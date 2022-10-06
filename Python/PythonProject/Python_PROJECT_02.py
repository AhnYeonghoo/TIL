# 02 Unit 8 ~ 11 심사문제

# 8.5 심사문제: 합격 여부 출력하기
kor,eng,mat,sci=map(int,input().split())
print(kor >=90 and eng > 80 and mat > 85 and sci>=80)

# 9.4 심사문제: 여러 줄로 된 문자열 사용하기
s = """'Python' is a "programming language"
that lets you work quickly
and
integrate systems more effectively."""
print(s)

# 10.5 심사문제: range로 튜플 만들기
a = int(input())
a = tuple(range(-10, 10, a))
print(a)

# 11.8 심사문제: 리스트의 마지막 부분 삭제하기
x = input().split()
del x[len(x)-1:-6:-1]
print(tuple(x))

# 11.9 심사문제: 문자열에서 인덱스가 홀수인 문자와 짝수인 문자 연결하기
one=input()
two=input()
print(one[1::2] + two[::2])