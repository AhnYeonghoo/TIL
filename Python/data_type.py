from codecs import StreamRecoder


year = 2016
print(type(year))
height = 175.5
print(type(height))
name = '제임스'
print(type(name))
p = 3.141592
score = 97
print(type(score), score)
score = float(score)
print(type(score), score)
avg = 83.4
print(type(avg), avg)
avg = int(avg)
print(type(avg), avg)
a = '30'
print(int(a) * 3)
r  = int(input('반지름은?: '))
result1 = p * r ** 2
result2 = 2 * p * r
result3 = 4 * p * r ** 2
print(f'원의 넓이 = {result1}, 원의 둘레 = {result2}, 구의 겉넓이 = {result3} ')
