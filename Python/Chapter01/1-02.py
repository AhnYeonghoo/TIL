# C언어 스타일의 문자열 포맷팅
name = 'minsu'
score = 90
print("%s의 점수는 %d점입니다." %(name, score))

# Python3 부터 지원하는 format 메서드
print("{}의 점수는 {}점 입니다.".format(name, score))

# Python3.6부터 지원하는 f-string 예
print(f"{name}의 점수는 {score}점 입니다.")

# 중괄호 자체를 출력
data = 3
fmt = "{{ {} }}".format(data)
print(fmt)
fmt = f"{{ {data} }}"
print(fmt)

# 자릿수 채우기
a = 3
mystr = f"{a:02d}"
print(mystr)

symbol = "BTCUSDT"
print(f"{symbol: 10}")

# 실수 다루기
a = 3.141592
mystr = f"{a: 6.2f}"
print(mystr)
