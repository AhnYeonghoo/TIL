def add_many(*args):
    result = 0
    for i in args:
        result += i
    return result

def add_mul(choice, *args):
    if choice == "add":
        result = 0
        for i in args:
            result += i
    elif choice == 'mul':
        result = 1
        for i in args:
            result *= i
    return result
    
def print_kwargs(**kwargs):
    print(kwargs)

def say_nick(nick):
    if nick == '바보':
        return
    print(f"나의 별명은 {nick}입니다.")
def say_myself(name, old, man=True):
    print(f"나의 이름은 {name}입니다.")
    print(f'나이는 {age}입니다.')
    if man:
        print('man')
    else:
        print('girl')

a = 1
def vartest():
    global a
    a += 1

add = lambda a, b : a + b
result = add(5, 5)
print(result)
vartest()
print(a)
print(print_kwargs(a=1))
print(print_kwargs(name='foo', ags=3, ddd=333))
print(add_many(1,2,3,4,5))
