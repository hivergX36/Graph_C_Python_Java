import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Stack;

public class DephtFirstSearchMatrix extends Graph{

    int Chemin[];
    int Distance[];
    Boolean Mark[];


    DephtFirstSearchMatrix(String name){
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
        Stack<Integer> stack = new Stack<Integer>();
        int chemin[] = this.Chemin;
        int distance[] = this.Distance;
        int succ; 

        stack.add(0);
        int visited;
        int neighbour;
        int increment = 0;
        while(stack.size() > 0){
            visited = stack.pop(); 
            this.Mark[visited] = true;
            for(int j = 0; j < this.NbVertices; j ++){
                neighbour = this.AdjacencyMatrix[visited][j];
                if(neighbour > 0){
                    succ = j;
                    if(this.Mark[succ] == false){
                        increment++;
                        chemin[increment] = succ;
                        stack.add(succ);

   
                }
            }
        }
    }

    this.Chemin = chemin;
    this.Distance = distance;
}


    public void displayDephtFirstSearch(){
        System.out.println("Le graph est: ");
        displayGraph();
        System.out.println("La solution est: ");

        for(int i = 0; i < this.Chemin.length; i++){
        System.out.println(this.Chemin[i]);

    }
}
}