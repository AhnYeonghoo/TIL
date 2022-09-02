a = {1: 'a'}
a[2] = 'b'
print(a)
a['name'] = 'pey'
print(a)
a[3] = [1,2,3]
print(a)
del a[1]
print(a)

print('\n')
grade = {'pey': 10, 'julliet': 99}
print(grade['pey'])
print(grade['julliet'])

a = {1:'a', 2:'b'}
print(a[1])
print(a[2])

dic = {'name' : 'pey', 'phone' : '0119993323', 'birth' : '1118'}
print(dic['name'])
print(dic['phone'])
print(dic['birth'])
a = {(1,2): 'a'}
print(a[1,2])
a = {'name': 'pey', 'phone': '0119993323', 'birth': '1118'}
print(a.keys())
print(list(a.keys()))
print(type(a.keys()))
print(type(list(a.keys())))
print(a.values())
print(a.items())
# a.clear()
print(a)
print(a.get('name'))
print(a.get('phone'))
print(a.get('foo', 'bar'))
print('name' in a)
print('email' in a)