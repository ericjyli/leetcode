from typing import List



def groupAnagrams(strs: List[str]) -> List[List[str]]:
    '''
    Example 1:

    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    groupAnagrams(["eat","tea","tan","ate","nat","bat"])
    >>> [["bat"],["nat","tan"],["ate","eat","tea"]]
    
    Example 2:

    Input: strs = [""]
    Output: [[""]]
    Example 3:

    Input: strs = ["a"]
    Output: [["a"]]
    '''
    
    
    res_map = {}
    for i in range (len(strs)):
        temp_str = ''.join(sorted(strs[i]))
        if temp_str in res_map:
            res_map[temp_str].append(strs[i])
        else:
            res_map[temp_str] = [strs[i]]
            
    res = []
    for keys in res_map:
        res.append(res_map[keys])
        
    return res

if __name__ == '__main__':
    groupAnagrams(["eat","tea","tan","ate","nat","bat"])
    print('a')