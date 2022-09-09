s = input()

def distance(s,t,c1,c2):
    return abs(s-c1)+abs(c1-c2)+abs(t-c2)

length, last_index = len(s), -1
min_idx, max_idx = [-1 for _ in range(26)], [-1 for __ in range(26)]
for i in range(26):
    al = chr(97 + i)
    min_idx[i] = s.find(al)
    max_idx[i] = s.rfind(al)

first_row = True
dp = [[0 for _ in range(length)] for __ in range(26)]
for i in range(26):
    if min_idx[i] == -1:
        continue
    if first_row:
        for j in range(length):
            dp[i][j] = distance(0,j,min_idx[i],max_idx[i])
        first_row = False
        last_index = i
        continue
    for j in range(length):
        for k in range(length):
            min_distance = min(distance(k,j,min_idx[i],max_idx[i]),distance(k,j,max_idx[i],min_idx[i]))
            if dp[i][j]:
                dp[i][j] = min(dp[i][j],dp[last_index][k]+min_distance)
            else:
                dp[i][j] = dp[last_index][k]+min_distance
    last_index = i

print(min(dp[last_index])+length) 