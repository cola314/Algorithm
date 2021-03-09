d=-int(input())+int(input())
c=0
if 1 <= d <= 20:
    c=100
elif 21 <= d <= 30:
    c=270
elif 31 <= d:
    c=500

if c == 0:
    print("Congratulations, you are within the speed limit!")
else:
    print(f'You are speeding and your fine is ${c}.')

