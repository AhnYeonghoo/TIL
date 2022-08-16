# 자료형

# 1. Integer
a = 123
a = -178
a = 0

# 2. Floating-point
a = 1.2
a = -3.45
a = 4.24E10 # 4.24 * 10^10
a = 4.24e-10 # 4.24 * 10^-10

# 3. Octal Number
a = 0o177

# 4. Hexadecimal Number
a = 0x8ff
a = 0xABC

# 사칙연산
a = 3
b = 4
print(a + b)
print(a - b)
print(a*b)
print(a/b)
print(a//b)
print(a%b)
print(a**b)

# String 문자열
a = "Hello World"
a = 'Python is fun'
# ""와 '' 모두 가능
a = """Life is too short,
You need python
"""
a = '''Life is too short,
You need python
'''
print(a)

# 따옴표안에 따옴표 넣기
a = "Python`s favorite food is perl"
print(a)
a = 'python is very easy" he say.'
print(a)
a = 'python \'s favorite food is perl'
print(a)
a = "\"Python is very easy.\" he says."
print(a)
# 줄 바꿈
a = "Life is too short\nYou need python"
print(a)
# \n 줄 바꿈
# \t 탭 간격 
# \\ 슬래시 문자 그대로 사용
# \r 캐리지 리턴(커서를 제일 앞으로)
# \b 백스페이스
# \000 Null 문자

# 문자열 연산
head = "Python"
tail = " is Fun!"
print(head+tail)
print(head*3)
print("="*50)
print("My Program")
print("="*50)
a = "Life is too short"
print(len(a))
a = "Life is too short, You need Python"
print(a[0])
print(a[1])
print(a[2])
print(a[3])
print(a[4])
print(a[5])
print(a[-1])
b = a[0] + a[1] + a[2] + a[3]
print(b)
print(a[0:4])
print(a[0:3]) # 이상 ~ 미만이기 때문에 짤려서 출력
print(a[0:5])
print(a[5:7])
print(a[12:17])
a = "Pithon"
print(a[:1])
print(a[2:])
print(a[:1] + 'y' + a[2:])
# Formating 
number = 3
print(f"I eat {number} apples")
name = "홍길동"
age = 30
print(f"나의 이름은 {name}입니다. 나이는 {age}입니다.")
print(f"나는 내년에 {age+1}살이 된다. 무야호 {30+40}")
d = {'name': '홍길동', 'age':30}
print(f"나의 이름은 {d['name']}이고, 나이는 {d['age']}살")

# 문자열 관련 메서드
a = "hobby"
print(a.count('b'))
a = "Python is the best choice"
print(a.find('b'))
print(a.find('k'))
a = "Life is too short"
print(a.index('t'))
# print(a.index('k'))
print(",".join(a))
print(",".join(['a','b','c','d']))
a = "lower"
print(a.upper())
a = "UPPER"
print(a.lower())
a = "  Hi  "
print(a.lstrip()) 
print(a.rstrip())
print(a.strip())
a ="Life is too short"
print(a.replace("Life", "Your leg"))
print(a.split())
b = "a:b:c:d"
print(b.split(':'))

