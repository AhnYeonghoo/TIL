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
