sentence = '나는 소년입니다.'
print(sentence)
sentence2 = "파이썬은 쉬워요"
print(sentence2)
sentence3 = """
여러줄도 가능하구요.
파이썬은 쉬워요.
"""
print(sentence3)
print()
print()

jumin = "990120-1234567"
print(jumin[:6])
print(jumin[7:])
if int(jumin[7]) == 1:
    print("man")
else:
    print("girl")

python = "Python is Amazing"
print(python.lower())
print(python.upper())
print(python[0].isupper())
print(len(python))
print(python.replace('Python', 'java'))

index = python.index('n')
print(index)
index = python.index('n', index+1)
print(index)

print(python.find('i'))
print(python.count('n'))
print(python.find("Java"))
# print(python.index('java')) -> index는 못 찾으면 Throw Error

print("백문이 불여일견\n백견이 불여일타")

url = "http://naver.com"
my_str = url.replace("http://", "")
my_str = my_str[:5] # my_str[:my_str.index(".")]
print(my_str)
length = len(my_str)
result = my_str[:3] + str(len(my_str)) + str(my_str.count('e')) + "!"
print(f"비밀번호는 {result} 입니다.")

