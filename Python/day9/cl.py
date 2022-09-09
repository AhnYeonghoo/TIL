


class Complex:
    def __init__(self, realpart, imagpart):
        self.r = realpart
        self.i = imagpart
        
x = Complex(3.0, -4.0)
print(x.i, x.r)

class Dog:
    # tricks = []
    kind = 'canine'
    
    def __init__(self, name):
        self.name = name
        self.tricks =[]
    def add_trick(self, trick):
        self.tricks.append(trick)
        
d = Dog("Fido")
e = Dog('Buddy')
d.add_trick('roll over')
e.add_trick('play dead')
print(d.kind)
print(e.kind)
print(d.name)
print(e.name)
print(d.tricks)

class Warehouse:
    purpose = 'storage'
    region = 'west'

def f1(self, x ,y):
    return min(x, x+y)
class C:
    f = f1

    def g(self):
        return 'hello world'

    h = g

class Bag:
    def __init__(self):
        self.data = []
    def add(self, x):
        self.data.append(x)
    def addtwice(self, x):
        self.add(x)
        self.add(x)

    