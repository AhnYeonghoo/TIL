age = int(input("나이를 입력하세요: "))
if age >= 20:
    print("성인은 15,000원 입니다.")
    price = 15000
else:
    print("미성년자는 6,000원 입니다.")
    price = 6000

price_input = int(input("입장료를 넣어주세요 --> "))
if price_input < price:
    print(f"{price-price_input} 원을 더 내야 합니다.")
else:
    print(f"{price_input-price} 원을 거슬러 드리겠습니다.")


price = int(input("구매금액은? "))
if price<20000:
    print("주문 금액이 부족합니다.")
elif price < 50000:
    print("배송비 2500원이 추가됩니다.")
else:
    print("무료배송됩니다.")
print(f"최종결제 금액은 {price}입니다.")

date = int(input("오늘은 며칠입니까? "))
if date > 31:
    print("올바른 날짜를 입력하세요.")
elif date % 2 == 1:
    print("홀수번호 차량만 통행 가능합니다.")
else:
    print("짝수번호 차량만 통행 가능합니다.")
    
