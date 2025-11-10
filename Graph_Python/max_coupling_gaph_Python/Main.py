import Max_coupling_graph
import re 

max_coupling_graph = Max_coupling_graph.Max_Coupling_Graph()
max_coupling_graph.parse_graph("data.txt")
max_coupling_graph.display_graph()
max_coupling_graph.Solve()
max_coupling_graph.display_solution()