#!/usr/bin/python3

def isPalindrome(n):
    string = str(n)
    return string == string[::-1]


if __name__ == "__main__":
    max = (0, 0)
    for i in range(100, 1000):
        for j in range(i, 1000):
            if (isPalindrome(i*j) and i * j > max[0] * max[1]):
                max = (i, j)
    print(f"{max[0] * max[1]} = {max[0]} x {max[1]}")
