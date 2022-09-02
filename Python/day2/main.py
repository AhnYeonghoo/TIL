print("Welcome to the tip calculator.")
bill = float(input("What was the total bil? "))
people = int(input("How many people to split the bill? "))
percentage = int(input("What percentage tip would you like to give? 10, 12, or 15? "))
result = bill  / people + ((bill /people)* percentage * 0.01)

print(f"Each person should pay: ${round(result, 1)}")