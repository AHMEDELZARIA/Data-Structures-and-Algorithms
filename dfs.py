graph = {
    "a" : ["b", "d"],
    "b": [],
    "c": [],
    "d": ["e", "g"],
    "e": ["c"],
    "f": [],
    "g": ["f"]
}

def dfs(graph, source_node):
    stack = []
    stack.append(source_node)
    while stack:
        popped = stack.pop(-1)
        print(popped)
        for neighbour in graph[popped]:
            stack.append(neighbour)

dfs(graph, "c")
