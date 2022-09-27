import pandas as pd 
import requests
import random
from tqdm import tqdm

# 1-45부터 추출
# 서로 겹치는 숫자가 나오면 안된다.

numbers = list()
for _ in range(7):
    number = random.randint(1, 45)
    while number in numbers:
        number = random.randint(1, 45)
    numbers.append(number)



# 2. 파이썬 웹크롤링
#   1. 리스트에 기존 당첨 번호를 저장 {“1,2,3,4,5,6”} ->파싱(“,”) //split으로 나누면 됨.
#   2. [0] = ‘1’, [1] = ‘2’ toInterger -> 숫자로 변경 후 비교


def getLottoWinInfo(startRound, endRound):
    drwtNo1 = [] 
    drwtNo2 = [] 
    drwtNo3 = [] 
    drwtNo4 = [] 
    drwtNo5 = [] 
    drwtNo6 = [] 
    bnusNo = [] 
    for i in tqdm(range(startRound, endRound+1, 1)): 
        req_url = "https://www.dhlottery.co.kr/common.do?method=getLottoNumber&drwNo=" + str(i)
        req_lotto = requests.get(req_url) 
        lottoNo = req_lotto.json() 
        drwtNo1.append(lottoNo['drwtNo1']) 
        drwtNo2.append(lottoNo['drwtNo2']) 
        drwtNo3.append(lottoNo['drwtNo3']) 
        drwtNo4.append(lottoNo['drwtNo4']) 
        drwtNo5.append(lottoNo['drwtNo5']) 
        drwtNo6.append(lottoNo['drwtNo6']) 
        bnusNo.append(lottoNo['bnusNo']) 
        lotto_dict = {
                      "Num1":drwtNo1, "Num2":drwtNo2,
                      "Num3":drwtNo3, "Num4":drwtNo4, "Num5":drwtNo5, 
                      "Num6":drwtNo6, "bnsNum":bnusNo,
                    }
        lotto_df = pd.DataFrame(lotto_dict)
    return lotto_dict, lotto_df # 반환값이 딕셔너리랑, 판다스 프레임

startRound = 930
endRound = 990
lotto_dict, lotto_df = getLottoWinInfo(startRound, endRound)

legecyNum1 = lotto_dict['Num1'][:7]
legecyNum2 = lotto_dict['Num2'][:7]
legecyNum3 = lotto_dict['Num3'][:7]
legecyNum4 = lotto_dict['Num4'][:7]
legecyNum5 = lotto_dict['Num5'][:7]
legecyNum6 = lotto_dict['Num6'][:7]
legecyBonus = lotto_dict['bnsNum'][:7]


"""3. 사용자가 입력한 7개의 번호를 
가지고 기존 당첨번호를 비교해서 누적등수 출력
(마지막은 보너스)
        1. 1등 - 1번
        2. 2등 - 3번
        3. 5등 - 100번
        """
        


userInput = list(input().split())# 7개 입력


result = []
for i in range(len(userInput)):
    if int(userInput[i]) == legecyNum1[i] or int(userInput[i]) == legecyNum2[i] or int(userInput[i]) == legecyNum3[i] or int(userInput[i]) == legecyNum4[i] or int(userInput[i]) == legecyNum5[i] or int(userInput[i]) == legecyNum6[i] or int(userInput[i]) == legecyBonus[i]:
        result.append(int(userInput[i]))
        


     

if len(result) < 4:
    print("맞춘 숫자는", end=' ')
    for i in range(len(result)):
        print(f'{result[i]}', end=', ')
    print('로 아쉽게도 낙첨 되었습니다.!')
    print(f'맞춘 숫자수: {len(result)}')
else:
    print("맞춘 숫자는", end=' ')
    for i in range(len(result)):
        print(f'{result[i]}', end=', ')
    print('로 당첨되었습니다.!')
    print(f'맞춘 숫자수: {len(result)}')



    
    
