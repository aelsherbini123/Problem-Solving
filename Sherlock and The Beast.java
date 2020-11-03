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

    // Complete the decentNumber function below.
    static void decentNumber(int n) {
        String res;
       
            res = new String(new char[n]).replace("\0", "5");
            int cnt = 0;
            int x = n;
            for(int i = res.length()-1; i >= 0; i--)
            {
                if(x % 3 == 0 && cnt % 5 == 0) break;
                else{
                    res = res.substring(0, i) + '3' + res.substring(i + 1);
                    cnt++;
                    x--;
                }
            }
        if(x % 3 != 0 || cnt % 5 != 0) System.out.println("-1");
        else System.out.println(res);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, t).forEach(tItr -> {
            try {
                int n = Integer.parseInt(bufferedReader.readLine().trim());

                decentNumber(n);
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
    }
}
