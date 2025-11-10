from collections import defaultdict
import re 

class Fold_Fulkerson:

    def __init__(self):
        self.history = []
        self.NbVertices = 0
        self.NbEdges = 0
        self.adjacency_list = {}
        self.adjacency_Matrix = []
        self.path = []
        self.source = 0
        self.sink = 0
        self.max_flow = 0

    def parse_graph(self,text):
        fichier = open(text, "r",encoding="utf8")
        lines = fichier.readlines()
        lines = [line.strip() for line in lines if line.strip() != " "]
        lines = [line.strip(",number of verticesedges''"": \n") for line in lines ]
        lines = [line.strip() for line in lines if line.strip() != "''"]
        lines = [[int(x) for x in lines[i].split(' ')] for i in range(len(lines)) if lines[i] != ""]
        self.NbVertices = lines[0][0]
        self.start = lines[1][0]
        self.sink = lines[len(lines)-1][1]
        print("Start:", self.start)
        print("Sink:", self.sink)
        self.NbEdges = len(lines) - 1
        self.adjacency_list = defaultdict(list)
        self.adjacency_Matrix = [[0 for i in range(self.NbVertices)] for j in range(self.NbVertices)]
        self.visited = [False for i in range(self.NbVertices)]
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

    def Dfs(self, visited,parent, s, sink):
        visited[s] = True
        if s == sink:
            return True
        for v in range(self.NbVertices):
            w = self.adjacency_Matrix[s][v]
            if visited[v] == False and w > 0:
                parent[v] = s
                if self.Dfs(visited, parent, v, sink):
                    return True
        return False
    



    def Fold_Fulkerson(self):
        parent = {}
        self.max_flow = 0

        while True:
            visited = {v: False for v in range(self.NbVertices)}
            parent = {}
            if not self.Dfs(visited, parent, self.start, self.sink):
                break
            flow = float('inf')
            s = self.sink
            while s != self.start:
                flow = min(flow, self.adjacency_Matrix[parent[s]][s])
                s = parent[s]
            self.max_flow += flow
            v = self.sink
            while v != self.start:
                u = parent[v]
                self.adjacency_Matrix[u][v] -= flow
                self.adjacency_Matrix[v][u] += flow
                v = parent[v]



    def display_solution(self): 
        print("Max Flow:", self.max_flow)
        print("Residual Graph:")
        for row in self.adjacency_Matrix:
            print(row)
        return self.max_flow, self.adjacency_Matrix
        
        
       