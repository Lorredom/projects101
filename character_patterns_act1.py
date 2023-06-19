""" CPTTRN1 from spoj.com
    Function takes 3 inputs: t - number of data sets; L - number of lines; C - number of columns
    Prints a chessboard-like pattern"""
    
def char_patterns():
    
    L, C = map(int, input().split())
    for j in range(L):
        
        line = ""
        for k in range(C):
             
            # if odd line (line 1, 3, 5...)
            if j % 2 != 0:
            	# if odd column in odd line (col 1, 3, 5...)
                if k % 2 != 0:
                    line += "*"
                # if even column in odd line (col 0, 2, 4...)
                else:
                    line += "."
                    
            # if even line (line 0, 2, 4...)      
            else:
            	# if odd column in even line (col 1, 3, 5...)
                if k % 2 != 0:
                    line += "."
                # if even column in even line (col 0, 2, 4...)
                else:
                    line += "*"
                
        print(line, end="\n")
        
    return line
    
    
    
t = int(input())
for _ in range(t):
    char_patterns()
    print("\n") 