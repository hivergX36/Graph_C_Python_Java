
public class Main {
    public static void main(String[] args) {
        Bellman_Ford bellman_Ford = new Bellman_Ford("data2.txt");

        bellman_Ford.resolve();
        bellman_Ford.displayPath();
    }
}
    
