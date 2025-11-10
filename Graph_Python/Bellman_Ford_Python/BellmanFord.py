from collections import defaultdict
import re 

class BellmanFord:

    def __init__(self):
        self.NbVertices = 0
        self.NbEdges = 0
        self.adjacency_list = {}
        self.adjacency_Matrix = []
        self.path = []
        self.cost = []
        self.negative_cycle = False  
        self.visited = []
        
    
            
    def parse_graph(self,text):
        fichier = open(text, "r",encoding="utf8")
        lines = fichier.readlines()
        lines = [line.strip() for line in lines if line.strip() != " "]
        lines = [line.strip(",number of verticesedges''"": \n") for line in lines ]
        lines = [line.strip() for line in lines if line.strip() != "''"]
        lines = [[int(x) for x in lines[i].split(' ')] for i in range(len(lines)) if lines[i] != ""]
        self.NbVertices = lines[0][0]
        self.NbEdges = len(lines) - 1
        self.adjacency_list = defaultdict(list)
        self.adjacency_Matrix = [[0 for i in range(self.NbVertices)] for j in range(self.NbVertices)]
        for i in range(1, len(lines)):
            u, v, w = lines[i]
            self.adjacency_list[u].append((v, w))
            self.adjacency_Matrix[u][v] = w
    
    def display_graph(self):
        print("Number of vertices:", self.NbVertices)
        print("Number of edges:", self.NbEdges)
        print("Adjacency List:")
        for pred, succ in self.adjacency_list.items():
            print(f"{pred}: {succ}")
        print("Adjacency Matrix:")
        for row in self.adjacency_Matrix:
            print(row)
            
            
    def resolve(self):
        cost = 0 
        self.path = [None for i in range(self.NbVertices)]
        self.cost = [float('inf') for i in range(self.NbVertices)]
        self.cost[0] = 0  # Assuming the source vertex is 0
        for i in range(self.NbVertices - 1):
            for j in range(self.NbVertices):
                vertex = j 
                for succ, weight in self.adjacency_list[vertex]:
                    cost = self.cost[succ]
                    print(f"Checking edge {vertex} -> {succ} with weight {weight}")
                    if self.cost[vertex] + weight < cost:
                        cost = self.cost[vertex] + weight
                        print(f"Updating cost for vertex {succ} to {cost}")
                        self.path[succ] = vertex
                        self.cost[succ] = cost
                        
                        
        # Check for negative weight cycles
        for j in range(self.NbVertices):
            vertex = j 
            for succ, weight in self.adjacency_list[vertex]:
                if self.cost[vertex] + weight < self.cost[succ]:
                    print(f"Negative cycle detected on edge {vertex} -> {succ} with weight {weight}")
                    self.negative_cycle = True
                    return

    def display_path(self):
        print("Path:", self.path)
        print("Cost:", self.cost)