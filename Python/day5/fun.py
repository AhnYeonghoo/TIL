def deposit(balance, money):
    print("입금완료 잔액은 {0} 입니다.".format(balance+money))
    return balance+money

def withdraw(balance, money):
    if balance >= money:
        print("출금완료 잔액은 {0} 입니다.".format(balance - money))
        return balance - money
    else:
        print("잔액이 부족합니다. 잔액은 {0}입니다.".format(balance))
        return balance

def withdraw_night(balance, money):
    commission = 100
    return commission, balance - money - commission
balance = 0
balance = deposit(balance, 1000)
balance = withdraw(balance, 2900)
balance = withdraw(balance, 900)
print(balance)
commission, balance = withdraw_night(balance, 400)
print(commission)
print(balance)

def profile(name, age, main_leng):
    print(f"이름 : {name}, 나이는 {age} , 주 사용 언어: {main_leng} ")

print()

profile("유재석", 20, '파이썬')
profile("김태호", 25, '자바')

def profile_default(name, age=17, main_leng='파이썬'):
    print(f"이름 : {name}, 나이는 {age} , 주 사용 언어: {main_leng} ")

profile_default("유재석")
profile_default("김태호")

def profile_two(name, age, main_lang):
    print(name, age, main_lang)

profile_two("유재석", 20, '파이썬')
profile_two(name='기매태', main_lang='자바', age=40)

