
public class Path {
    int NbVertices;
    int[] path;
    Float[] cost;
    boolean[] visited; 
    boolean isnegativeCycle;

    Path(int NbVertices) {
        this.NbVertices = NbVertices;
        this.path = new int[NbVertices];
        this.cost = new Float[NbVertices];
        this.visited = new boolean[NbVertices];
        this.isnegativeCycle = false;
    }
}
