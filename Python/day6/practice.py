def profile(name, age, lang1, lang2, lang3, lang4, lang5):
    print("이름: {0}\t 나이: {1}\t".format(name, age), end=" ")
    print(lang1, lang2, lang3, lang4, lang5)

print("유재석", 20, "python", 'java', 'c', 'c++', 'c#')
print('김태호', 25, 'kotlin', 'swift',"", "", "")

def profile_two(name, age, *language):
    print(f"이름: {name}\t 나이: {age}", end=" ")
    for i in language:
        print(i, end=" ")
    print()
    
print("유재석", 20, "python", 'java', 'c', 'c++', 'c#', 'javascript')
print('김태호', 25, 'kotlin', 'swift')

gun = 10
def checkpoint(soldiers):
    gun = 20
    gun = gun - soldiers
    print("[함수 내] 남은 총: {0}".format(gun))

print("전체 총: {0}".format(gun))
checkpoint(2)
print("전체 총: {0}".format(gun))