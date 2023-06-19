""" CPTTRN5 from spoj.com
	Program takes the following inputs: t times it runs 
	and for each t:
		the number of lines L
		the number of columns C
		the width and height of the grid, equal here, S (size)
    (4 input variables total)
	Prints diagonals alternatingly, according to the example"""
 
t = int(input())
 
for _ in range(t):
	L, C, S = map(int, input().split())
	
	for line in range(L):
		if line == 0:
			for column in range(C):
				print("*", end="")
				for width in range(S):
					print("*", end="")
			print("*")
			
		
		if line%2 == 0:
			for height in range(S):
				for column in range(C):
					print("*", end="")
					for width in range(S):
						if C==1 and S==1:
							print("\\", end="")
						if C==1 and S>1:
							if width == height:
								print("\\", end="")
							else:
								print(".", end="")
						if C>1 and S==1:
							if column%2 == 0:
								print("\\", end="")
							if column%2 != 0:
								print("/", end="")
						if C>1 and S>1:
							if column%2 == 0:
								if width == height:
									print("\\", end="")
								else:
									print(".", end="")
							if column%2 != 0:
								if width == (S-(height+1)):
									print("/", end="")
								else:
									print(".", end="")
				print("*")
			
			for column in range(C):
				print("*", end="")
				for width in range(S):
					print("*", end="")
			print("*")
					
		if line%2 != 0:
			for height in range(S):
				for column in range(C):
					print("*", end="")
					for width in range(S):
						if C==1 and S==1:
							print("/", end="")
						if C==1 and S>1:
							if width == (S-(height+1)):
								print("/", end="")
							else:
								print(".", end="")
						if C>1 and S==1:
							if column%2 == 0:
								print("/", end="")
							if column%2 != 0:
								print("\\", end="")
						if C>1 and S>1:
							if column%2 == 0:
								if width == (S-(height+1)):
									print("/", end="")
								else:
									print(".", end="")
							if column%2 != 0:
								if width == height:
									print("\\", end="")
								else:
									print(".", end="")
				print("*")
			
			for column in range(C):
				print("*", end="")
				for width in range(S):
					print("*", end="")
			print("*")
	print("\n")