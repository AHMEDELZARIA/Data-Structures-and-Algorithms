graph = {
    "a" : ["b", "d"],
    "b": [],
    "c": [],
    "d": ["e", "g"],
    "e": ["c"],
    "f": [],
    "g": ["f"]
}

def hasPath(graph, src, dst):
    if src == dst:
        return True
    
    ans = False
    for neighbour in graph[src]:
        ans = ans or hasPath(graph, neighbour, dst)
    
    return ans

src, dst = input().split()
print(hasPath(graph,src,dst))
