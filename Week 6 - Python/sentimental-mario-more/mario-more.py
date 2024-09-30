from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

for i in range(n):
    for j in range(n + i + 3):
        if (j == n or j == n + 1 or i + j < n - 1):
            print(" ", end="")
        else:
            print("#", end="")
    print()
