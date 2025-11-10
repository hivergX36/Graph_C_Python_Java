import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.util.ArrayDeque;
import java.util.Queue;

public class EdmondsKarp {
    Float AdjacencyMatrix[][];
    int NbVertices;
    float max_flow = 0.0f;

    EdmondsKarp(String name) {
        int index_1 = 0;
        int index_2 = 0;
        float weight = 0;
        File input = new File(name);
        try {
            Scanner reader = new Scanner(input);
            String[] nums = reader.nextLine().split(" ");
            this.NbVertices = Integer.parseInt(nums[0]);
            this.AdjacencyMatrix = new Float[this.NbVertices][this.NbVertices];
            for (int i = 0; i < this.NbVertices; i++) {
                for (int j = 0; j < this.NbVertices; j++) {
                    this.AdjacencyMatrix[i][j] = 0.0f;
                }
            }
            while (reader.hasNextLine()) {
                nums = reader.nextLine().split(" ");
                index_1 = Integer.parseInt(nums[0]);
                index_2 = Integer.parseInt(nums[1]);
                weight = Float.parseFloat(nums[2]);
                this.AdjacencyMatrix[index_1][index_2] = weight;
            }
            reader.close();
        } catch (IOException e) {
            System.out.println("no file");
        }

    }

    public boolean bfs(boolean visited[], int pred[], int source, int sink) {
        visited[source] = true;
        int u = 0;
        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(source);
        System.out.println("Visiting node: " + source);
        while (!queue.isEmpty()) {
            u = queue.poll();
            for (int v = 0; v < this.NbVertices; v++) {
                if (!visited[v] && this.AdjacencyMatrix[u][v] > 0) {
                    pred[v] = u;
                    visited[v] = true;
                    if (v == sink) {
                        return true;
                    }
                    queue.add(v);
                }
            }
        }
        return false;
    }

    public void solve() {
        int pred[] = new int[this.NbVertices];
        boolean visited[] = new boolean[this.NbVertices];
        this.max_flow = 0.0f;
        boolean dfs_result = false;
        boolean stop = false;
        System.out.println("Starting the algorithm...");
        while (stop == false) {
            for (int i = 0; i < this.NbVertices; i++) {
                visited[i] = false;
                pred[i] = -1;
            }
            dfs_result = this.bfs(visited, pred, 0, this.NbVertices - 1);
            if (dfs_result == false) {
                System.out.println("stop condition");
                stop = true;
                break;
            }
            float path_flow = Float.POSITIVE_INFINITY;

            System.out.println("An augmenting path has been found.");
            for (int v = this.NbVertices - 1; v != 0; v = pred[v]) {
                int u = pred[v];
                path_flow = Math.min(path_flow, this.AdjacencyMatrix[u][v]);
            }

            for (int v = this.NbVertices - 1; v != 0; v = pred[v]) {
                int u = pred[v];
                this.AdjacencyMatrix[u][v] = this.AdjacencyMatrix[u][v] - path_flow;
                this.AdjacencyMatrix[v][u] = this.AdjacencyMatrix[u][v] + path_flow;
            }
            this.max_flow += path_flow;
        }
    }

    public void displayResidualGraphAndMaxFlow() {
        System.out.println("The residual graph is: ");
        for (int i = 0; i < this.NbVertices; i++) {
            for (int j = 0; j < this.NbVertices; j++) {
                System.out.print(this.AdjacencyMatrix[i][j] + " ");

            }
            System.out.println("\n");
        }
        System.out.println("The maximum flow is: " + this.max_flow);
    }
}