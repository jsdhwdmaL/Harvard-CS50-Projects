num = int(input("Number: "))
tmp = num
sum = 0
while tmp > 0:
    mod = tmp % 100
    t = mod
    tmp = int(tmp / 100)
    mod = int(mod / 10)
    mod = mod * 2
    while mod > 0:
        sum = sum + mod % 10
        mod = int(mod / 10)
    sum = sum + t % 10
#print(sum)
digit = 0;
tmp2 = num;
while tmp2 > 0:
    digit = digit + 1
    tmp2 = int(tmp2 / 10)

if sum % 10 != 0:
    print("INVALID\n")
else:
    #print("Hi\n")
    if digit == 15:
        if int(num / 10000000000000) == 34 or int(num / 10000000000000) == 37:
            print("AMEX\n")
        else:
            print("INVALID\n")
    elif digit == 13:
        if int(num / 1000000000000) == 4:
            print("VISA\n")
        else:
            print("INVALID\n")
    elif digit == 16:
        if int(num / 100000000000000) >= 51 and int(num / 100000000000000) <= 55:
            print("MASTERCARD\n")
        elif int(num / 1000000000000000) == 4:
            print("VISA\n")
        else:
            print("INVALID\n")
    else:
        print("INVALID\n")