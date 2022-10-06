# Unit 25 심사문제
x = {key: value for key, value in x.items() if key != 'delta' and value != 30}

# Unit 26 심사문제
first, second = map(int, input().split())
a = {i for i in range(1, first + 1) if first % i == 0}
b = {i for i in range(1, second + 1) if second % i == 0}

# Unit 27 심사문제
f = open("words.txt", "r")
x = f.read()
f.close()

x = x.replace(',', '')
x = x.replace('.', '')
x = x.split(' ')

for i, val in enumerate(x):
    if 'c' in val:
        print(val)

# Unit 28 심사문제
f = open("words.txt", "r")
x = f.readlines()
f.close()

x = [i.replace('\n', '') for i in x]

for i, val in enumerate(x):
    if val == val[::-1]:
        print(val)