# definition function

from re import L


def fib2(n):
    result = []
    a, b = 0, 1
    while a < n:
        result.append(a)
        a, b = b, a + b
    return result

f100 = fib2(100)
print(f100)

def ask_ok(prompt, retries=4, reminder='Please try again'):
    while True:
        ok = input(prompt)
        if ok in ('y', 'ye', 'yes'):
            return True
        if ok in ('n', 'no', 'nop', 'nope'):
            return False
        retries -= 1
        if retries < 0:
            return ValueError('invalid user response')
        print(reminder)
    
i = 5
def f(arg=i):
    print(arg)

def g(a, L=[]):
    L.append(a)
    return L
print(g(1))
print(g(3))
print(g(2))
i = 6
f()