import pandas as pd 

import requests
import random
from tqdm import tqdm

_input = list(input().split())

def getLottoWinInfo(startRound, endRound):
    
    drwtNo1 = [] 
    
    drwtNo2 = [] 
    
    drwtNo3 = [] 
    
    drwtNo4 = [] 
    
    drwtNo5 = [] 
    
    drwtNo6 = [] 
    
    bnusNo = [] 
    
    for i in tqdm(range(startRound, endRound+1, 1)): 
        
        # i = 1
        
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
        
    return lotto_dict, lotto_df


startRound = 930

endRound = 990

lotto_dict, lotto_df = getLottoWinInfo(startRound, endRound)

array=lotto_df.values


# 기존 당첨번호에서 한 행씩 저장

legecy = list()
for i in range(len(array)):
    legecy.append(list(array[i]))

# 레거시에 현재 기존 당첨번호 한 행씩 저장되어 있음.

result = list()
for i in range(len(array)):
    for j in range(len(_input)):
        if int(legecy[i][j]) == int(_input[j]):
            result.append(legecy[i][j])

당첨 = list()
당첨.append(result[0:7])
당첨.append(result[7:14])
당첨.append(result[14:21])

print(당첨)
        




    
 









#조건문쓰기. 마지막 거는 자릿수 1개 또는 2개 해서 if로 구분해주기.