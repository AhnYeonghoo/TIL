# 05 Unit 20, 22, 23, 24

# 20.8 심사문제: 5와 7의 배수, 공배수 처리하기
start, stop = map(int, input().split())
for i in range(start, stop + 1):
    print('Fizz' * (i % 5 == 0) + 'Buzz' * (i % 7 == 0) or i)

# 22.10 심사문제: 2의 거듭제곱 리스트 생성하기
start, stop = map(int, input().split())
a = list(2 ** i for i in range(start, stop + 1))
a.pop(len(a)-2)
a.pop(1)
print(a)

# 23.7 심사문제: 지뢰찾기
col, row = map(int, input().split())
matrix = [['.' for i in range(col+2)] for i in range(row+2)]
for i in range(1, row + 1):
    matrix[i][1 : col+1] = list(input())
for i in range(1, row + 1):
    for j in range(1, col + 1):
        cnt = 0
        if(matrix[i][j] == '.'):
            if matrix[i][j+1] == '*':
                cnt += 1
            if matrix[i-1][j] == '*':
                cnt += 1
            if matrix[i+1][j] == '*':
                cnt += 1
            if matrix[i][j-1] == '*':
                cnt += 1
            if matrix[i-1][j+1] == '*':
                cnt += 1
            if matrix[i-1][j-1] == '*':
                cnt += 1
            if matrix[i+1][j-1] == '*':
                cnt += 1
            if matrix[i+1][j+1] == '*':
                cnt +=1
        
            matrix[i][j]=cnt
for i in range(1, row + 1):
    for j in range(1, col + 1):
        print(matrix[i][j],end='')
    print()

# 24.5 심사문제: 특정 단어 개수 세기
import string
s=list(input().split())
count = 0
for i in s:
    i = i.strip(',.')
    if 'the' == i:
        count+=1
print(count)

# 24.6 심사문제: 높은 가격순으로 출력하기
a=list(map(int,input().split(';')))
a.sort()
for i in range(len(a)-1,-1,-1):
    print(str(format(a[i],',')).rjust(9))