# 시소러스(thesaurus)

유의어 사전으로 NLP에서 이용되는 시소러스는 단어 사이의 상위 및 하위 혹은 전체와 부분 등 세세한 관계까지 정의해두는 경우가 많다.

- <img src="../images/fig 2-2.png">
- 이렇게 단어들간 네트워크를 이용하여 컴퓨터에게 단어간 관계를 학습시킬 수도 있다.

### WordNet

자연어처리에서 가장 유명한 시소러스이다. WordNet을 이용하면 유의어를 얻거나, 단어 네트워크를 이용할 수 있다.

```python
# WordNet을 이용하여 동의어 얻고, 단어간 유사도 분석
import nltk
from nltk.corpus import wordnet
nltk.download('wordnet')
nltk.download('omw-1.4')
wordnet.synsets('car') #[Synset('car.n.01'),
                       #Synset('car.n.02'),
                       # Synset('car.n.03'),
                       # Synset('car.n.04'),
                       # Synset('cable_car.n.01')]
car = wordnet.synset('car.n.01')
car.definition() #'a motor vehicle with four wheels; usually propelled by an internal combustion engine'
car.lemma_names() #['car', 'auto', 'automobile', 'machine', 'motorcar']
car.hypernym_paths() # 추상적인 내용부터 내려가며 점점 구체화된 단어의 의미로 나타남
# 단어간 의미 유사도
car = wordnet.synset('car.n.01') # 자동차
novel = wordnet.synset('novel.n.01') # 소설
dog = wordnet.synset('dog.n.01') # 개
motorcycle = wordnet.synset('motorcycle.n.01')
print(car.path_similarity(novel)) # 0.0555555555555
print(car.path_similarity(dog)) # 0.0769230769
car.path_similarity(motorcycle) # 0.33333333333333333
# 1에 가까울 수록 유사도 높다.

```

- 시소러스의 문제점
  - 신조어의 등장과 잊혀지는 옛말들을 일일히 끊임없이 사람이 직접 갱신하기 어려움
  - 시소러스를 구축하는데 드는 인적 비용이 매우 큼
  - 단어의 미묘한 차이를 표현하기 힘들다.(이 또한 수작접을 통해 해야함)
- 이러한 문제를 해결하기 위해 통계 기반 기법이 등장하였다.

# 통계 기반 기법

- 말뭉치(corpus): 자연어 처리를 위해 수집된 텍스트 데이터를 corpus라고 한다.
- corpus를 preprocessing하는 코드 구현

  ```python
  # corpus proprecessing을 위한 함수 구현
  def preprocess(text):
  text = text.lower() # 모두 소문자로 변환
  text = text.replace('.', ' .') # 마침표로 구분하되, 마지막 문장을 고려하여 공백+'.'을 추가, 이는 정규표현식을 이용하여 더 간단하게 가능
  words = text.split(' ') # 분리한 문장을 단어로 리스트화 한다.
  word_to_id = {} # key값으로 단어를, value로 순서(숫자)를 부여
  id_to_word = {} # word_to_id와 반대
  for word in words:
     if word not in word_to_id: # 0부터 시작
         new_id = len(word_to_id)
         word_to_id[word] = new_id # 첫 번째 단어부터 0,1,2... 순서 부여
         id_to_word[new_id] = word # word_to_id와 반대로 0,1,2...에 단어들을 순서대로 value로 넣는다

  corpus = np.array([word_to_id[w] for w in words]) # 단어 목록을 넘파이 배열로 변환
  return corpus, word_to_id, id_to_word
  text = "Your say goodbye and I say hello."
  corpus, word_to_id, id_to_word = preprocess(text)
  print(f"corpus: {corpus}") # corpus: [0 1 2 3 4 1 5 6]
  print(f"word_to_id: {word_to_id}") # word_to_id: {'your': 0, 'say': 1, 'goodbye': 2, 'and': 3, 'i': 4, 'hello': 5, '.': 6}
  print(f"id_to_word: {id_to_word}") # id_to_word: {0: 'your', 1: 'say', 2: 'goodbye', 3: 'and', 4: 'i', 5: 'hello', 6: '.'}
  ```

<hr />
<hr />

# 분포 가설(distributional hypothesis)

- 단어의 의미는 주변 단어에 의해 형성된다라는 가설이다.
- 분포 가설에서 의미하는 바는 단어 자체는 큰 의미가 없고, 해당 단어가 사용된 맥락(context)이 의미를 형성한다는 것이다.
- 좌우 동수인 윈도우 크기가 2인 맥락의 예시
  - <img src="../images/fig 2-3.png">

## 동시발생 행렬

- 분포 가설에 기초해 단어를 vector로 나타내는 방법은, 주변 단어를 세어보는 방법이 간단하다.

  - 단어를 통계내고, 각 단어들의 맥락에 해당하는 단어의 빈도를 세어보는 것이다.
  - <img src="../images/fig 2-4.png">
  - <img src="../images/fig 2-5.png">
  - 이를 vector로 표현하면 [0, 1, 0, 0, 0, 0, 0, 0]으로 표현할 수 있다.
  - 계속해서 say에 대해서도 goodbye에 대해서도 맥락에 해당하는 단어의 빈도를 통계낸다.

  - <img src="../images/fig 2-7.png">
  - 이처럼 모두 센 후, 동시발생하는 단어를 표로써 정리한다.
  - 이 표에서는 각 행은 해당 단어를 표현한 vector가 된다. 이 표가 행렬의 형태를 띤다는 의미로 동시발생 행렬이라고 한다(co-occurrence matrix)

        동시발생 행렬을 만드는 함수를 코드로 구현하면 다음과 같다.

        ```python
        # 동시발생 행렬 자동화 함수
        def create_co_matrix(corpus, vocab_size, window_size=1):
        corpus_size = len(corpus)
        co_matrix = np.zeros((vocab_size, vocab_size), dtype=np.int32) # matrix 초기화

        for idx, word_id in enumerate(corpus): # enumerate 내장함수를 이용해 index와 value를 나눈다.
            for i in range(1, window_size+1):  # 모든 단어 각각에 대해 윈도우에 포함된 주변 단어 세기 반복
                left_idx = idx - i
                right_idx = idx + i

                if left_idx >= 0: # corpus의 왼쪽 끝 경계를 벗어나지 않게 처리
                    left_word_id = corpus[left_idx]
                    co_matrix[word_id, left_word_id] += 1

                if right_idx < corpus_size: # corpus의 오른쪽 끝 경계를 벗어나지 않게 처리
                    right_word_id = corpus[right_idx]
                    co_matrix[word_id, right_word_id] += 1

        return co_matrix
        ```

    <hr />
    <hr />

# 벡터 간 유사도

- 벡터 사이의 유사도를 측정하는 방법

  - 벡터의 내적, 유클리드 거리 구하기, 코사인 유사도 구하기 등.
  - 하지만 단어 벡터의 유사도를 나타낼 때는 코사인 유사도를 자주 이용한다.

    - $$x=(x_1,x_2,x_3,\dots, x_n)$$
      과 $$y=(y_1,y_2,y_3,\dots,y_n)$$
      이 있다면, 코사인 유사도는 다음 식으로 정의된다.

    - $$similarity(x,y)=\frac{X*Y}{||X||||Y||}=\frac{x_1y_1+\dots+x_n y_n}{\sqrt{x_1^2+\dots+x_n^2}{\sqrt{y_1^2+\dots+y_n^2}}}$$

    - 분자에는 벡터의 내적, 분모에는 각 벡터의 노름이 등장한다.
      노름이란 벡터의 크기를 나타낸 것이다. 해당 식의 핵심은 벡터를 정규화하고 내적을 구한다는 것에 있다.
    - 코사인 유사도는 '두 벡터가 가리키는 방향이 얼마나 비슷한가'라는 의미가 있다. 벡터의 방향이 완전히 같다면 유사도는 1이, 완전히 반대라면 -1이 됩니다.
    - 이를 통해 단어간의 유사도를 직관적으로 알 수 있다.

- 코사인 유사도를 코드로 구현한 것

```python
def cos_similarity(x, y, eps=1e-8):
    nx = x / np.sqrt(np.sum(x**2)+eps) # x를 정규화
    ny = y / np.sqrt(np.sum(y**2)+eps) # y를 정규화
    return np.dot(nx,ny) # 벡터의 내적을 반환
    # 분모에 0이 들어오면 divide by zero error가 발생함으로 예외처리
```

# 상호정보량

- 동시발생 행렬은 두 단어가 동시에 발생한 횟수를 나타낸다.
- 하지만 발생 횟수라는 것은 그리 좋은 feature가 되지 못한다.
  - 예를 들어, the와 car가 동시발생한다고 했을 때 the car라는 문구가 자주 보인다고 가정하면, 두 단어의 동시발생 횟수는 아주 많을 것이다.
  - 한편, car와 drive는 유사도가 깊은 단어이다.
  - 하지만 단순히 등장 횟수만 고려한다면 car는 drive보다 the와의 관련성이 강하다고 나올 것이다.
  - 단순히 the가 고빈도 단어라서 그런 결과를 얻게 되는 것이다.

### 점별 상호정보량(Pointwise Mutual Information[PMI])

이 문제를 해결하기 위해 PMI라는 척도를 사용한다.

- PMI는 확률 변수 x와 y에 대해 다음 식으로 정의된다.

  - $$PMI(x,y)=\log_2\frac{P(x,y)}{P(x)P(y)}$$
    해당 식에서 P(x)는 x가 일어날 확률을, P(y)는 y가 일어날 확률을, P(x,y)는 x와 y가 동시에 일어날 확률을 뜻한다. 이 PMI값이 높을수록 관련성이 높다는 의미이다.
    즉, P(x)는 단어 x가 corpus에서 등장할 확률을 의미한다.

- 그럼 동시발생 행렬을 이용하여 해당 식을 다시 정리하면 다음과 같다.

  - $$PMI(x,y)=\log_2\frac{P(x,y)}{P(x)P(y)}=\log_2\frac{\frac{C(x,y)}{N}}{\frac{C(x)C(y)}{N}}=\log_2\frac{C(x,y)*N}{C(x)C(y)}$$

C는 동시발생 행렬, C(x,y)는 단어 x와 y가 동시발생하는 횟수, C(x),C(y)는 각각 단어 x와 y의 등장횟수이다. N은 corpus에 포함된 단어 수이다.

- 예를 들어 corpus는 10,000이고, "the"와 "car"와 "drive"가 각 1,000번, 20번, 10번 등장했다고 가정하고 "the"와 "car"의 동시발생 수는 10, "car"와 "drive"의 동시발생 수는 5라고 가정하면 PMI 계산 결과는 다음과 같다.

  - $$PMI("the","car")=\log_2\frac{10*10000}{1000*20}\approx2.32$$
  - $$PMI("car","drive")=\log_2\frac{5*10000}{20*10}\approx7.97$$
  - 이 처럼 PMI를 이용하면 car는 the보다 drive와의 관련성이 깊게 나온다.

- 실제로는 동시발생 횟수가 0일 때 $$\log_20=-\infty$$
  가 되므로 실제로 구현할 때는 **양의 상호정보량(Positive PMI[PPMI])** 을 사용한다.
  - $$PPMI(x,y)=max(0,PMI(x,y))$$

해당 식에서는 PMI가 0일 때 0으로 취급한다.

- 코드로 구현하면 다음과 같다.

```python
def ppmi(C, verbose=False, eps=1e-8):
    M = np.zeros_like(C, dtype=np.float32)
    N = np.sum(C)
    S = np.sum(C, axis=0)
    total = C.shape[0] * C.shape[1]
    cnt = 0

    for i in range(C.shape[0]):
        for j in range(C.shape[1]):
            pmi = np.log2(C[i, j] * N / (S[j]*S[i]) + eps)
            M[i,j] = max(0, pmi)

            if verbose:
                cnt += 1
                if cnt % (total//100 + 1)  == 0:
                    print(f"(100*cnt/total) 완료")
    return M
```

C는 동시발생 행렬, verbose는 진행상황 출력 여부를 결정하는 flag다. 단어 x와 y가 동시에 발생하는 횟수를 C(x,y)라 했을 때,
$$C(x)=\sum_iC(i,x)$$
, $$C(y)=\sum_iC(i,y)$$
, $$N=\sum_i\sum_jC(i,j)$$
가 되도록 구현한 코드이다.

- 문제점

  - PPMI는 corpus 어휘 수가 증가하면 증가할 수록, 각 단어 벡터의 차원 수도 같이 증가한다.
  - 예를 들어, corpus의 어휘 수가 10만 개라면, 벡터의 차원 수도 10만이 된다.

```python
text = 'You say goodbye and I say hello. '
corpus, word_to_id, id_to_word = preprocess(text)
vocab_size = len(word_to_id)
vocab_size = len(word_to_id)
C = create_co_matrix(corpus, vocab_size)
W = ppmi(C)
np.set_printoptions(precision=3)
print('동시발생 행렬')
print(C)
# 동시발생 행렬
# [[0 1 0 0 0 0 0 0]
#  [1 0 1 0 1 1 0 0]
#  [0 1 0 1 0 0 0 0]
#  [0 0 1 0 1 0 0 0]
#  [0 1 0 1 0 0 0 0]
#  [0 1 0 0 0 0 1 0]
#  [0 0 0 0 0 1 0 1]
#  [0 0 0 0 0 0 1 0]]
print('-'*50)
print('PPMI')
print(W)
# PPMI
# [[0. 2. 0. 0. 0. 0. 0. 0.]
#  [2. 0. 1. 0. 1. 1. 0. 0.]
#  [0. 1. 0. 2. 0. 0. 0. 0.]
#  [0. 0. 2. 0. 2. 0. 0. 0.]
#  [0. 1. 0. 2. 0. 0. 0. 0.]
#  [0. 1. 0. 0. 0. 0. 2. 0.]
#  [0. 0. 0. 0. 0. 2. 0. 3.]
#  [0. 0. 0. 0. 0. 0. 3. 0.]]
```

- 또한 위 ppmi 행렬처럼 대부분의 원소가 0임을 알 수 있다. 즉, 대부분의 원소는 중요도가 낮다는 의미이다.
- 따라서 이 문제를 해결하기 위해 벡터의 차원 감소가 도입됐다.

<hr />
<hr />
<hr />

# 차원감소(dimensionality reduction)

- 차원 감소는 벡터의 차원을 줄이는 방법이다.
- 여기서 핵심은 중요한 정보는 최대한 보존하며, 줄이는 것이다.

  - <img src="../images/fig 2-8.png">
  - 어떠한 다차원 데이터에 대해서도 가장 적합한 축을 찾아내, 1차원 값만으로도 데이터의 본질적인 차이를 구별할 수 있어야 한다.

- 희소행렬(sparse matrix)

  - 원소 대부분이 0인 행렬은 희소행렬이라고 한다.
  - 차원 감소의 핵심은 희소행렬에서 중요한 축을 찾아내 더 적은 차원으로 다시 표현하는 것이다.
  - 차원감소의 결과는 원소 대부분의 값이 0이 아닌 값으로 구성된(유의미한) 밀집행렬로 변환된다.

  - 이러한 조밀한 벡터가 바로 단어의 분산 표현이다.

- 특잇값분해(Singular Value Decomposition(SVD))

  - 차원을 감소시키는 방법 중 하나이다.
  - SVD는 임의의 행렬을 세 행렬의 곱으로 분해하며, 수식은 다음과 같다.
  - $$X = USV^T$$
    $$U$$
    와 $$V$$
    는 직교행렬(orthogonal matrix)이고, 그 열벡터는 서로 직교한다.
    $$S$$
    는 대각행렬(diagonal maxtrix)(대각성분 외에는 모두 0인 행렬)이다.

  - <img src="../images/fig 2-10.png">
  - 행렬 S에서 특잇값이 작다면 중요도가 낮다는 뜻이므로, 행렬 U에서 여분의 열벡터를 깎아내어 원래의 행렬을 근사할 수 있다.

- 코드로 구현하면 다음과 같다.

```python
  # SVD를 코드로 구현
import matplotlib.pyplot as plt
C = create_co_matrix(corpus, vocab_size, window_size=1)
W = ppmi(C)

U, S, V = np.linalg.svd(W) # numpy에서 제공하는 linalg 모듈에서 SVD 메서드를 실행할 수 있다. linalg는 linear algebra의 약어다(선형대수)
print(U[0])
#   [-3.331e-16  2.193e-01 -3.098e-01 -3.331e-16  2.220e-16 -8.417e-01
#   1.356e-01  3.594e-01]
```
