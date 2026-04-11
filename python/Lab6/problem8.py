#Given a directed graph as an adjacency list (dictionary), where each node points to a set of nodes it connects to, write a function to find all nodes that are reachable from a given node using DFS (Depth First Search).
#E.g. graph = { 'A': {'B', 'C'}, 'B': {'D'}, 'C': {'D'}, 'D': {'E'}, 'E': set()}
#Author - Vedika Udgir

graph = { 'A': {'B', 'C'}, 'B': {'D'}, 'C': {'D'}, 'D': {'E'}, 'E': set()}

def DFS(graph, start):
    visited = set()
    def dfs(node):
        if node not in visited:
            visited.add(node)
            for neighbor in graph.get(node, []):
                dfs(neighbor)
    dfs(start)
    return visited


print(DFS(graph,'A'))