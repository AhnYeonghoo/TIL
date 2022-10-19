# Unit 33.6

def countdown(n):
    global i
    i = -1 
    i += 1
    
    return (lambda : n - i)
n = int(input())
 
c = countdown(n)
for i in range(n):
    print(c(), end=' ')

# Unit 34.6

class Annie():
    def __init__(self, health, mana, ability_power):
        self.health = health
        self.mana = mana
        self.ability_power = ability_power
        self.damage = self.ability_power * (0.65) + 400
    
    def tibbers(self):
        print("티버: 피해량 {}".format(self.damage))

health, mana, ability_power = map(float, input().split())
 
x = Annie(health=health, mana=mana, ability_power=ability_power)
x.tibbers()

# Unit 35.6

class Time:
    def __init__(self, hour, minute, second):
        self.hour = hour
        self.minute = minute
        self.second = second
 
    @staticmethod
    def is_time_valid(time_string):
        hour, minute, second = map(int, time_string.split(':'))
        return hour <= 24 and minute <= 59 and second <= 60
        
        
    @classmethod
    def from_string(cls, time_string):
        hour, minute, second = map(int, time_string.split(':'))
        time = cls(hour, minute, second)
        return time
        
 
time_string = input()
 
if Time.is_time_valid(time_string):
    t = Time.from_string(time_string)
    print(t.hour, t.minute, t.second)
else:
    print('잘못된 시간 형식입니다.')

# Unit 36.9

class Animal:
    def eat(self):
        print('먹다')
 
class Wing:
    def flap(self):
        print('파닥거리다')

class Bird(Animal, Wing):
    def fly(self):
        print("날다")

b = Bird()
b.eat()
b.flap()
b.fly()
print(issubclass(Bird, Animal))
print(issubclass(Bird, Wing))