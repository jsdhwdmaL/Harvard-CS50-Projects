from cs50 import get_int
#input
height = get_int("Height: ")
while height < 1 or height > 8:
    height = get_int("Height: ")


#print
for i in range(1, height + 1):
    for j in range (0, height - i):
        print(" ", end="")
    for x in range(1, i + 1):
        print("#", end="")
    print("  ", end="")
    for y in range(1, i + 1):
        print("#", end="")
    print("\n", end="")
