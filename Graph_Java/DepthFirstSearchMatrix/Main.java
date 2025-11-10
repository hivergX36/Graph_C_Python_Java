
public class Main{
 
public static void main(String[] args){
    DephtFirstSearchMatrix dephtFirstSearch = new DephtFirstSearchMatrix("Graph.txt");
    System.out.println("The deterministic graph is: ");
    dephtFirstSearch.displayGraph();
    dephtFirstSearch.displayDephtFirstSearch();
    dephtFirstSearch.resolve();
    dephtFirstSearch.displayDephtFirstSearch();

}
}