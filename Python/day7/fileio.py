f = open('new_file.txt', 'w')
for i in range(1, 11):
    data = f"{i}st line.\n"
    f.write(data)

f.close()

f = open('new_file.txt', 'a')
line = f.readlines()
for i in range(len(line)):
    print(line[i], end=' \n')


print()

while True:
    line = f.readline()
    if not line: break
    print(line)
f.close()
lines = f.readlines()
for line in lines:
    line = line.strip()
    print(line)
f.close()

data = f.read()
print(data)
f.close()
for i in range(11, 20):
    data = f"{i}st line.\n"
    f.write(data)
f.close()

f = open('foo.txt', 'w')
f.write('Life is too short, you need python')
f.close()
f = open('too.txt', 'w')

with open('too.txt', 'w') as f:
    f.write("Life is too short, you need python")
