a = [80, 75, 55]
result = 0
for i in a:
    result += i

print(result / len(a))
    
if 13 % 2 == 0:
    print('not odd')
else:
    print('odd')

number = '881120-1068234'
print(number[:6])
print(number[7:])

pin = '881120-1068234'
print(pin[7])
a = "a:b:c:d"
print(a.replace(':', '#'))

a = [1, 3, 5, 4, 2]
a.sort(reverse=True)
print(a)

a = (1, 2, 3)
print(a)
b = (4,)
a = a + b
print(a)

a = dict()
a = {'A':90, 'B':80, 'C':70}
print(a.pop('B'))

a = [1,1,1,2,2,3,3,3,4,4,5]
a = set(a)
print(list(a))

a = b = [1,2,3]
a[1] = 4
print(b)
print(id(a))
print(id(b))



