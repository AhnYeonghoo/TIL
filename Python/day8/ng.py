from this import d


words = ['cat', 'window', 'defensetrate']
for w in words:
    print(w, len(w))

print()

users = {'Hans': 'active', 'Eleonore':'inactive', 'www':'active'}

for user, status in users.copy().items():
    if status == 'inactive':
        del users[user]

print(users)

active_users = {}
for user, status in users.items():
    if status == 'active':
        active_users[user] = status
print(active_users)

for i in range(5):
    print(i)

a = ['Mary', 'had', 'a', 'little', 'lamb']
for i in range(len(a)):
    print(i, a[i])

print(sum(range(4)))

print('\n\n')
for n in range(2, 10):
    for x in range(2, n):
        if n % x == 0:
            print(n, 'equals', x, '*', n//x)
            break
    else:
        print(n, 'is a prime number')

print('\n\n')

for num in range(2, 10):
    if num % 2 == 0:
        print("Found an even number", num)
        continue
    print("FOund an odd number", num)

# 클래스 틀 만들 때 주로 사용되는 pass
class MyEmptyClass:
    pass

def http_error(status):
    match status:
        case 400:
            return "Bad request"
        case 404:
            return "Not found"
        case 418:
            return "i`m a teapot"
        case 401  | 403 | 404:
            return "Not allowed"
        case _:
            return "Something`s wrong with the internet"
        
class Point:
    x: int
    y: int

def where_is(point):
    match point:
        case Point(x=0, y=0):
            print("Origin")
        case Point(x=0, y=y):
            print(f"Y={y}")
        case Point(x=x, y=0):
            print(f"X={x}")
        case Point():
            print("Somewhere else")
        case _:
            print("Not a point")
    
print(where_is(Point(1,3)))
print(where_is(Point(1,y=var)))
print(where_is(Point(x=1,y=3)))
print(where_is(Point(y=1,x=3)))

import matplotlib.pyplot as plt
sales = [1,5,7,3,7]
month = [3, 4, 5, 6, 7]
plt.rc('font')
plt.title('월별 판매 실적')
plt.bar(month,sales, color='b')
plt.show()
sales = [1, 5, 7, 3, 7]
plt.title('월별 판매 실적')
plt.barh(range(3, 8), sales, color='b')
plt.show()
sales = [1, 5, 7, 3, 7]
plt.hist(sales)
plt.show()
import random
a = []
for i in range(10):
  a.append(random.randint(1, 10))
print(a)
plt.hist(a)
plt.show()
a = [7, 5, 3, 3, 1, 3, 2, 10 ,7, 8]
plt.hist(a, bins=20)
plt.show()
b_type=[25, 19, 37, 11]
plt.pie(b_type)
plt.show()
b_type=[25, 19, 37, 11]
plt.pie(b_type, labels=['A', 'B', 'O', 'AB'])
plt.show()
b_type = [25, 19, 37, 11]
labels = ['A', 'B', 'O', 'AB']
plt.pie(b_type, labels=labels, autopct='%1.2f%%')
plt.show()
kor = [80, 20, 50, 20, 10, 50, 60 ,30 ,60]
eng = [90, 40, 60, 40, 10, 30, 50, 70, 90]
plt.scatter(kor, eng)
plt.show()
kor = [80, 20, 50, 20, 10, 50, 60 ,30 ,60]
eng = [90, 40, 60, 40, 10, 30, 50, 70, 90]
plt.scatter(kor, eng, color='red', alpha=0.3)
plt.xlabel('국어')
plt.ylabel('영어')
plt.show()
