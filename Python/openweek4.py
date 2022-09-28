# List Comprehension
oddNumber = [i for i in range(10) if i % 2 == 0]

complexNumber = [i * j for j in range(2, 10) for i in range(1, 10)]

print(oddNumber)
print(complexNumber)

a = [1.2, 2.5, 3.7, 4.6]
a = list(map(int, a))
print(a)

# Tuple
a = tuple(i for i in range(10) if i % 2 == 0)
print(a)

d = {}
d['key1'] = 100
d.setdefault('key2')
d.setdefault('key3', 200)
d.update(key3=300, key4=400)
d.update({1: 'ONE', 2: 'TWO'})
# d.update(zip(keys, values))
print(d)

d = {'key1': 100, 'key2': 200, 'key3': 300}
d.pop('key1')
d.pop('key10', -1)
del d['key2']
print(d)
d.clear()
print(d)