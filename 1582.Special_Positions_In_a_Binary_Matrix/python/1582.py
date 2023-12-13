from typing import List


def numSpecial(mat: List[List[int]]) -> int:
    row_dict = {}
    col_dict = {}
    count = 0
    
    for i in range (len(mat)):
        for j in range (len(mat[i])):
            if mat[i][j] == 1:
                if i in row_dict:
                    row_dict[i] += 1
                else:
                    row_dict[i] = 1
                if j in col_dict:
                    col_dict[j] += 1
                else:
                    col_dict[j] = 1
                    
    for i in range (len(mat)):
        for j in range (len(mat[i])):
            if (mat[i][j] == 1 and row_dict[i] == 1 and col_dict[j] == 1):
                count += 1
    return count

if __name__ == '__main__':
    mat1 = [[0,0,0,0,0,1,0,0],
            [0,0,0,0,1,0,0,1],
            [0,0,0,0,1,0,0,0],
            [1,0,0,0,1,0,0,0],
            [0,0,1,1,0,0,0,0]]
    print(f"res1: {numSpecial(mat1)}") # should be 1
    