class FourCal:
    
    def __init__(self, first, second):
        self.first = first
        self.second = second
        
    def setData(self, first, second):
        self.first = first
        self.second = second
        
    def add(self):
        return self.first + self.second
    
    def sub(self):
        return self.first - self.second
        
    def mul(self):
        return self.first * self.second
    
    def div(self):
        return self.first / self.second


class MoreFourCal(FourCal):
    def pow(self):
        return self.first ** self.second
        

class SafeFourCal(FourCal):
    def div(self):
        if self.second == 0:
            return 0
        else:
            return self.first / self.second

class Family:
    last_name = 'kim'

mfc = MoreFourCal(4, 2)
print(mfc.add())
print(mfc.sub())
print(mfc.mul())
print(mfc.div())
print(mfc.pow())
print(Family.last_name)
f = Family()
print(f.last_name)
f.last_name = 'ahn'
print(f.last_name)
