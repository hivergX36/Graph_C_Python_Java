import java.util.ArrayDeque;
import java.util.Queue;

public class Prims extends Graph {
    Path path; 



    Prims(String name) {
        super(name);
        path = new Path(this.NbVertices);
        int chemin[] = new int[this.NbVertices];
        Boolean mark[] = new Boolean[this.NbVertices];
        Float distance[] = new Float[this.NbVertices];
        ;
        for (int i = 0; i < chemin.length; i++) {

            chemin[i] = 0;
            mark[i] = false;
            distance[i] = Float.MAX_VALUE;
        }
        this.path.path = chemin;
        this.path.cost = distance;
    }

    // Il y'a un problème de marquage

    public void resolve() {
        Queue<Integer> Queue = new ArrayDeque<>();
        for(int i = 0; i < this.NbVertices; i++){
            Queue.add(i);
        } 
        float neighbourValue;
        int visited_point;
        while (Queue.size() > 0) {
            visited_point = Queue.remove();
            for (int j = 0; j < this.NbVertices; j++) {
                neighbourValue = this.AdjacencyMatrix[visited_point][j];
                if (neighbourValue > 0) {
                    Queue.add(j);
                    if (neighbourValue < this.path.cost[j]) {
                        this.path.cost[j] =  neighbourValue;
                        this.path.path[j] = visited_point;
                    }
                }
            }
        }

    }

    public void displayPath() {
        System.out.println("Le graph est: ");
        displayGraph();
        System.out.println("La solution est: ");

        for (int i = 0; i < this.NbVertices; i++) {
            System.out.println(this.path.path[i]);

        }
    }
}