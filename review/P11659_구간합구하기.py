import sys
input = sys.stdin.readline
suNo, quizNo = map(int, input().split())
numbers = list(map(int, input().split()))
prefixSum = [0]
temp = 0

for i in numbers:
    temp += i
    prefixSum.append(temp)

for i in range(quizNo):
    s, e = map(int, input().split())
    print(prefixSum[e] - prefixSum[s-1]) # 합 배열에서 구간 합