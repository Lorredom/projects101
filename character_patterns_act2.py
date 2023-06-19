""" CPTTRN2 from spoj.com
    Function takes 3 inputs: t - number of data sets; L - number of lines; C - number of columns
    Prints a frame-like pattern"""

    
def char_patterns():
    
    L, C = map(int, input().split())
    if L >= 3 and C >= 3:
        for j in range(L):
        
            line = ""
            for k in range(C):
             
                # if first or last line)
                if j == 0 or j == L-1:
            	    line += "*"
                    
                    
                # if middle lines     
                else:
            	    # if first or last character in given line)
                    if k == 0 or k == C-1:
                        line += "*"
                    # if middle characters in given line
                    else:
                        line += "."
                
            print(line, end="\n")
    
    # if lines or columns less than 3, no middle characters
    else:
        for j in range(L):
            line = ""
            for k in range(C):
                line += "*"
            print(line, end="\n")
        
    return line
    
    
def call_char_patterns():
    t = int(input())
    for _ in range(t):
        char_patterns()
        print("\n")
 
call_char_patterns() 