class Calculator:
    # Constructor
    def __init__(self, first, second):
        self.first = first
        self.second = second

    # add method
    def add(self):
        return self.first + self.second
    # sub method
    def sub(self):
        return self.first - self.second
    # mul method
    def mul(self):
        return self.first * self.second
    # divide method
    def div(self):
        return self.first / self.second
    # setData method
    def setData(self, first, second):
        self.first = first
        self.second = second
        
    
class MoreCalculator(Calculator):
    def pow(self):
        return self.first ** self.second
    
cal1 = Calculator(4,2)
cal2 = MoreCalculator(2,2)


print("\n\n")
print(cal1.add())
print(cal1.sub())
print(cal1.mul())
print(cal1.div())
print(cal2.pow())
print('\n\n')
print(abs(-5)) # 5
print(pow(4, 2)) # 16
print(max(1, -10, 5))
print(min(3, 1, -10))
print(round(3.14))
print(round(4.54))

from math import *
print(floor(4.99))
print(ceil(4.13))
print(sqrt(9))
print(sqrt(3))



