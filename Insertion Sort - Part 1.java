import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the insertionSort1 function below.
    static void insertionSort1(int n, int[] arr) {

        int e = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (i + 1 < n && arr[i] > e) {
                arr[i + 1] = arr[i];
                for (int k = 0; k < n; k++) {
                    System.out.print(arr[k] + " ");
                }
            } else if (arr[i] < e) {
                arr[i + 1] = e;
                for (int k = 0; k < n; k++) {
                    System.out.print(arr[k] + " ");
                }
                break;
            }
            System.out.println();
        }
        if(arr[0] > e) {
            arr[0] = e;
            for (int k = 0; k < n; k++) {
                System.out.print(arr[k] + " ");
            }
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        insertionSort1(n, arr);

        scanner.close();
    }
}
