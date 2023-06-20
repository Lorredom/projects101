"""Function returns n-th number in the Fibonacci string"""
def fib(n):
    # return allowes the program to continue despite errors, prints out prepared message
    # raise crashes the program at first error occurence, exit code 0
    if n <= 0:
        return ValueError("Choose 1 or a higher number")
        # raise ValueError("Choose 1 or a higher number")
    if n == 1 or n == 2:
        return 1
    else:
        a = 1
        b = 1
        i = n - 3
        while i:
            # temp = b
            # b = a + b
            # a = temp
            # or
            a, b = b, a+b
            i -= 1
    return a + b

try:
    print(fib(8))
    print(fib(0))
    print(fib(-8))
    print(fib(5))
except ValueError as e:
    print(f"Error occured: {e}")