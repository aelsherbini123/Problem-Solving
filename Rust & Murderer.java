import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    static class Pair {
        int left;
        int right;

        public Pair(int left, int right) {
            this.left = left;
            this.right = right;
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + left;
            result = prime * result + right;
            return result;
        }

        @Override
        public boolean equals(Object other) {
            if (this == other) {
                return true;
            }
            if (other instanceof Pair) {
                Pair m = (Pair) other;
                return this.left == m.left && this.right == m.right;
            }
            return false;
        }
    }

    public static void bfs(int start, int n, int m, Set<Pair> edges) {
        int i;

        Set<Integer> undiscovered = new HashSet<>();

        int[] distance_node = new int[n+1];

        for (i = 1; i <= n; i++) {

            undiscovered.add(i);

            distance_node[i] = Integer.MAX_VALUE;
        }

        undiscovered.remove(start);

        distance_node[start] = 0;

        Queue<Integer> q = new LinkedList<>();

        q.add(start);

        while (undiscovered.size() > 0 && !q.isEmpty()) {

            int cur = q.peek();
            q.remove();

            List<Integer> complement_vertex = new ArrayList<>();

            for (int x : undiscovered) {
                Pair temp = new Pair(cur, x);

                if (!edges.contains(temp)) {
                    complement_vertex.add(x);
                }
            }

            for (int x : complement_vertex) {

                if (distance_node[x] > distance_node[cur] + 1) {
                    distance_node[x] = distance_node[cur] + 1;
                    q.add(x);
                }

                undiscovered.remove(x);
            }
        }

        for (i = 1; i <= n; i++)
            if (i != start)
                System.out.print(distance_node[i] + " ");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Integer tc = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tc; t++) {
            Set<Pair> edges = new HashSet<>();
            String str = br.readLine();
            String[] arr = str.trim().split(" ");
            int n = Integer.parseInt(arr[0]);
            int m = Integer.parseInt(arr[1]);
            for (int i = 0; i < m; i++) {
                String x = br.readLine();
                String[] data = x.trim().split(" ");
                int u = Integer.parseInt(data[0]);
                int v = Integer.parseInt(data[1]);
                edges.add(new Pair(u, v));
                edges.add(new Pair(v, u));
            }
            Integer start = Integer.parseInt(br.readLine());
            bfs(start, n, m, edges);
            System.out.println();
        }       
    }
}
