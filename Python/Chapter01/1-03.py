a = 'hello'
b = ['hello', 'python']
print(id(a))
print(id(b))
print(id(a))
print(id(b[0]))

# Immutable과 Mutable
# 수정 불가능한 객체는 Immutable
# 수정 가능한 객체는 Mutable이라고 부른다.
# Immutable은 정수, 실수, 문자열, 튜플
# Mutable은 리스트와 딕셔너리이다.
