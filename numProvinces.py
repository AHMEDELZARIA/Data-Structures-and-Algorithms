graph = {
    1: [3,7],
    2: [],
    3: [1,7],
    4: [9],
    5: [8,10],
    6: [8,10],
    7: [1,3],
    8: [5,6],
    9: [4],
    10: [5,6]
}

vis = set()
def dfs(graph,src):
    queue = []
    queue.append(src)
    vis.add(src)
    while queue:
        queue.pop(0)
        for nb in graph[src]:
            dfs(graph, nb)

def numProv(graph):
    num = 0
    for key in graph.keys():
        if key not in vis:
            dfs(graph, key)
            num+=1
    
    return num
    
print(numProv(graph))

