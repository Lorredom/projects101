"""BFN1 from pl.spoj.com"""
t = int(input())
 
# For each integer returns an integer with a reversed digit-order
def palindrome_search(n):
    rev_n = int(str(n)[::-1])
    return rev_n
 
 
# Loops t times requesting input n, runs then loops palindrome_search over each n, until rev_n and n are equal
for _ in range(t):
    n = int(input())
    rev_n = palindrome_search(n)
    i = 0
    while n != rev_n:
        new_n = n + rev_n
        rev_n = palindrome_search(new_n)
        n = new_n
        i += 1
    print(rev_n, i, end=" ")