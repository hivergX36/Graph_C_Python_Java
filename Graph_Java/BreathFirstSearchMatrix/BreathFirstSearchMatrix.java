import java.util.ArrayDeque;
import java.util.Queue;

public class BreathFirstSearchMatrix extends Graph{

    int Chemin[];
    int Distance[];
    Boolean Mark[];


    BreathFirstSearchMatrix(String name){
        super(name); 
        int chemin[] = new int[this.NbVertices];
        Boolean mark[] = new Boolean[this.NbVertices];
        int distance[] = new int[this.NbVertices];;
        for(int i = 0; i < chemin.length; i++){
            chemin[i] = 0;
            mark[i] = false; 
            distance[i] = Integer.MAX_VALUE;
        }
        this.Chemin = chemin;
        this.Mark = mark;
        this.Distance = distance;
    }

//Il y'a un problème de marquage 

    public void resolve(){
        Queue<Integer> Queue = new ArrayDeque<>();
        int chemin[] = this.Chemin;
        int distance[] = this.Distance;
        int succ; 

        Queue.add(0);
        int visited;
        int neighbour;
        int increment = 0;
        while(Queue.size() > 0){
            visited = Queue.remove(); 
            this.Mark[visited] = true;
            for(int j = 0; j < this.NbVertices; j ++){
                neighbour = this.AdjacencyMatrix[visited][j];
                if(neighbour > 0){
                    succ = j;
                    if(this.Mark[succ] == false){
                        increment++;
                        chemin[increment] = succ;
                        Queue.add(succ);

   
                }
            }
        }
    }

    this.Chemin = chemin;
    this.Distance = distance;
}


    public void displayBreathFirstSearchMatrix(){
        System.out.println("Le graph est: ");
        displayGraph();
        System.out.println("La solution est: ");

        for(int i = 0; i < this.Chemin.length; i++){
        System.out.println(this.Chemin[i]);

    }
}
}