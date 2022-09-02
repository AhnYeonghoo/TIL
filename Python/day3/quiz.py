a = input("기침이 있습니까? ")
b = float(input("체온을 입력하세요: "))
if a == "Y" and b >= 38.5:
    print("독감일 수 있습니다.")
else:
    print("독감이 아닐 수도 있습니다.")

a = input("김밥 or 라면")
if a == "김밥":
    b = input("야채김밥, 참치김밥 뭐?")
elif a == "라면":
    b = input("기본라면, 떡라면, 만두라면 뭐?")
else:
    print("올바른 메뉴를 입력하세요.")