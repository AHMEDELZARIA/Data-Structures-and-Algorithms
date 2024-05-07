graph = {
    "A" : ["B", "D"],
    "B": ["A", "F", "D"],
    "C": ["A"],
    "D": ["B", "G", "I"],
    "E": ["F", "H"],
    "F": ["E", "B"],
    "G": ["D", "H"],
    "H": ["G", "E"],
    "I": ["D"],
}

def hasPath(graph, src, dst):
    if src == dst:
        return True
    vis.add(src)
    ans = False
    for neighbour in graph[src]:
        if neighbour not in vis:
            ans = ans or hasPath(graph, neighbour, dst)
    
    return ans

vis = set()
src, dst = input().split()
print(hasPath(graph,src,dst))
