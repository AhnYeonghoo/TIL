a = 1
b = 'python'
c = [1,2,3]
a = [1, 2, 3]
print(id(a))
b = a
print(id(a))
print(id(b))
a = [1, 2, 3]
b = a[:]
print(id(a))
print(id(b))
a[1] = 4
print(a)
print(b)
from copy import copy

a = [1, 2,3]
b = copy(a)
print(b is a)
a = [ 1, 2, 3]
b = a.copy()
print(a is b)
a, b = ('python', 'life')
(a, b) = 'python', 'life'
[a, b] = ['python', 'life']
a =b  = 'python'
a = 3
b = 4
a , b = b, a
print(a, b)