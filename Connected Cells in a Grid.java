import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static Integer count = 0;
    static boolean vis[][] = new boolean[11][11];

    static boolean isValid(int M[][], int row, int col, int m, int n) {
        return (row >= 0) && (row < m) && (col >= 0) && (col < n) && (M[row][col] == 1 && !vis[row][col]);
    }

    static void Dfs(int M[][], int row, int col, int m, int n) {
        int rows[] = new int[] { -1, -1, -1, 0, 0, 1, 1, 1 };
        int cols[] = new int[] { -1, 0, 1, -1, 1, -1, 0, 1 };
        vis[row][col] = true;
        count++;
        for (int k = 0; k < 8; k++) {
            if (isValid(M, row + rows[k], col + cols[k], m, n)) {
                Dfs(M, row + rows[k], col + cols[k], m, n);
            }
        }
    }

    static void reset_vis() {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                vis[i][j] = false;
            }
        }
    }

    static int countConnectedCells(int M[][], int m, int n) {
        int cnt = Integer.MIN_VALUE;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1 && !vis[i][j]) {
                    Dfs(M, i, j, m, n);
                }
                if (count >= cnt) {
                    cnt = count;
                }
                reset_vis();
                count = 0;
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Integer m = Integer.parseInt(br.readLine());
        Integer n = Integer.parseInt(br.readLine());
        int[][] mat = new int[m][n];
        for (int i = 0; i < m; i++) {
            String str = br.readLine();
            String[] nums = str.trim().split(" ");
            for (int j = 0; j < n; j++) {
                mat[i][j] = Integer.parseInt(nums[j]);
            }
        }

        System.out.println(countConnectedCells(mat, m, n));
    }
}
