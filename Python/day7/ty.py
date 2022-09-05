


try:
    4/0
except ZeroDivisionError as e:
    print(e)
try:
    a = [1, 2]
    print(a[3])
    4/0
except ZeroDivisionError:
    print('0으로 나눌 수 없습니다.')
except IndexError:
    print("인덱싱 할 수 없습니다.")

try:
    a = [1, 2]
    print(a[3])
    4/0
except (ZeroDivisionError, IndexError) as e:
    print(e)

try:
    age = int(input("input the age: "))
except:
    print("입력이 정확하지 않습니다.")
else:
    if age <= 18:
        print("미성년자는 출입금지입니다.")
    else:
        print("환영합니다.")

try:
    f = open('나없는파일', 'r')
except FileNotFoundError:
    pass

class Bird:
    def fly(self):
        raise NotImplementedError
    
class Eagle(Bird):
    pass

eagle = Eagle()
eagle.fly()

class MyError(Exception):
    def __str__(self):
        return '허용되지 않은 별명입니다.'
        
def say_nic(nick):
    if nick == '바보':
        raise MyError()
    print(nick)
try:
    say_nic('천사')
    say_nic('바보')
except MyError as e:
    print(e)
    


