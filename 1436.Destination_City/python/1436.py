from typing import List

def destCity(paths: List[List[str]]) -> str:
    city_path = {}
    for i in range (len(paths)):
        city_path[paths[i][0]] = paths[i][1]
        
    for city in city_path:
        destination = city_path[city]
        if not destination in city_path:
            return destination