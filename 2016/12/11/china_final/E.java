package gym101194;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		BigInteger[] up = new BigInteger[100];
		BigInteger[] down = new BigInteger[100];
		for (int t = 1; t <= T; t++) {
			int n = sc.nextInt();
			sc.nextLine();
			for (int i = 0; i < n; i++) {
				String str = sc.nextLine();
				String[] da = str.split(":");
				double x = Double.parseDouble(da[0]) * 1000;
				double y = Double.parseDouble(da[1]) * 1000;
				BigInteger a = BigInteger.valueOf((long) x);
				BigInteger b = BigInteger.valueOf((long) y);
				BigInteger g = a.gcd(b);
				up[i] = a.divide(g);
				down[i] = a.add(b).divide(g);
			}
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (up[i].multiply(down[j]).compareTo(down[i].multiply(up[j])) > 0) {
						BigInteger tmp = up[i];
						up[i] = up[j];
						up[j] = tmp;
						tmp = down[i];
						down[i] = down[j];
						down[j] = tmp;
					}
				}
			}
			BigInteger su = BigInteger.ZERO;
			BigInteger sd = BigInteger.ONE;
			int ans = 0;
			for (int i = 0; i < n; i++) {
				BigInteger nu = su.multiply(down[i]).add(sd.multiply(up[i]));
				BigInteger nd = sd.multiply(down[i]);
				BigInteger g = nu.gcd(nd);
				su = nu.divide(g);
				sd = nd.divide(g);
				if (su.compareTo(sd) < 0) {
					ans += 1;
				} else {
					break;
				}
			}
			System.out.println("Case #" + t + ": " + ans);
		}
	}
}
