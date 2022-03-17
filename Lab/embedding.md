# Embedding 계층

- word2vec의 CBOW 모델은 단순한 2층 신경망이어서, corpus의 어휘 수가 많아지면 계산량이 커져서 계산 시간이 오래 걸리게 된다.
- 이러한 word2vec의 단점을 극복하기 위해 Embedding 계층과, 네거티브 샘플링이라는 손실 함수를 도입하게 되었다.

### CBOW 모델 복습

- <img src="../images/fig 4-2.png">

  - 두 개의 단어를 맥락으로 사용해, 하나의 타깃을 추측한다.
  - 이때, 입력 측 가중치와의 행렬 곱으로 hidden layer가 계산되고, 다시 출력 측 가중치와의 행렬 곱으로 각 단어의 점수를 구한다.

  - 여기서 구한 점수는 확률이 아님에 주의하자.
  - 이후 구한 점수에 softmax 함수를 적용하여 각 단어의 출현 확률을 구한 후 정답 레이블과의 교차 엔트로피 오차를 구해 최종 손실을 구한다.

### 기본 CBOW 모델의 문제점

- 이처럼 CBOW 모델은 단순한 신경망이어서 어휘가 10만개, 100만개 늘어나면 은닉 층의 뉴런과의 중간 계산에서 많은 시간이 소요된다.
- 은닉층의 뉴런수도 증가함에 따라서 두 연산에서 병목 현상이 일어나는데
  - 첫 째, 입력층의 원핫벡터와 가중치 행렬의 곱 계산
  - 둘 째, 은닉층과 가중치 행렬의 곱과 softmax 계층의 계산
- 입력 어휘를 one-hot-vector로 다루기 때문에 어휘 수가 증가하면 벡터 크기도 증가한다. 이는 곧, 메모리의 점유율과 연관되어진다.

### Embedding 계층의 도입

- 기존 word2vec 구조에서는 입력의 어휘 들을 one-hot-vector로 바꾸었다.
- 그 후 그것을 MatMul 계층에 입력 후 MatMul 계층에서 행렬을 곱했다.

  - <img src="../images/fig 4-3.png">
  - 하지만 결국 MatMul 계층이 수행하는 일은 행렬의 특정 행을 추출하는 것 뿐이다.

  - 따라서, one-hot-vector로의 변환과 MatMul 계층의 행렬 곱 계산은 필요가 없는 절차였다.

- 그래서 가중치 매개변수로부터 단어 id에 해당하는 행을 추출하는 계층을 도입하는데 이를 embedding 계층이라고 부른다.

  - NLP에서 단어의 밀집벡터 표현을 word embedding 혹은 distributed representation(분산 표현)이라고 한다.
  - 통계 기반 기법으로 얻은 단어 벡터는 distributional representation
  - 추론 기반 기법으로 얻은 단어 벡터는 distributed representation이라고 한다.

    ```python
    # 입력층에 도입할 Embedding 계층 구현
    # Embedding 계층의 forward() 메서드와 backward() 메서드 구현
    class Embedding:
        def __init__(self, W):
            self.params = [W]
            self.grads = [np.zeros_like(W)]
            self.idx = None

        def forward(self, idx):
            W, = self.params
            self.idx = idx
            out = W[idx]
            return out

        def backward(self, dout):
            dW, = self.grads
            dW[...] = 0 # dW의 형상은 유지하되 원소만 0으로 뒤덮기

            for i, word_id in enumerate(self.idx):
                dW[word_id] += dout[i]

        return None
    ```

<hr />
<hr />
<hr />

# 네거티브 샘플링

- 입력층에서 은닉층으로 가는 계산에는 Embedding 계층을 도입하여 병목 현상을 해결할 수 있다.
- 남은 병목인 은닉층 이후의 행렬곱과 softmax 계층의 계산을 해결하려면 네거티브 샘플링 기법을 사용해야 한다.
- softmax 대신 네거티브 샘플링 기법을 도입하는 것이다.

- 은닉층 이후의 계산이 오래 걸리는 곳은 두 부분이다.
  - 은닉층의 뉴런과 가중치 행렬의 곱
  - Softmax 계층의 계산
- 이중 특히 Softmax의 계산은 매우 오래 걸리게 된다.(어휘 수 증가량에 따라)
- Softmax 계산 식을 보자.
  - $$y_k=\frac{\exp(s_k)}{\sum_{i=1}^k\exp(s_i)}$$
  - 다음 식처럼 어휘 수 k가 만약 100000개면 exp 계산을 100000번 수행해야 한다.

### 네거티브 샘플링의 핵심 아이디어

- 네거티브 샘플링은 기존의 다중 분류 문제를 이진 분류의 문제로 근사하는 것이 핵심 아이디어이다.

  - 이진 분류는 yes or no로 답할 수 있는 모델이 필요하다.
  - 이렇게 이진 분류로 문제를 풀어낸다면 출력층의 뉴런은 하나만 존재해도 된다. 하나의 어휘에 대한 점수만 출력하면 되기 때문이다.

  - <img src="../images/fig 4-7.png">
  - 그림과 같이 출력층의 뉴런은 한 개로도 충분하게 된다.
  - 따라서 은닉층과 출력 측의 가중치 행렬 곱은 'say'에 해당하는 열(단어 벡터)만을 추출하고, 그 추출된 벡터와 은닉층 뉴런과의 행렬곱만 수행하면 계산이 끝나게 된다.

- 이처럼 이진 분류를 통해 출력층에서 했던 다중 분류의 문제를 해결하여 출력층에선 하나의 어휘에만 주목하여 그 어휘의 점수만을 계산할 수 있다.
- 그 후 최종적으로 Sigmoid 함수를 활성화 함수로 적용하여 최종 확률을 구한다.

### 이진분류의 활성화 함수 및 손실 함수

- 다중 분류에서는 출력층에선 softmax 함수, 손실 함수로는 cross_entropy_error를 이용했다.
- 하지만 이진 분류에서는 출력층에서 Sigmoid 함수, 손실 함수로는 cross_entropy_error를 이용한다.

- Sigmoid 함수의 식을 다시 보자.

  - $$y=\frac{1}{1+\exp(-x)}$$
  - sigmoid 함수의 그래프는 S자 곡선 형태이며, 출력값을 확률로 해석할 수 있다.

  - sigmoid 함수를 통해 확률을 구한 후 교차 엔트로피 오차를 적용해 손실값을 구한다.
  - 교차 엔트로피 오차 수식은 다음과 같이 쓸 수 있다.
    - $$L=-(t\log y+(1-t)\log(1-y))$$
    - y는 sigmoid 함수의 출력, t는 정답 레이블이다.
  - <img src="../images/fig 4-10.png">

    - 역전파의 y-t 값은 신경망이 출력한 확률과 정답 레이블의 차이값이다.
    - 정답은 1이므로, y가 커질수록 오차는 줄어든다.
    - 오차가 크면 크게 학습하고, 작으면 작게 학습하게 된다.

- 이제 다중 분류에서 이진 분류로 바뀐 CBOW 모델의 구조를 보면 다음과 같다.

  - <img src="../images/fig 4-12.png">

- 하지만 단순히 이렇게만 학습하면, 정답 어휘만을 학습하게 된다.
- 다시 말해, 부정적인 예(오답)에 대해서는 어떠한 정보도 학습하지 못하게 된다는 것이다.
- 이를 해결하기 위해 정답에 대해서는 Sigmoid 계층의 출력을 1에 가깝게, 오답에 대해서는 Simoide 계층의 출력을 0에 가깝게 만들면 된다.
- 하지만 모든 오답에 대해서 학습하면, 다중 분류에서와 같은 병목 현상이 일어날 수 있기 대문에 근사적인 해법으로 오답은 예를 몇 개 선택하게 된다.
- 결국 적은 수의 오답을 샘플링해 사용하는데, 이를 네거티브 샘플링 기법이라고 한다.

  - <img src="../images/fig 4-16.png">

  - 결과적으로 네거티브 샘플링 기법은 정답을 타겟으로 한 경우의 손실을 구함과 동시에, 오답의 예를 몇 개 선별하여 그 오답에 대해서도 손실을 구한다.

  - 그 후 각 각의 데이터의 손실을 더한 값을 최종 손실로 한다.

### 그렇다면 네거티브 샘플링에서의 오답은 어떤식으로 선별할까?

- 랜덤으로 샘플링 하는 것 보다는 corpus에서 빈도수가 많은 단어는 많이 추출하고, 빈도수가 적은 단어는 적게 추출하는 확률분포 방법을 사용하는것이 좋다.

  - <img src="../images/fig 4-18.png">

```python
    # 확률분포에 따른 네거티브 샘플링하는 예제
    print(np.random.choice(10))
    words = ['you', 'say', 'goodbye', 'i', 'hello', '.']
    print(np.random.choice(words))
    # 무작위 5개만 샘플링
    print(np.random.choice(words, size=5))
    # 무작위 5개 샘플링 중복 제거
    print(np.random.choice(words, size=5, replace=False))
    # 확률분포를 설정 후 샘플링
    p = [0.5, 0.1, 0.05, 0.2, 0.05, 0.1]
    np.random.choice(words, p=p)
```

- np.random.choice 메서드를 사용하면 샘플링 용도로 사용할 수 있고, replace를 지정하면 중복을 제거할 수 있다. 또, 인수 p를 통해 확률분포를 설정할 수 있다.

- 중요한 점은 word2vec의 네거티브 샘플링에서는 확률분포에 0.75를 곱하는 것을 권고하고 있다.
- 식으로 확인하면 다음과 같다.
  - $$P`(w_i)=\frac{P(w_i)^{0.75}}{\sum_j^nP(w_j)^{0.75}}$$
    - 여기서 $$P(w_i)$$는 i번째 단어의 확률을 뜻한다.
    - 이렇게 0.75를 곱하는 이유는 출현 확률이 희박한 단어의 손실을 막기 위함이다.
  - 일종의 구제..? 조치이다.

### word2vec의 단어의 분산 표현

- word2vec의 단어의 분산 표현은 단어를 고정 길이 벡터로 변환해준다는 장점이 있다.
- 또한, 문장도 단어의 분산 표현을 사용해 고정 길이 벡터로 변환할 수 있다.
- 이처럼 단어의 분산 표현을 통해 자연어를 벡터로 변환하는 것이 중요한 이유는 머신러닝 기법을 적용할 수 있기 때문이다.
  - 예를 들면 "질문"과 같은 일반적인 자연어를 단어 벡터화를 통해 고정 길이 벡터로 변환한다면, 이를 머신러닝 시스템의 입력으로 이용하여 학습시킬 수 있다.

# Pytorch의 Embedding

- pytorch에선 embedding을 쉽게 할 수 있는 api 함수를 제공한다.
- 주요 Parameter

  - num_embeddings: 임베딩 벡터를 생성할 전체 범주 개수
  - embedding_dim: 임베딩 벡터의 차원
  - padding_idx: 지정된 인덱스에 대한 임베딩 벡터에 대해서는 학습시 parameter update가 이루어지지 않는다.
  - max_norm: 특정 실수가 주어지고 임베딩 벡터의 norm이 이 값보다 크다면 norm이 이 값에 맞춰지도록 정규화된다.
  - norm_type: p-norm의 p값으로 default는 2다.

  ```python
  # 차원이 3인 임베딩 벡터가 10개 생성
  embedding = nn.Embedding(10, 3)
  embedding.weight
  ```

  ```python
  import torch
  from torch import nn
  n, d, m = 3, 5, 7
  embedding = nn.Embedding(n, d, max_norm=True)
  W = torch.randn((m,d), requires_grad=True)
  idx = torch.tensor([1, 2])
  a = embedding.weight.clone() @W.t()
  b = embedding(idx) @ W.t()
  out = (a.unsqueeze(0) + b.unsqueeze(1))
  loss = out.sigmoid().prod()
  loss.backward()

  ```

  주의할 점은 만약 max_norm 인자에 값이 주어진다면 Embedding 객체의 forward 메서드에 의해 임베딩 파라미터가 주어진 max_norm 크기에 맞게 in-place 방식으로 정규화 된다는 것이다. 기울기 계산을 위해서는 in-place 방식으로 값이 변하면 안되므로 forward 메서드를 호출하기 전에 임베딩 파라미터의 기울기를 계산하기 위해서는 파라미터를 clone 메서드로 복사해서 연산하여야 한다.

```python
from torch import LongTensor, norm
from torch.nn import Embedding
embedding = nn.Embedding(10, 3)
sentences = LongTensor([[1,2,4,5],[4,3,2,9]])
embedding(sentences)
# tensor([[[ 1.0141, -2.1953,  0.3030],
#          [-0.8147,  2.2799,  0.7509],
#          [-0.6491, -0.2387,  0.8809],
#          [ 0.9722,  0.6464, -0.5913]],

#         [[-0.6491, -0.2387,  0.8809],
#          [-0.3678, -1.7773, -1.3405],
#          [-0.8147,  2.2799,  0.7509],
#          [ 0.6034, -0.2334, -0.4138]]], grad_fn=<EmbeddingBackward0>)
```

- 임베딩 파라미터를 선언 후 forward 메서드를 수행하면 (입력차원, 임베딩차원) 크기를 가진 텐서가 출력된다. 이때 임베딩 벡터를 추출할 범주의 인덱스이므로 무조건 정수 타입이 들어가야 한다.

```python
sentences = LongTensor([[1,2,4,5], [4,3,2,9]])
embedding = Embedding(num_embeddings=10, embedding_dim=100, max_norm=1)
for sentence in embedding(sentences):
    for word in sentence:
        print(norm(word))

# tensor(1.0000, grad_fn=<CopyBackwards>)
# tensor(1.0000, grad_fn=<CopyBackwards>)
# tensor(1.0000, grad_fn=<CopyBackwards>)
# tensor(1.0000, grad_fn=<CopyBackwards>)
# tensor(1.0000, grad_fn=<CopyBackwards>)
# tensor(1.0000, grad_fn=<CopyBackwards>)
# tensor(1.0000, grad_fn=<CopyBackwards>)
# tensor(1.0000, grad_fn=<CopyBackwards>)
```

- 이처럼 max_norm 인자를 지정하면 forward 메서드가 in-place 방식으로 임베딩 파라미터를 수정하고 norm을 이용해 크기를 출력하면 max_norm 인자에 맞게 정규화 된다.
