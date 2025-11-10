import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Graph {
  int NbVertices;
  int NbEdges;
  List<Integer> Vertices;
  List<List<Integer>> Edges;
  Random random = new Random();
  int[][] AdjacencyMatrix;

  Graph(String name) {
    this.NbEdges = 0; 
    File input = new File(name);
    List<List<Integer>> edges = new ArrayList<List<Integer>>();
    try {
      Scanner reader = new Scanner(input);
      while (reader.hasNextLine()) {
        String[] nums = reader.nextLine().split(" ");
        if (nums.length < 3) {
          this.NbVertices = Integer.parseInt(nums[0]);
          this.AdjacencyMatrix = new int[this.NbVertices][this.NbVertices];
          this.Vertices = new ArrayList<Integer>();
          for (int i = 0; i < NbVertices; i++) {
            this.Vertices.add(i);
          }
        } else {
          edges.add(Arrays.asList(Integer.parseInt(nums[0]), Integer.parseInt(nums[1]), Integer.parseInt(nums[2])));
        }
      }

      this.Edges = edges;

      for (List<Integer> elem : edges) {

        this.AdjacencyMatrix[elem.get(0)][elem.get(1)] = elem.get(2);
        this.NbEdges++;

      }

      reader.close();

    } catch (IOException e) {
      System.out.println("no file");
    }

  }

  public void addEdge(int prec, int succ, int pounds) {

    Edges.add(Arrays.asList(prec, succ, pounds));
    AdjacencyMatrix[prec][succ] = pounds;
  }

  public void displayGraph() {

    System.out.println("Le nombre de sommets est: " + NbVertices);
    System.out.println("Le nombre d'arrêtes est: " + NbEdges);
    System.out.println("La liste des sommet est: " + Vertices);
    System.out.println("la liste des arrêtes est: " + Edges);
    System.out.println("la matrice d'adjacence est: ");
    for (int r = 0; r < AdjacencyMatrix.length; r++) {
      for (int c = 0; c < AdjacencyMatrix[0].length; c++) {
        System.out.print(AdjacencyMatrix[r][c] + "\t");
      }
      System.out.println();
    }
  }

}
