import re 
import Djikstra

Djikstra = Djikstra.Djikstra()
Djikstra.parse_graph("data01.txt")
Djikstra.display_graph()
Djikstra.resolve()
Djikstra.display_path() 