from typing import List

def sortPeople(names: List[str], heights: List[int]) -> List[str]:
    my_dict = {}
    n = len(names)
    for i in range(len(names)):
        my_dict[heights[i]] = names[i]

    my_dict = dict(sorted(my_dict.items()))
    for i in range(len(names)):
        names[n - i - 1] = list(my_dict.values())[i]

    return names