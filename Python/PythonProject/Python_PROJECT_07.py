# Unit 29 심사문제
def calc(x, y):
    return x+y, x-y, x*y, x/y

# Unit 30 심사문제
def get_min_max_score(*args):
    return min(args), max(args)

def get_average(**kwarg):
    return sum(kwarg.values()) / len(kwarg)

# Unit 31 심사문제
def fib(n):
    if n == 0 or n == 1: return n
    else: return fib(n-1) + fib(n-2)

# Unit 32 심사문제
list(map(lambda x: x.split('.')[0].zfill(3) + '.' + x.split('.')[1], files))