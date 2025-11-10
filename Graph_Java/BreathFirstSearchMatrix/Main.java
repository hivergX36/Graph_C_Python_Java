
public class Main{
 
public static void main(String[] args){
    BreathFirstSearchMatrix breathFirstSearchMatrix = new BreathFirstSearchMatrix("Graph.txt");
    System.out.println("The deterministic graph is: ");
    breathFirstSearchMatrix.displayGraph();
    breathFirstSearchMatrix.displayBreathFirstSearchMatrix();
    breathFirstSearchMatrix.resolve();
    breathFirstSearchMatrix.displayBreathFirstSearchMatrix();

}
}