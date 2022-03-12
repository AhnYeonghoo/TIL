# 추론 기반 기법

### 통계 기반 기법의 문제점

- 통계 기반 기법에서는 단어의 동시발생 행렬을 만든 후 SVD를 적용하여, 밀집벡터를 얻는 방식으로 학습한다. 하지만 대규모 corpus를 처리할 때는 이 방식에는 한계가 있다.
  - SVD를 $$n*n$$ 행렬에 적용하는 비용은 $$O(n^3)$$이다.
- 따라서, 추론 기반 기법에서는 미니배치 학습을 사용하는 것이 일반적이다.
- 신경망의 학습과 같이 PPMI와 같이 단 1회에 처리하는 것이 아닌, 한 번에 미니배치만큼의 학습을 반복하며 가중치를 갱신해나간다.
  <img src="../images/fig 3-1.png">
  - 이처럼 미니배치 단위로 순차적으로 학습시키면, corpus가 많아도 큰 문제를 작게 나눠 학습시킬 수 있다.
  - 추가적으로 여러 머신과 GPU를 이용해 병렬 계산도 가능하다.

<hr />
<hr />
<hr />

# 추론 기반 기법

- 추론 기반 기법도 기반적으로 분포 가설에 기초하여 추론한다.
- 다만, 추론 기반 기법은 여러 맥락들 사이에서 "?"가 주어졌을 때 어떤 단어가 들어있는 지를 추론하는 방법을 사용한다.
  <img src="../images/fig 3-2.png">
  맥락이라는 인풋이 들어오면 학습 모델은 각 단어의 출현을 확률로써 표현한다.(eg: 'you'라는 단어는 0.7.. 등)
- 추론 기반 기법과 같은 신경망 학습에서도 단어를 단어 그대로 표현하지 않고, 고정 길이의 벡터로 변환하여 분류하기 쉽게 만드는데 보통, one-hot vector로 변환한다.
- 원-핫 벡터는 벡터의 원소 중 하나만 1이고 나머지는 0인 벡터이다.
- 이렇게 원-핫 벡터로 변환하면, 신경망의 인풋은 뉴런의 수를 고정할 수 있게 된다.
  <img src="../images/fig 3-5.png" height="150" width='400'>
  - 입력층의 뉴런은 총 7ㄱ9이고, 7개의 뉴런은 차례로 7개의 단어들에 대응한다. 덕분에, 신경망을 구성하는 각 layer들은 vector로 처리할 수 있게 된다.
    <img src="../images/fig 3-6.png" height='150'>

<hr />
<hr />
<hr />

# word2vec

- 추론 기반 기법에서 사용하는 신경망은 word2vec이며, word2vec에서 제안하는 모델은 CBOW(continuous bag-of-words)와, skip-gram model 두가지이다.

### CBOW(continuous bag-of-words)

- CBOW 모델은 맥락으로부터 타겟을 추측하는 용도의 신경망이다. 즉, `hi my ?? is ddd` 라는 문장이 있을 때, 주변 단어를 보고 ??라는 타겟을 추측한다. 이러한 맥락을 원핫벡터로 변환하여 CBOW 모델이 학습할 수 있도록 만든다.
  <img src="../images/fig 3-9.png" height="200" width="400">
  CBOW 모델의 간단한 신경망 구조이다.
  인풋은 2개가 있고, 잇풋 2개에서 히든레이어로의 변환은 완전연결계층이 처리한다. 또, 히든레이어에서 아웃풋으로의 변환은 또 다른 완전연결계층이 처리한다.

- 위 사진에선 인풋이 2개인데 이 때 완전연결계층에 의해 첫 번째 인풋은 $$h_1$$으로 변환되고, 두 번째 인풋은 $$h_2$$로 변환되고, 결과적으로 히든레이어는 $$\frac{1}{2}(h_1+h_2)$$가 된다.

- 여기서 아웃풋 뉴런은 각 단어의 score에 해당하며, 값이 높을수록 대응 단어의 출현 확률도 높아진다.
- 값이란 것은 아직 확률로써 역할은 하지 못한다는 뜻이고, 확률을 얻기 위해서 softmax 함수를 적용한다.

        은닉층의 뉴런 수를 입력층의 뉴런 수보다 적게하는 것이 중요하다. 이렇게 해야 은닉층에는 단어 예측에 필요한 정보를 간결하게 담을 수 있고, 결과적으로 밀집벡터로 표현된 결과를 얻을 수 있다. 이대, 은닉층의 정보는 인코됭 되어 있기 때문에 알아볼 수 없으며, 우리가 볼 수 있는 결과로 얻는 과정을 디코딩이라고 한다.

    <img src="../images/fig 3-11.png" height='200' width='500'>
    CBOW 모델을 계층관점에서 보면 가장 앞 단에는 2개의 MatMul 계층이 존재하며, 이 두계층의 출력이 더해지고, 0.5를 곱해줌으로써 평균을 구하게 된다. 
    
    $$\frac{1}{2}(h_1+h_2)$$
    마지막으로 은닉층의 뉴런에 또 다른 MatMul 계층이 적용된 후 점수가 출력된다.

### CBOW 모델의 학습

<img src="../images/fig 3-12.png" height="200" width="400">

- CBOW 모델의 학습 과정은 간단하다.
  - 1. MatMul 계층으로 인풋을 받는다.
  - 2. 인풋들을 모두 더한 후 평균을 구한다.
  - 3. 히든레이어로부터 최종 출력을 얻는다.
  - 4. 출력에 softmax 함수를 적용해 확률로 만든다.
  - 5. cross_entropy_error를 통해 실제 정답 레이블과 예측 확률의 값을 손실로 이용해 학습을 진행한다.
- softmax 함수와 교차 엔트로피 오차를 이용한 최종 학습 모델은 다음과 같다.

  - <img src="../images/fig 3-13.png" height='200' width='400'>

- 그런데 word2vec에는 가중치가 두가지가 존재한다. 하나는 인풋의 완전연결계층의 가중치$$W_{in}$$와 아웃풋 측 완전연결계층의 가중치 $$W_{out}$$이다. 그리고 입력 측 가중치의 각 행이 각 단어의 분산 표현에 해당한다.
- 출력 측 가중치에도 단어의 의미가 인코딩된 벡터가 저장되고 있다고 생각할 수 있다.

<img src="../images/fig 3-15.png" height='200' width='400'>

다만, 'Hakan Inan' 저의 "Tying Word Vectors and Word Classifiers: A Loss Framework for Language Modeling"라는 논문에 따르면 $$W_{in}$$을 학습에 사용했을 때 효과가 더 좋다고 실험 결과가 나와있었다.

<hr />

## 맥락과 타겟

- word2vec에서의 인풋은 **맥락** 이다. 그리고 정답 레이블은 맥락에 둘러쌓인 중앙의 단어, 즉 **타겟** 이다. 즉, 학습의 목적은 **맥락** 이 주어졌을 때 모델이 **타겟** 의 출현 확률을 높이는 것이다.

- 따라서, 맥락(context)과 타겟(target)을 만드는 과정이 필요하다.

  - <img src="../images/fig 3-16.png">

  - 우선, 맥락과 타겟을 만들기 전에 corpus 텍스트를 단어 ID로 만드는 과정이 필요하다.
  - text가 주어졌을 때 단어id 만드는 소스코드

  ```python
  def preprocess(text):
    text = text.lower()
    text = text.replace('.', ' .')
    words = text.split(' ')

    word_to_id = {}
    id_to_word = {}
    for word in words:
        if word not in word_to_id:
            new_id = len(word_to_id)
            word_to_id[word] = new_id
            id_to_word[new_id] = word

    corpus = np.array([word_to_id[w] for w in words])

    return corpus, word_to_id, id_to_word
  ```

  - 그 후에 corpus를 이용하여 맥락과 타겟을 생성하는 함수를 통해 모델 학습에 필요한 맥락, 타겟을 생성한다.
  - 맥락 및 타겟을 생성하는 소스코드

  ```python
    def create_contexts_target(corpus, window_size=1):

    target = corpus[window_size:-window_size]
    contexts = []

    for idx in range(window_size, len(corpus)-window_size):
        cs = []
        for t in range(-window_size, window_size + 1):
            if t == 0:
                continue
            cs.append(corpus[idx + t])
        contexts.append(cs)

    return np.array(contexts), np.array(target)

  ```

  - 맥락과 타겟의 원소들 또한 일반적인 단어 ID이므로 원핫벡터로 변환하는 과정이 필요하다.
  - 원핫벡터로 변환하는 소스코드

  ```python
  def convert_one_hot(corpus, vocab_size):

    N = corpus.shape[0]

    if corpus.ndim == 1:
        one_hot = np.zeros((N, vocab_size), dtype=np.int32)
        for idx, word_id in enumerate(corpus):
            one_hot[idx, word_id] = 1

    elif corpus.ndim == 2:
        C = corpus.shape[1]
        one_hot = np.zeros((N, C, vocab_size), dtype=np.int32)
        for idx_0, word_ids in enumerate(corpus):
            for idx_1, word_id in enumerate(word_ids):
                one_hot[idx_0, idx_1, word_id] = 1

    return one_hot
  ```

- 전체적인 전처리 과정을 보면 다음과 같다.

  - <img src="../images/fig 3-18.png">

- 최종적인 CBOW 신경망 학습 모델 구현 소스코드

```python
class SimpleCBOW:
    def __init__(self, vocab_size, hidden_size):
        V, H = vocab_size, hidden_size

        # 가중치 초기화
        W_in = 0.01 * np.random.randn(V, H).astype('f')
        W_out = 0.01 * np.random.randn(H, V).astype('f')

        # 계층 생성
        self.in_layer0 = MatMul(W_in)
        self.in_layer1 = MatMul(W_in)
        self.out_layer = MatMul(W_out)
        self.loss_layer = SoftmaxWithLoss()

        # 모든 가중치와 기울기를 리스트화 한다.
        layers = [self.in_layer0, self.in_layer1, self.out_layer]
        self.params, self.grads = [], []
        for layer in layers:
            self.params += layer.params
            self.grads += layer.grads

        # 인스턴스 변수에 단어의 분산 표현을 저장
        self.word_vecs = W_in

    def forward(self, contexts, target):
        h0 = self.in_layer0.forward(contexts[:,0])
        h1 = self.in_layer1.forward(contexts[:,1])
        h = (h0+h1) * 0.5
        score = self.out_layer.forward(h)
        loss = self.loss_layer.forward(score, target)
        return loss

    def backward(self, dout=1):
        ds = self.loss_layer.backward(dout)
        da = self.out_layer.backward(ds)
        da *= 0.5
        self.in_layer1.backward(da)
        self.in_layer0.backward(da)
        return None
```

여기서 softmax와 cross_entropy_error, MatMul 함수는 모듈로써 가져왔다고 가정했다.

- CBOW 모델의 역전파 과정
  <img src="../images/fig 3-20.png">

  - 기존과 같이, 역전파는 미분의 연쇄법칙으로 설명이 가능하고, **X의 역전파는 순전파 시의 인풋을 서로 바꾸어 기울기에 곱하고 +의 역전파는 기울기를 그대로 통과시킨다.(정확히는 곱하기 1 해준다)**

  - 실제 학습하는 코드를 구현해보면 다음과 같다.

  ```python
  window_size = 1
  hidden_size = 5
  batch_size = 3
  max_epoch = 1000
  text = 'you say goodbye and i say hello. '
  corpus, word_to_id, id_to_word = preprocess(text)

  vocab_size = len(word_to_id)
  contexts, target = create_contexts_target(corpus, window_size)
  target = convert_one_hot(target, vocab_size)
  contexts = convert_one_hot(contexts, vocab_size)

  model = CBOW(vocab_size, hidden_size)
  optimizer = Adam() # 매개변수 갱신은 여러가지가 있지만 Adam으로 선정
  trainer = Trainer(model, optimizer) # 학습 모델과 최적화 모델을 넣어주면 훈련시켜주는 객체가 있다고 가정

  trainer.fit(contexts, target, max_epoch, batch_size)
  trainer.plot()
  ```

- 학습 결과
  - <img src="../images/fig 3-21.png">
- 손실이 줄어들며 학습이 제대로 진행되는 것을 알 수 있다.

<hr />
<hr />
<hr />

# CBOW 모델과 확률

- 동시확률
  - $$P(A, B)$$
    이라고 쓰고, 사건 A와 B가 동시에 일어날 확률이다.
- 사후확률
  - $$P(A|B)$$
    B가 주어졌을 때 A라는 사건이 일어날 확률이다.
- CBOW의 확률

  - CBOW 모델은 맥락을 주면 타겟 단어가 나타날 확률을 추측하는 모델이다.
    여기서 corpus를 $$w_1, w_2, \dots, w_T$$처럼 단어 시퀀스로 표기하고, 윈도우 크기가 1인 맥락이라고 가정한다면 그림과 같이 될 것이다.
  - <img src="../images/fig 3-22.png">
  - 그럼 맥락 $$w_{t-1}$$과 $$w_{t+1}$$이 주어졌을 때 타겟이 $$w_t$$가 될 확률은 수식으로 쓰면 다음과 같이 될 것이다.

    - $$P(w_t|w_{t-1},w_{t+1})$$
    - 위 설명처럼 해당 수식은 $$w_{t-1}$$과 $$w_{t+1}$$이 주어졌을 때 $$w_t$$가 나타날 확률을 뜻한다.

    - 이 수식을 이용하면 CBOW 모델의 손실 함수도 표현할 수 있다.

  - 우선, 교차 엔트로피 오차 수식을 다시 써보면

    - $$L=-\sum_k t_k logy_k$$
      가 된다.
      이때, $$y_k$$는 **k번째에 해당하는 사건이 일어날 확률을 뜻한다.**
    - 그리고 $$t_k$$는 정답 레이블이고, 원핫벡터로 표현된다.
    - 여기서 문제의 정답은 **$$w_t$$가 발생**
      이므로 $$w_t$$에 해당하는 원소만 1이고 나머지는 0이 된다.
    - 이를 이용하여 다음 식을 유도할 수 있게 된다.

    - $$L=-\log P(w_t|w_{t_1},w{t+1})$$
    - 식에서 알 수 있듯, CBOW 손실함수는 단순히 맥락이 주어졌을 때 타겟이 될 확률에 log를 취한 후 마이너스를 붙인 것과 같다.

  - 이를 **음의 로그 가능도(negative log likelihood)** 라고도 한다.
  - 하지만 이는 샘플 데이터 하나에만 국한하는 손실 함수며, 이를 corpus 데이터 전체로 확장하면 다음과 같이 유도할 수 있다.

  $$L=-\frac{1}{T}\sum_{t=1}^T\log P(w_t|w_{t-1},w_{t+1})$$
  결국 신경망 학습이 늘 그렇듯 CBOW 모델 또한 하는 일은 이 손실 함수의 값을 가능한 한 작게 만드는 것이다. 이때의 가중치 매개변수가 결국 얻고자 하는 단어의 분산 표현인 것이다.

<hr />
<hr />
<hr />

# SKIP-GRAM 모델

- word2vec의 또 다른 모델이다.
- skip-gram 모델은 CBOW 모델과 정반대의 모델이다.
- CBOW 모델은 맥락으로부터 타겟을 추측했다면, skip-gram 모델은 타겟을 통해 맥락을 추측한다.

  - <img src="../images/fig 3-23.png">

  - <img src="../images/fig 3-24.png">

  - skip-model은 입력층은 하나이며, 출력층은 추측하고자 하는 맥락의 수만큼 존재한다.
    따라서, 각 출력층에서는 개별적으로 손실을 구하고, 이 개별 손실들을 모두 합 한 값을 최종 손실로 한다.

### skip-model의 확률적 표현

$$P(w_{t-1},w_{t+1}|w_t)$$
$$w_t$$
가 주어졌을 때 $$w_{t-1},w_{t+1}$$가 동시에 일어날 확률이다.

- skip-model에서는 조건부 독립이라는 가정을 통해 해당 식을 다음과 같이 분해한다.

  - $$P(w_{t-1},w_{t+1}|w_t)=P(w_{t-1}|w_t)P(w_{t+1}|w_t)$$
  - 이어서 교차 엔트로피 오차에 적용하여 skip-model의 손실함수를 유도할 수 있다.
  - $$L=-\log P(w_{t-1},w_{t+1}|w_t)$$
    $$=-\log P(w_{t-1}|w_t)P(w_{t+1}|w_t)$$
    $$=-(\log P(w_{t-1}|w_t)+\log P(w_{t+1}|w_t)$$
  - 이 또한 샘플 데이터 하나에만 국한한 손실함수이므로 corpus 데이터 전체로 확장하면 다음과 같이 skip-gram 모델의 손실함수가 정의된다.
  - $$L=-\frac{1}{T}\sum_{t=1}^T(\log P(w_{t-1}|w_t)+\log P(w_{t+1}|w_t)$$

- skip-gram 모델은 맥락의 수만큼 추측하기 때문에 그 손실 함수는 각 맥락에서 구한 손실의 총합이어야 한다.
- 반면 CBOW 모델은 타겟 하나의 손실만을 구한다.
- 단어 분산 표현의 정밀도 면에서는 skip-gram 모델이 더 결과가 좋은 경우가 많아서 일반적으로 skip-gram 모델이 더 선호되는 경향이 있다고 한다.
- 특히 저빈도 단어나 유추 문제의 성능 면에서는 skip-gram이 더 뛰어나다.
- 반면 학습 속도 자체만 보면 CBOW 모델이 더 빠르다.
- 그 이유는 skip-gram 모델은 맥락의 수만큼 손실을 구해야 하기 때문에 그만큼 계산비용이 들기 때문이다.

- skip-gram의 소스코드

```python
class SkipGram:
    def __init__(self, vocab_size, hidden_size):
        V, H = vocab_size, hidden_size

        # 가중치 초기화
        W_in = 0.01 * np.random.randn(V, H).astype('f')
        W_out = 0.01 * np.random.randn(H, V).astype('f')

        # 계층 생성
        self.in_layer = MatMul(W_in)
        self.out_layer = MatMul(W_out)
        self.loss_layer1 = SoftmaxWithLoss()
        self.loss_layer2 = SoftmaxWithLoss()

        # 모든 가중치와 기울기를 리스트에 모은다.
        layers = [self.in_layer, self.out_layer]
        self.params, self.grads = [], []
        for layer in layers:
            self.params += layer.params
            self.grads += layer.grads

        # 인스턴스 변수에 단어의 분산 표현을 저장한다.
        self.word_vecs = W_in

    def forward(self, contexts, target):
        h = self.in_layer.forward(target)
        s = self.out_layer.forward(h)
        l1 = self.loss_layer1.forward(s, contexts[:, 0])
        l2 = self.loss_layer2.forward(s, contexts[:, 1])
        loss = l1 + l2
        return loss

    def backward(self, dout=1):
        dl1 = self.loss_layer1.backward(dout)
        dl2 = self.loss_layer2.backward(dout)
        ds = dl1 + dl2
        dh = self.out_layer.backward(ds)
        self.in_layer.backward(dh)
        return None
```

- word2vec 이후 추론 기반 기법과 통계 기반 기법을 융합한 GloVe 기법이 등장했다고 하는데, 기본 아이디어는 corpus 전체의 통계 정보를 손실 함수에 도입해 미니배치 학습을 하는 것이라고 한다.
- GloVe에 대해서도 한 번 들여다봐야겠다.
- 추가로 pytorch에서는 지금까지 학습한 모델을 어떻게 사용하는 지 공부를 시작해야겠다.. 너무 밑바닥만 본 것 같다.
