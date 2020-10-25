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
    static int getTuran(int n, int r) {
        int nn = n * (n - 1) / 2;
        int nr = n % r;
        double fl = Math.floor(n * 1.0 / r);
        double cl = Math.ceil(n * 1.0 / r);
        int ccl = (int) (cl * (cl - 1));
        int ffl = (int) (fl * (fl - 1));
        return nn - (nr * (ccl / 2)) - ((r - nr) * (ffl / 2));
    }
    public static void main(String[] args) throws IOException {
          BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        for (int i = 0; i < tc; i++) {
            String str = br.readLine();
            String[] arr = str.trim().split(" ");
            int n = Integer.parseInt(arr[0]);
            int m = Integer.parseInt(arr[1]);
            int l = 1;
            int r = n+1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (getTuran(n, mid) >= m)
                    r = mid;
                else
                    l = mid + 1;
            }
            System.out.println(l);
        }
    }
}
