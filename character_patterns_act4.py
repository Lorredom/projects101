""" CPTTRN4 from spoj.com
    Function takes 5 inputs: t - number of test cases; L - number of lines; C - number of columns; 
	H - hight and W - width (of a single rectangle)
    Prints a grid-like pattern"""

t = int(input())
 
for _ in range(t):
	L, C, H, W = map(int, input().split())
	
	for a in range(L):
	
		if a == 0:
			for b in range(C):
				print("*", end="")
				
				for d in range(W):
					print("*", end="")
			print("*")
 
		for c in range(H):	
			
			for b in range(C):
				print("*", end="")
				for d in range(W):
					print(".", end="")
			print("*")
	
		for b in range(C):
			print("*", end="")
			
			for d in range(W):
				print("*", end="")
		print("*")
	print("\n") 