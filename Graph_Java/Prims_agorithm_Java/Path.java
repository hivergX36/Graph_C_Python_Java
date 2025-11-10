public class Path {
    int NbVertices;
    int[] path;
    Float[] cost;

    Path(int NbVertices) {
        this.NbVertices = NbVertices;
        this.path = new int[NbVertices];
        this.cost = new Float[NbVertices];
    }
}
