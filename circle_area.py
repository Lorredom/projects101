"""ETI06F1 from pl.spoj.com"""
from math import sqrt as root
 
def calc_circle_area(r, d):  # r to promieÅ sfery, d to odlegÅoÅÄ miÄdzy
                              # Årodkami dwÃ³ch sfer o tych samych r, d<2r
    squared_x = pow(r, 2) - pow((d / 2), 2)
    x = root(squared_x)
    result = 3.141592654 * pow(x, 2)
    return result
 
 
r, d = map(float, input().split())
 
circle_area = round(calc_circle_area(r, d), 3)
print(circle_area) 