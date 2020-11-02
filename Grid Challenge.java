import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the gridChallenge function below.
    static String gridChallenge(String[] grid) {
        char[][] res = new char[grid.length][grid[0].length()];
        for(int i = 0; i < grid.length; i++)
        {
            char[] ch = grid[i].toCharArray();
            Arrays.sort(ch);
            res[i] = ch;
        }
        int n = grid.length;
        int m = grid[0].length();
        // System.out.println(n+" : "+m);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if((j+1 < m) && res[j][i] > res[j+1][i]){
                    return "NO";
                }
            }
        }
        return "YES";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            String[] grid = new String[n];

            for (int i = 0; i < n; i++) {
                String gridItem = scanner.nextLine();
                grid[i] = gridItem;
            }

            String result = gridChallenge(grid);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
