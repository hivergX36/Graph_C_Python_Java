
public class Main{
 
public static void main(String[] args){
    Djikstra djikstra = new Djikstra("Graph.txt");
    System.out.println("The deterministic graph is: ");
    djikstra.displayGraph();
    djikstra.displayDjikstra();
    djikstra.resolve();
    djikstra.displayDjikstra();

}
}