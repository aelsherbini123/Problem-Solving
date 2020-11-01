import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the maximumPerimeterTriangle function below.
    static int round(double res){
         res *= 10;
        int round;
        if(res%10 >= 5){
            round = (int)res/10 + 1;
        }else{
            round = (int)res/10;
        }
        return round;
    }
    static int[] maximumPerimeterTriangle(int[] sticks) {
        Arrays.sort(sticks);
        int []sides = new int[3];
        int max = Integer.MIN_VALUE;
        for(int i = 0; i < sticks.length; i++)
        {
            if((i+1 < sticks.length && i+2 < sticks.length)){
                int a = sticks[i];
                int b = sticks[i+1];
                int c = sticks[i+2];
                if((a+b > c) && (a+c > b) && (b+c > a)){
                    int pre = a+b+c;
                   if(pre > max){
                       max = pre;
                       sides[0] = a;
                       sides[1] = b;
                       sides[2] = c;
                   }
                }
            }
        }
        if(sides[0] == 0 && sides[1] == 0 && sides[2] == 0) return new int []{-1};
        return sides;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] sticks = new int[n];

        String[] sticksItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int sticksItem = Integer.parseInt(sticksItems[i]);
            sticks[i] = sticksItem;
        }

        int[] result = maximumPerimeterTriangle(sticks);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write(" ");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
