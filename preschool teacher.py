"""PRZEDSZK from pl.spoj.com"""
# This function computes GCD
def compute_gcd(x, y):
   while(y):
       x, y = y, x % y
   return x
 
# This function computes LCM
def compute_lcm(x, y):
    lcm = (x*y)//compute_gcd(x,y)
    return lcm
 
N = int(input())
for _ in range(N):
    a, b = map(int, input().split())
    lcm = compute_lcm(a, b)
    print(lcm) 