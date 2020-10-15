import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class Solution {

    // Complete the balancedSums function below.
   
    public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Integer tc = Integer.parseInt(br.readLine());
        for (int t = 0; t < tc; t++) {
            Integer n = Integer.parseInt(br.readLine());
            String str = br.readLine();
            String[] nums = str.trim().split(" ");

            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(nums[i]);
            }

            int sum = 0;
            int left = 0;
            for (int i = 0; i < arr.length; i++) {
                sum += arr[i];
            }
            boolean flag = false;
            for (int i = 0; i < arr.length; i++) {
                if (2 * left == sum - arr[i]) {
                    flag = true;
                    break;
                } else {
                    left += arr[i];
                }
            }
            if (flag)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
