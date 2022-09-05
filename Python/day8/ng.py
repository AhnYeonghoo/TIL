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

