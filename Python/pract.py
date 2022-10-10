height = 5; i=1
d = False
while (i>=1) :
  for j in range(height-i) :
    print(' ', end='')
  print('*', '-'*(i-1), sep='')
  if (i > height/2) : d = True
  i = i-1 if d else i+1

a = []
a.append(10)
a.append(20)
a.append(30)
print(a)
a.append([100, 200])
print(a)
a = [0, 1, 2]
for i in a:
    print(i)
    if i == 0 : a.append(3)
    print(i)
