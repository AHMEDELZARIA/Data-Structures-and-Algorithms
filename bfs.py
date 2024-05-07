from collections import deque

def bfs_shortest_path(graph, source_node, target_node):
    # Initialize the queue with the source node and mark it visited
    queue = deque([(source_node, [source_node])])  # Stores (node, path to node)
    visited = set([source_node])

    while queue:
        current_node, path = queue.popleft()

        # Check if we've reached the target node
        if current_node == target_node:
            return path  # Return the path to the target node

        # Explore the neighbors of the current node
        for neighbor in graph[current_node]:
            if neighbor not in visited:
                visited.add(neighbor)  # Mark the neighbor as visited
                # Enqueue the neighbor along with the path to reach it
                queue.append((neighbor, path + [neighbor]))

    return "Path does not exist"

graph = {
    'a': ['b', 'c'],
    'b': ['a', 'd', 'e'],
    'c': ['a', 'f'],
    'd': ['b'],
    'e': ['b', 'f'],
    'f': ['c', 'e']
}

# Example usage
source_node = "a"
target_node = "f"
path = bfs_shortest_path(graph, source_node, target_node)
print("Shortest path from", source_node, "to", target_node, ":", path)