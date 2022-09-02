from re import A


odd = [1, 3, 5, 7, 9]

a = [1, 2, ['a', 'b', ['Life', 'is']]]
print(a[-1][2][0])

a = [1, 2, 3, 4, 5]
print(a[0:2])
print(a[:2])
print(a[2:])

a = [1, 2, 3, ['a', 'b', 'c'], 4 ,5]
print(a[2:5])
print(a[3][:2])

a = [1, 2, 3]
b = [4, 5, 6]
print(a + b)
print(type(a))
print(type(a+b))
print(a*3)
print(len(a*3))

print(str(a[2]) + "Hi")

a = [1, 2, 3]
a[2] = 4 # 수정

del a[2]
print(a)

a = [1, 2, 3, 4, 5]
del a[2:]
print(a)
a.append(4)
print(a)
a.append([4,5])
print(a)
a = [4, 2, 1, 3]
a.sort()
print(a)
a.reverse()
print(a)
a = ['a', 'c', 'd']
a.reverse()
print(a)
# index = a.index(3)

a = [1, 2, 3]
index = a.index(3)
print(index)

a = [1, 2, 3]
a.insert(0, 4)
print(a)
a.insert(3, 5)
print(a)
a.remove(3)
print(a)
a = [1,2,1,2]
a.remove(2)
print(a)
a = [1, 2, 3]
print(a.pop())
print(a)
print(a.pop(1))
print(a)
a = [1,2,3,1]
count = a.count(1)
print(count)
a = [1, 2, 3]
a.extend([4, 5])
b = [6, 7]
print(a)
a.extend(b)
print(a)