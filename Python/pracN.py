from re import M


print(5//2)
print(5/2)
print(type(35.9))
m, n = 30, 40
m, n = n, m
print(m, n)
x = 10
print(x)
del x;
a = 233
print(id(a))
a = 300
print(id(a))
a = 300
print(id(a))
b = 300
print(id(b))
print(a == b)
print(a is  b)

a = b = 300
print(a is b)
print(id(a), id(b))
a = 250
print( a is b)
print(id(a), id(b))

a = b = 100
c = 100
print(a == b)
print(a == c)
print(a is b)
print(a is c)
print(id(a), id(b), id(c))
a = 1000
b = 1000
c = 500
print(a == b and a != c)
print(bool(''))
print(bool('False'))
print(bool('Python'))
print(bool(0.0))
print(bool(3))
print()
a = [0, 10, 20, 30, 40, 50, 60, 70, 80, 90]
b = tuple(range(3, 14, 2))
c = range(10)
d = 'Nice to meet you'
print()

print(50 in a)
print(5 in b)
print(9 in c)
print('m' not in d)

print([1, 2, 3] + [4, 5])
print(a + list(c))
print('THis is' + 'the end')

print('Count: ' + str(10))
print([0, 10, 20, 30] * 3)
print(list(range(3)) * 0)
print('Say it again' + ' and again'*4 + '...')

print(a)
print(a[-1])
print(a[len(a) - 1])

print(a, '\t' + str(len(a)))
del a[2]
print(a, '\t' + str(len(a)))
a = list(range(10))
print(a)
print(a[4::2])
print(a[:7:2])
print(a[3:-3:2])
print(a[5:1:-1])
s = list(range(4, 25, 4))
print(s)
s[2:5] = [3, 4, 5]
print(s)
s[2:5] = [7]
print(s)
s[1:3] = list(range(7))
print((1, 2, 3) < (1, 2, 4))
print([1, 2, 3] < [1, 2, 4])
print('ABC' < 'C' < 'Pascal' < 'Python')
print((1, 2, 3, 4) < (1, 2, 4))
print((1, 2) < (1, 2, -1))
print((1, 2, 3) == (1.0, 2.0, 3.0))
print((1, 2, ('aa', 'ab'), 4) < (1, 2, ('abc', 'a')))
a = 1000
print(id(a))
a = 2
print(id(a))
a = list(range(20))
print(id(a))
a[3:9] = [5, 6]
print(id(a))
a = [1,2,3]
b = a
c = [1,2,3]
print(a == b, a is b)
print(a == c, a is c)
print(id(a), id(b), id(c))
a[1] = 8
print(b)
print(id(a), id(b), id(c))
import copy
a = [1, 2, 3]
b = a[:] # deep copy
c = copy.deepcopy(a) # deep copy
print(a, b, c)
print(id(a), id(b), id(c))
d = {}
print(type(d))
lux = {'health': 490, 'health': 800, 'mana': 334, 'melee': 550, 'armor': 18.72}
print(lux['health'])
keys = ['a', 'b', 'c']
values = [1, 2, 3]
print('zip: \t', list(zip(keys, values)))
d = dict(zip(keys, values))
print('dict:\t', d)
print(d.keys())
print(d.values())
print(d.items())
x = 5
y = x if x == 10 else 0
print(y)
def func():
    return
print(func())

print('None:\t', end='')
if None:
    print("true")
else:
    print("false")

print('0\t', end='')
if 0:
    print('true')
else:
    print('false')
print('3.2\t', end='')
if 3.2:
    print('true')
else:
    print('false')
print("'False'\t:", end='')
if 'False':
    print("True")
else : 
    print("False")
print("''\t:", end='')
if '':
    print("True")
else : 
    print("False")

print("{}\t:", end='')
if {}:
    print("True")
else : 
    print("False")
    
print("(2,)\t:", end='')
if (2,):
    print("True")
else : 
    print("False")

print()
print()
x = 10
y = 10
z = 0
if x == 10:
    z = 1
else:
    if y == 10:
        z = 2
    else:
        z = 3
print(z)
x = 5
y = 5
z = 1 if x == 10 else 2 if y == 10 else 3
print(z)
for i in range(9, -1, -1):
    print(i, end=' ')
print(type(range(9, -1, -1)))
a = list(range(10))
for i in a[::-1]:
    print(i, end=' ')
print(type(a[::-1]))
print(a)
a.reverse()
print(a)
for i in a:
    print(i, end=' ')
print(type(a))
print('a after reversed(): ', a)

for i in reversed(a):
    print(i, end=' ')
print(type(reversed([1,2 , 3])))
print(a)
a = list(range(10))
b = a.reverse()
print(a)
print(b)
for i in reversed([1, 2, 3]):
    print(i)
for i in reversed((1, 2, 3)):
    print(i)
for i in reversed('Hello'):
    print(i)
    
for i in range(10):
    print('after for: ', i)
    i = 18
    print(i)
i = 0
while i < 3:
    print('Hello world', i)
    i += 1

i = 3
while i > 0:
    print('Hello World', i)
    i -= 1

import random
print(random.random())
print(random.random())
print(random.random())
print(100*random.random())
print(100*random.random())
print(100*random.random())
print(random.randint(10, 20))
print(random.randint(10, 20))
print(random.randint(10, 20))
s = [1, 2, 3, 4, 5]
print(random.choice(s))
print(random.choice(s))
print(random.choice(s))

i = 0
while True:
    print(i)
    i += 1
    if i == 5:
        print('bye')
        break
    print('still running')

