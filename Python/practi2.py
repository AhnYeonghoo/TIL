import random
import requests


url = "https://dhlottery.co.kr/common.do?method=main"
html = requests.get(url).text
list = []

random_ = random.randint(1, 46)

for i in range(7):
    while random_ in list:
        random_ = random.randint(0, 9)
    
    list.append(random_)



list.sort()
print(list)