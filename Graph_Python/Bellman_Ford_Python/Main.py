import re 
import BellmanFord 

BellmanFord = BellmanFord.BellmanFord()
BellmanFord.parse_graph("data02.txt")
BellmanFord.display_graph()
BellmanFord.resolve()
BellmanFord.display_path() 