N=int(input())
cnt=0
for i in range(N):
    word = input()  
    bl_=True
    for j in range(len(word)-1):
        if word[j]!=word[j+1]:
            if word[j] in word[j+1:]:
                bl_=False
                break
    if bl_:
        cnt+=1
print(cnt)