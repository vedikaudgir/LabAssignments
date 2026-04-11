def has_cycle(graph):
    visited = set()       
    recursionStack = set()
    def dfs(node):
        if node in recursionStack:
            return True
        if node in visited:
            return False

        recursionStack.add(node)
        for neighbor in graph.get(node, []):
            if dfs(neighbor):
                return True
        recursionStack.remove(node)
        visited.add(node)
        return False


    for node in graph:
        if dfs(node):
            return True
    
    return False

graph = { 'A': {'B', 'C'}, 'B': {'D'}, 'C': {'D'}, 'D': {'E'}, 'E': set()}
print(has_cycle(graph))