from collections import defaultdict
import re 

class Djikstra:

    def __init__(self):
        self.NbVertices = 0
        self.NbEdges = 0
        self.adjacency_list = {}
        self.adjacency_Matrix = []
        self.path = []
        self.cost = []
        self.visited = []
        self.shortest_path = []
        self.min_cost = 0 
    
            
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
            
            
    def resolve(self):
        current_vertex = 0
        prec = 0 
        cost_succ = 0 
        cost_prec = 0
        self.path = [None for i in range(self.NbVertices)]
        self.cost = [float('inf') for i in range(self.NbVertices)]
        self.cost[0] = 0
        fifo = [0]
        while len(fifo) > 0:
            vertex = fifo.pop()
            self.visited[vertex] = True
            print("Processing vertex:", vertex)
            print("Current cost:", cost_succ)
            for succ, weight in self.adjacency_list[vertex]:
                if self.visited[succ] == True:
                    break
                fifo.append(succ)
                cost_succ = self.cost[succ]
                cost_prec = self.cost[vertex]
                print(f"Checking edge {vertex} -> {succ} with weight {weight}")
                if cost_prec + weight  < cost_succ:
                    cost_succ = cost_prec + weight
                    print(f"Updating cost for vertex {succ} to {cost_succ}")
                    self.path[succ] = vertex
                    self.cost[succ] = cost_succ
                    
    def calculate_shortest_path(self):
        prec = self.path[-1]
        while prec is not None:
            self.shortest_path.append(prec)
            current_vertex = self.path[prec]
            self.shortest_path.reverse()
            self.min_cost = sum(self.cost[i] for i in self.shortest_path)



    def display_path(self):
        print("path predecessors:", self.path)
        print("Path:", self.shortest_path)
        print("Cost:", self.cost)
        print("Minimum cost:", self.min_cost)