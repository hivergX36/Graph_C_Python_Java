import Edmonds_Karp
import re 

edmonds_karp = Edmonds_Karp.Edmonds_Karp()
edmonds_karp.parse_graph("data.txt")
edmonds_karp.display_graph()
edmonds_karp.solve()
edmonds_karp.display_solution()