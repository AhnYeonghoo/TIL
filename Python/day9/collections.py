# list, tuple

# list -> mutable
# tuple -> immutable

# initial 
# 1. [] 
# 2. list()
# 3. str.split()

from re import A


a = ['list1', 'list2']
print(type(a))

a = list(['list1'])
print(type(a))

a = "list1, list2"
a = str.split(a, ',')
print(a)
print(type(a))

a = ['korea', 'canada', 1, 23, [34, 56]]
print(a[-1][0])

a = 'hello world'
b = list(a)
print(b)

c = (1, 2, 3)
d = list(c)
print(d)



a = 'hello world nice weather'
b = a.split('e')
print(b)


a = [1, 2, 3, 4, 5]
print(a[-2])

a = 'hello world'
print(a[0])
b = 'j' + a[1:]
print(b)
print(a)