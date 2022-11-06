# Class

result = 0
result2 = 0.0
def add(num: int) -> int:
    global result
    result += num
    return result

def add2(num: float) -> float:
    global result2
    result2 += num
    return result2

class Calculator:
    def __init__(self):
        self.result = 0

    def add(self, num):
        return self.result + num

print(add(3))
print(add(4))
print(add2(0.2))
print(add2(1.8))

cal1 = Calculator()
cal2 = Calculator()

print(cal1.add(3))
print(cal1.add(4))
print(cal2.add(0.2))
print(cal2.add(1.8))

