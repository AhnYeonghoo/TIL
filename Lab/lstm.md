# (기본)RNN의 문제점

- 단순한 구조여서 시계열 데이터의 장기 의존 관계를 학습하기 어렵다.
- 그 원인으로는 BPTT에서 기울기 소실 혹은 폭팔이 일어나기 때문이다.

- 기본 RNN 계층의 계산 그래프

  - <img src="../images/fig 6-2.png">

<br >
<br >

## 기울기의 소실과 폭팔

- 기울기 소실은 역전파의 기울기 값이 점점 작아지다가 소멸되는 것을 뜻하고, 폭팔은 반대로 매우 큰 값이 된다는 것을 의미한다. 즉 학습이 더이상 불가능한 상태가 되는 것이다.

### 원인

- 예를 들어 다음과 같은 장기 기억이 필요한 문제를 보면

    <img src="../images/fig 6-3.png">

  - RNN이 이 문제에 정확한 답을 내릴려면 현재의 context에서 **Tom이 방에서 TV를 보고 있음** 과 **그 방에 Mary가 들어옴** 이라는 정보를 RNN 계층의 은닉 상태에 인코딩해 보관해두어야 한다.

  - 즉, RNN 계층이 과거 방향으로 학습에 의미가 있는 기울기를 전달해야만 시간 뱡향의 의존 관계를 학습할 수 있는 것이다.

  - 하지만 이 기울기가 중간에 사그라들면 가중치 매개변수는 전혀 갱신되지 않고, 학습할 수 없다.

<br>  
<br> 
<img src="../images/fig 6-5.png">

     그림처럼 길이가 T인 시계열 데이터를 가정하고, 앞의 문제에 대입하면, T번째 정답 레이블이 Tom인 경우에 해당한다. 이때 시간 뱡향 기울기에 주목하면 역전파로 전해지는 기울기는 차례대로 tanh, +, MatMul(행렬 곱) 연산을 통과하는 것을 알 수 있다.

- +의 역전파는 받은 기울기를 그냥 그대로 흘러보내기만 할 뿐이어서, 기울기의 변화는 없다.
- 다음으로 tanh 함수의 미분인데 y=tanh(x)일 때의 미분은 $$\frac{\partial z}{\partial x}=1-y^2$$ 이다.

- 이때의 y=tanh(x)의 값과 미분값을 그래프로 그리면 다음과 같다.

  - <img src="../images/fig 6-6.png">
      
      - 미분의 그래프는 x가 0으로부터 멀어질수록 작아진다.
      - 즉, 역전파 때 기울기가 tanh 노드를 지날 때마다 값이 계속 작아진다는 의미이다.
      - 따라서 tanh 함수를 T번 통과하면 기울기도 T번 반복하여 작아진다.

<br >

- **Improving performance of recurrent neural network with relu nonlinearity** 라는 논문에서는 RNN 계층의 활성화 함수를 tanh 함수 대신에 ReLU 함수를 사용해 기울기의 소실을 줄여 성능을 개선했다고 한다.

- ReLU 함수는 함수 특성상 입력 x가 0 이상이면 이전 노드의 기울기를 그대로 흘려보내기 때문에 기울기가 줄어들지는 않는다.

<br >
<br >

- 마지막으로 MatMul 노드에서는 기울기가 어떻게 변할까?

```python
import numpy as np
import matplotlib.pyplot as plt

N = 2 # 미니배치의 크기
H = 3 # 은닉 상태 벡터의 차원 수
T = 20  # 시계열 데이터 길이

dh = np.ones((N, H)) # 모든 원소가 1인 행렬 반환
np.random.seed(3) # 난수의 시드를 고정
Wh = np.random.randn(H, H)

norm_list = []  # L2 노름이란 각 각의 원소를 제곱해 모두 더하고 제곱근을 취한 값이다.
for t in range(T):
    dh = np.matmul(dh, Wh.T)
    norm = np.sqrt(np.sum(dh**2)) / N
    norm_list.append(norm)
```

해당 코드로 matmul 노드를 구현해 그래프를 그려보면 다음과 같이 그래프가 형성된다.

<br >

- <img src="../images/fig 6-8.png">

  - 이처럼, 기울기가 시간에 따라 지수적으로 증가한다.
  - 결국 기울기 폭팔로 이어지고, 오버플로가 발생해 NaN같은 값을 발생시켜, 학습을 이어나갈 수 없다.

```python
import numpy as np
import matplotlib.pyplot as plt

N = 2 # 미니배치의 크기
H = 3 # 은닉 상태 벡터의 차원 수
T = 20  # 시계열 데이터 길이

dh = np.ones((N, H)) # 모든 원소가 1인 행렬 반환
np.random.seed(3) # 난수의 시드를 고정
Wh = np.random.randn(H, H) * 0.5 # 가중치 초깃값 변경

norm_list = []  # L2 노름이란 각 각의 원소를 제곱해 모두 더하고 제곱근을 취한 값이다.
for t in range(T):
    dh = np.matmul(dh, Wh.T)
    norm = np.sqrt(np.sum(dh**2)) / N
    norm_list.append(norm)
```

- 가중치의 초깃값을 변경하면 그래프는 다음과 같이 형성된다.

  - <img src="../images/fig 6-9.png">

    - 시간에 따라 기울기가 지수적으로 감소한다.
    - 결국 기울기 소실이 일어나 가중치 매개변수를 갱신할 수 없고, 학습을 이어나갈 수 없게 된다.

## 기울기 폭팔 혹은 소실 대책

<br >

- 기울기 폭팔의 전통적인 대책으로 기울기 클리핑(gradients clipping)이라는 기법이 있다.

- 이 알고리즘을 의사 코드로 쓰면 다음과 같다.

  - $$if ||\hat{g}||\geq threshould:$$
  - $$\hat{g}=\frac{threshould}{||\hat{g}||}\hat{g}$$

  - threshould는 문턱값이고, 기울기의 L2 norm이 문턱값을 초과하면 두 번째 줄의 수식으로 기울기를 수정한다.

  - $$\hat{g}$$
  - 은 신경망에서 사용되는 모든 매개변수의 기울기를 하나로 모은 것이다.

<br >

코드로 구현하면 다음과 같다.

```python
def clip_grads(grads, max_norm):
    total_norm = 0
    for grad in grads:
        total_norm += np.sum(grad ** 2)
    total_norm = np.sqrt(total_norm)

    rate = max_norm / (total_norm + 1e-6)
    if rate < 1:
        for grad in grads:
            grad *= rate
```

## 고찰

RNN이 그냥 RNN인줄 알고 있었는데 이런 문제점이 있는지 잘 몰랐고, LSTM과 GRU가 이러한 RNN의 문제점을 해결하고자 나왔다는 배경을 알게 되었다.
