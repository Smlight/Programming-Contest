import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        int n;
        for (int t = 0; t < T; ++t) {
            n = s.nextInt();
            BigInteger ans = new BigInteger("1");
            for (int i = 0; i < n; ++i) {
                ans = ans.multiply(BigInteger.valueOf(2));
            }
            System.out.println(ans);
        }
    }
}