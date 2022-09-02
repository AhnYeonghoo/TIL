for i in [1,2,3,4,5]:
    print("Hello")

for a in [1,2,3,4,5]:
    print(a, "을 저장 중입니다.")

for a in range(1, 20):
    print(a, "선생님, 다시는 장소를 빼먹지 않겠습니다.")

for a in range(20):
    print(a)

for a in range(1, 20, 2):
    print(a)

result = 0
for i in range(1, 51):
    result += i
print(result)
result = 0
for i in range(101, 151):
    result += i
print(result)
result = 1
for i in range(1, 51):
    result *= i
print(result)
num = int(input("number "))
for i in range(1, 10):
    print(f"{num} x {i} = {num*i}  ")