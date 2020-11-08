import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the beautifulPairs function below.
    static int beautifulPairs(Integer[] A, Integer[] B) {
       HashMap<Integer, Integer> CountMap = new HashMap<>();
       for(int i = 0; i < A.length; i++)
       {
           if (CountMap.containsKey(A[i])) { 
  
                CountMap.put(A[i], CountMap.get(A[i]) + 1); 
            } 
            else { 
                CountMap.put(A[i], 1); 
            } 
       }
       int beauti = 0;
         for(int i = 0; i < B.length; i++){
             if(CountMap.get(B[i]) != null && CountMap.get(B[i]) > 0){
                 beauti++;
                 CountMap.put(B[i], CountMap.get(B[i]) - 1);
             }
         }
         if(beauti < A.length) return beauti+1;
         return beauti-1;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        Integer[] A = new Integer[n];

        String[] AItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            Integer AItem = Integer.parseInt(AItems[i]);
            A[i] = AItem;
        }

        Integer[] B = new Integer[n];

        String[] BItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            Integer BItem = Integer.parseInt(BItems[i]);
            B[i] = BItem;
        }

        int result = beautifulPairs(A, B);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
