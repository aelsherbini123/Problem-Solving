import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the luckBalance function below.
    static int luckBalance(int k, int[][] contests) {
        int min = 10000000, cnt = 0;
        for(int i = 0; i < contests.length; i++)
        {
            if(contests[i][1] == 1){ 
                cnt++;
            }
        }
        Arrays.sort(contests, new Comparator<int[]>() {
           @Override
        public int compare(int[] o1, int[] o2) {
                int itemIdOne = o1[0];
                int itemIdTwo = o2[0];
            return Integer.compare(itemIdOne,itemIdTwo);
        }
    });
        boolean []vis = new boolean[contests.length];
        for(int i = 0; i < contests.length; i++) vis[i] = false;
        int sum = 0;
        if(k == cnt){
            for(int i = 0; i < contests.length; i++)
            {
                sum += contests[i][0];
            }
        }else{
            int val = 0;
            int j = 0;
            for(int i = 0; i < contests.length && j < (cnt - k); i++)
            {
                if(contests[i][1] == 1 && !vis[i]){
                    //System.out.println(i + " : " + contests[i][0]);
                    val += contests[i][0];
                    vis[i] = true;
                    j++;
                }

            }
            for(int i = 0; i < contests.length; i++)
            {
                if(vis[i]) continue;
                sum += contests[i][0];
            }

            sum -= val;
        }
        return sum;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);

        int k = Integer.parseInt(nk[1]);

        int[][] contests = new int[n][2];

        for (int i = 0; i < n; i++) {
            String[] contestsRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 2; j++) {
                int contestsItem = Integer.parseInt(contestsRowItems[j]);
                contests[i][j] = contestsItem;
            }
        }

        int result = luckBalance(k, contests);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
