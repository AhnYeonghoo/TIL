import sys
print("Python", "Java")
print("Python"+"Java")
print("Python","Java", sep=", ")
print("Python", "Java", sep=" vs ")
print("Python", "Java", "JavaScript", sep=" vs " )
print("Python", "Java", sep=",", end="?")
print()
print()
print("Python", "Java", file=sys.stdout) # 표준출력
print("Python", "Java", file=sys.stderr) # 표준에러

scores = {"수학":0, "영어": 50, "코딩": 100}
for subject, score in scores.items():
    # print(f"{subject}의 점수는 {score}입니다.", end=", ")
    print(f"{subject.ljust(8)}의 점수는 {str(score).rjust(4)}입니다.")
    
print()
print()

for num in range(1, 21):
    print(f"대기번호: {str(num).zfill(3)}")

    
answer = input("아무 값이나 입력하세요: ")
print(type(answer))

