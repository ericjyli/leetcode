from typing import List

def countStudents(students: List[int], sandwiches: List[int]) -> int:
    num = len(students)
    count = 0
    not_want = 0
    
    while (len(students) != 0):
        if students[0] == sandwiches[0]:
            count += 1
            not_want = 0
            students.pop(0)
            sandwiches.pop(0)
        else:
            not_want += 1
            students.append(students.pop(0))
            if not_want == len(students):
                break
        
    return num - count
