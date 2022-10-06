# 04 Unit 16 ~ 19

# 16.6 심사문제: 구구단 출력하기
a=int(input())
for i in range(1, 9+1):
    print("{0} * {1} = {2}".format(a, i, a * i))

# 17.6 심사문제: 교통카드 잔액 출력하기
m = int(input())
while 1:
    m -= 1350
    if m < 0: break
    print(m)

# 18.6 심사문제: 두 수 사이의 숫자 중 3으로 끝나지 않는 숫자 출력하기
start, stop = map(int, input().split())
 
i = start
 
while True:
    if(i > stop):
        break
    if(i % 10 == 3):
        i+=1
        continue
    print(i, end=' ')
    i += 1

# 19.6 심사문제: 산 모양으로 별 출력하기
n = int(input())
for i in range(n):
    for j in range(n - i - 1):
        print(" ", end='')
    for j in range(2*i + 1):
        print("*", end='')
    print()