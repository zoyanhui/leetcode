import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/**
 * Created by zhouyanhui on 2020/5/27.
 */
public class Solution_TimeExceed {
    class Solution {
        public int subarraysDivByK(int[] A, int K) {
            int total = 0;
            int[] sum = new int[A.length];
            for(int i =0; i<A.length; i++){
                sum[i] = A[i];
                if(sum[i] % K == 0){
                    total++;
                }
                for(int j = 0; j<i; j++){
                    sum[j] += A[i];
                    if(sum[j] % K == 0){
                        total++;
                    }
                }
            }
            return total;
        }
    }

    static class Case{
        int[] a;
        int n;

        public Case(int[] a, int n) {
            this.a = a;
            this.n = n;
        }
    }
    private static Case read(String file) throws IOException {
        try(BufferedReader bufferedReader = new BufferedReader(new FileReader(file))){
            String s = bufferedReader.readLine();
            int n = Integer.parseInt(s);
            String vals = bufferedReader.readLine();
            String[] split = vals.split(",");
            int[] a = new int[split.length];
            for (int i = 0; i < split.length; i++) {
                a[i] = Integer.parseInt(split[i]);
            }
            return new Case(a, n);
        }
    }

    public static void main(String[] args) throws IOException {
        Solution_TimeExceed solution_timeExceed = new Solution_TimeExceed();
        Solution s = solution_timeExceed.new Solution();
        Case c = read(Solution_TimeExceed.class.getResource("/long_case.txt").getFile());
        int ret = s.subarraysDivByK(c.a, c.n);
        System.out.println(ret);
    }
}
