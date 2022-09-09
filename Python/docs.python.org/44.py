import os
x = {'key1': 'value1 from x', 'key2': 'value2 from x'}
y = {'key2': 'value2 from y', 'key3': 'value3 from y'}
z = x | y
print(z)
n = y | x
print(n)

def greet_all(names: list[str]) -> None:
    for name in names:
        print("Hello", name)
        
    
os.system('cls')

fruits = ['orange', 'apple', 'pear', 'banana', 'kiwi', 'apple', 'banana']
print(fruits.count('apple'))
print(fruits.count('tangerine'))
print(fruits.index('banana'))
print(fruits.index('banana', 4))
fruits.reverse()
print(fruits)
fruits.append('grape')
print(fruits)
fruits.sort()
print(fruits)
fruits.pop()
print(fruits)
os.system('cls')
stack = [3, 4, 5]
stack.append(6)
stack.append(7)
print(stack)
print(stack.pop())
print(stack)
print(stack.pop())
print(stack.pop())
print(stack)
from collections import deque
queue = deque(["Eric", "John", "Michael"])
queue.append("Terry")
queue.append("Graham")
print(queue)
print(queue.popleft())
print(queue.popleft())
print(queue)
os.system('cls')
squares = []
for x in range(10):
    squares.append(x**2)
print(squares)
squares = [x**2 for x in range(10)]
print(squares)
print([(x, y) for x in [1,2,3] for y in [3, 1, 4] if x != y])
combs = []
for x in [1, 2, 3]:
    for y in [3, 1, 4]:
        if x != y:
            combs.append((x, y))
print(combs)
from math import pi
print([str(round(pi, i)) for i in range(1, 6)])
os.system('cls')
matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
]
print([[row[i] for row in matrix] for i in range(4)])
transposed = []
for i in range(4):
    transposed.append([row[i] for row in matrix])
    
for i in matrix:
    print(i)
os.system('cls')
result = list(zip(*matrix))
print(result)
a = [-1, 1, 66.25, 333, 333, 1234.5]
print(a)
del a[0]
print(a)
del a[2:4]
print(a)
del a[:]
print(a)
del a
# print(a)


