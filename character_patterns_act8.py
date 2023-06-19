""" CPTTRN8 from spoj.com
	Program takes the following inputs: t, the test cases number
	and for each t:
		the number of rows R
		the number of columns C
		the size of the 'diamond' S
    (amounting to 4 input variables)
	Prints a regular grid pattern with diamond-like base elements. *Inner part of diamonds and outer space differ"""

t =  int(input())
 
for _ in range(t):
	R, C, S = map(int, input().split())
	
	for row in range(R):
		for size_top in range(S):
			for column in range(C):
				if size_top == 0:
					for size_left in range(S):
						if size_top != S-(size_left+1):
							print(".", end="")
						else:
							print("/", end="")
					for size_right in range(S):
						if size_top != size_right:
							print(".", end="")
						else:
							print("\\", end="")
				else:
					for size_left in range(S):
						if size_top == S-(size_left+1):
							print("/", end="")
						elif size_top < S-(size_left+1):
							print(".", end="")
						else:
							print("*", end="")
					for size_right in range(S):
						if size_top == size_right:
							print("\\", end="")
						elif size_top < size_right:
							print(".", end="")
						else:
							print("*", end="")
			print("\n")
		for size_bottom in range(S):
			for column in range(C):
				if size_bottom == S-1:
					for size_left in range(S):
						if size_bottom != size_left:
							print(".", end="")
						else:
							print("\\", end="")
					for size_right in range(S):
						if size_bottom != S-(size_right+1):
							print(".", end="")
						else:
							print("/", end="")
				else:
					for size_left in range(S):
						if size_bottom == size_left:
							print("\\", end="")
						elif size_bottom < size_left:
							print("*", end="")
						else:
							print(".", end="")
					for size_right in range(S):
						if size_bottom == S-(size_right+1):
							print("/", end="")
						elif size_bottom < S-(size_right+1):
							print("*", end="")
						else:
							print(".", end="")
					
			print("\n") 