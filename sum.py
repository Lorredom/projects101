"""SUMA form pl.spoj.com"""

lst = []
downloading = True
while downloading:
    try:
        lst.append(int(input()))
    except EOFError:
        downloading = False
        break
 
for i, number in enumerate(lst):
    if i == 0:
        print(number)
        continue
    if i > 0:
        a = sum(lst[:i+1])
        print(a)
        i += 1 