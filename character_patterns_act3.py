""" CPTTRN3 from spoj.com
    Function takes 3 inputs: t - number of test cases; L - number of lines; C - number of columns
    Prints a grid-like pattern"""

t = int(input())
 
for _ in range(t):
	L, C = map(int, input().split())
	for i in range(L):
		for x in range(3):
			for j in range(C):
				if x == 0:
					print("***", end="")
					if j == C-1:
						print("*")
				else:
					print("*..", end="")
					if j == C-1:
						print("*")
		if i == L-1:
			for j in range(C):
				print("***", end="")
				if j == C-1:
					print("*")
	print("\n") 