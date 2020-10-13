import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Pair<Key, Value> {
    private Key key;
    private Value value;

    public Pair(Key key, Value value) {
        this.key = key;
        this.value = value;
    }

    public Key getKey() {
        return key;
    }

    public void setKey(Key key) {
        this.key = key;
    }

    public Value getValue() {
        return value;
    }

    public void setValue(Value value) {
        this.value = value;
    }

}

public class Solution {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String str = br.readLine();
        String[] nums = str.trim().split(" ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(nums[i]);
        }
        Arrays.sort(arr);
        List<Pair< Pair <Integer, Integer>, Integer > > lst = new ArrayList<>();
        int min = 10000007;
        for(int i = 1; i < arr.length; i++)
        {
            min = Math.min(min, Math.abs(arr[i-1]-arr[i]));
            lst.add(new Pair<Pair<Integer,Integer>, Integer>(new Pair<Integer,Integer>  (arr[i-1],arr[i]), Math.abs(arr[i-1]-arr[i])));
        }
        for (Pair<Pair<Integer, Integer>, Integer> res : lst) {
            if(res.getValue().equals(min)) {
                System.out.print(res.getKey().getKey()+" "+res.getKey().getValue()+" ");
            }
        }
    }
}
