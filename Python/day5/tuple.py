t1 = ()
t2 = (1,)
t3 = (1,2,3)
t4 = 1, 2, 3
t5 = ('a', 'b', ('ab', 'cd'))

t1 = (1, 2, 'a', 'b')
# del 불가능

print(t1[0])
print(t1[3])
print(t1[1:])

t1 = (1, 2, 'a', 'b')
t2 = (3, 4)
t3 = t1 + t2
print(t3)

t2 = (3, 4)

print(t2 * 3)
print(len(t2))