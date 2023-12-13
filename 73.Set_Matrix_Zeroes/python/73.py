from typing import List

def setZeroes(matrix: List[List[int]]) -> None:
    """
    Do not return anything, modify matrix in-place instead.
    """
    row_dict = {}
    col_dict = {}

    for i in range (len(matrix)):
        for j in range (len(matrix[i])):
            if matrix[i][j] == 0:
                row_dict[i] = 1
                col_dict[j] = 1

    for row in row_dict:
        for i in range(len(matrix[row])):
            matrix[row][i] = 0

    for col in col_dict:
        for i in range (len(matrix)):
            matrix[i][col] = 0
