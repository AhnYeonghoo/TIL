n,l = map(int,input().split())

answer= -1
S_l = 0
answer_l = 0

for length in range(l,101):
    S_l = (length*(length-1))/2
    if((n-S_l)%length==0 and (n-S_l)//length >=0):
        answer = (n-S_l)//length
        answer_l = length
        break
answer = int(answer)
if(answer==-1):
    print(-1)
else:
    for i in range(answer,answer+answer_l):
        print(i,end=" ")
    print()