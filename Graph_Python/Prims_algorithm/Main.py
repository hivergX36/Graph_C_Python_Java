import re 
import Prim 

Prim = Prim.Prim()
Prim.parse_graph("data.txt")
Prim.display_graph()
Prim.resolve()
Prim.display_path() 