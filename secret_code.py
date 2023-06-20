"""AL_10_01 from pl.spoj.com"""
t = int(input())
for _ in range(t):
    lst = input().split()
    x = lst[1]
    if x[0] != "?":
        n = sum(char == "?" for char in x)
        result = 10 ** n
        print(result)
    else:
        x = list(x)
        x.pop(0)
        if not x:
            result = 10
        else:
            q = 9
            n = sum(char == "?" for char in x)
            result = (10 ** n) * q
        print(result)