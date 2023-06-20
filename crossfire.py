"""ETI06F3 from pl.spoj.com"""
from  collections import Counter
n = int(input())
 
students_friends = []
for i in range(n):
    student = input()
    students_friends.append(student)
friend_book = Counter(students_friends)
 
if len(set(students_friends)) % 3 == 0:
    teams = sorted(friend_book.values())
    num_of_teammates = " ".join(str(team) for team in teams)
    print("TAK", num_of_teammates)
 
else:
    print("NIE") 