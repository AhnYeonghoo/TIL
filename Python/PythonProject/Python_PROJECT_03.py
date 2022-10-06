# Unit 12 심사문제 
name =  input().split()
num =  map(float, input().split())
a = dict(zip(name,num))
print(a)

# Unit 13 심사문제 
price = int(input())
name = input()
if name == 'Cash3000':
    print(price-3000)
else :
    print(price-5000)

# Unit 14 심사문제 
a, b, c, d = map(int, input().split())
if 0 <= a <= 100 and 0 <= b <= 100 and 0 <= c <= 100 and 0 <= d <= 100:
    sum = a+b+c+d
    if (sum/4) >= 80:
        print('합격')
    else:
        print('불합격') 
else:
    print('잘못된 점수')

# Unit 15 심사문제 
age = int(input())
balance = 9000    # 교통카드 잔액
if age >= 19:
    balance -= 1250
elif 13 <= age < 19:
    balance -= 1050
else:
    balance -= 650
    print(balance)