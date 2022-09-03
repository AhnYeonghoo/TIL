
def std_weight(height, gender):
    weight = 0
    if gender == 'man':
        weight = height * height * 22
        weight = round(weight,2)
        print(f"표준 체중은 {weight}입니다.")
    elif gender ==  'woman':
        weight = height * height * 21
        weight = round(weight, 2)
        print(f"표준 체중은 {weight}입니다.")
    else:
        print('not human')
    

print(std_weight(175 / 100, 'man'))
