""" CPTTRN6 from spoj.com
    Function takes 5 inputs: t - number of test cases; L - number of lines; C - number of columns; 
	H - hight and W - width (of a single rectangle)
    Prints a grid-like pattern with crossings"""

t = int(input())
 
for _ in range(t):
	L, C, H, W = map(int, input().split())
	
	for line in range(L):
		if line == 0:
			for height in range(H):
				for verticals in range(C):
					for width in range(W):
						print(".", end="")
					print("|", end="")
				for width in range(W-1):
					print(".", end="")
				print(".")
		
		for verticals in range(C):
			for width in range(W):
				print("-", end="")
			print("+", end="")
		for width in range(W-1):
			print("-", end="")
		print("-")	
			
		for height in range(H):
			for verticals in range(C):
				for width in range(W):
					print(".", end="")
				print("|", end="")
			for width in range(W-1):
					print(".", end="")
			print(".")
	print("\n") 