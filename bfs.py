graph = {
    "a" : ["b", "d"],
    "b": [],
    "c": [],
    "d": ["e", "g"],
    "e": ["c"],
    "f": [],
    "g": ["f"]
}

def bfs(graph, sourceNode):
    queue = []
    queue.append(sourceNode)

    while queue:
        dequeued = queue.pop(0)
        print(dequeued)
        for neighbour in graph[dequeued]:
            queue.append(neighbour)

bfs(graph, "a")