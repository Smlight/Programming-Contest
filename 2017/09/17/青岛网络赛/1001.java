import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		while (T > 0) {
			T--;
			BigDecimal xa, ya, xb, yb, xc, yc, X, Y;
			xa = scanner.nextBigDecimal();
			ya = scanner.nextBigDecimal();
			xb = scanner.nextBigDecimal();
			yb = scanner.nextBigDecimal();
			xc = scanner.nextBigDecimal();
			yc = scanner.nextBigDecimal();
			X = scanner.nextBigDecimal();
			Y = scanner.nextBigDecimal();
			BigDecimal xa2 = xa.multiply(xa);
			BigDecimal ya2 = ya.multiply(ya);
			BigDecimal xb2 = xb.multiply(xb);
			BigDecimal yb2 = yb.multiply(yb);
			BigDecimal xc2 = xc.multiply(xc);
			BigDecimal yc2 = yc.multiply(yc);
			BigDecimal xp = yc.subtract(yb).multiply(xa2.add(ya2).subtract(xb2).subtract(yb2));
			xp = xp.subtract(ya.subtract(yb).multiply(xc2.add(yc2).subtract(xb2).subtract(yb2)));
			BigDecimal yp = xa.subtract(xb).multiply(xc2.add(yc2).subtract(xb2).subtract(yb2));
			yp = yp.subtract(xc.subtract(xb).multiply(xa2.add(ya2).subtract(xb2).subtract(yb2)));
			BigDecimal TWO = BigDecimal.valueOf(2);
			BigDecimal dlt = TWO.multiply(xa.subtract(xb)).multiply(yc.subtract(yb));
			dlt = dlt.subtract(TWO.multiply(xc.subtract(xb)).multiply(ya.subtract(yb)));
			xp = xp.divide(dlt);
			yp = yp.divide(dlt);
			// ld px=(C1*B2-C2*B1)/(A1*B2-A2*B1);
			// ld py=(A1*C2-A2*C1)/(A1*B2-A2*B1);
			BigDecimal dx = xa.subtract(xp);
			BigDecimal dy = ya.subtract(yp);
			BigDecimal r = dx.multiply(dx).add(dy.multiply(dy));
			dx = X.subtract(xp);
			dy = Y.subtract(yp);
			BigDecimal d = dx.multiply(dx).add(dy.multiply(dy));
			// ld r=dis2(xa,ya,px,py);
			// ld d=dis2(X,Y,px,py);
			if (d.compareTo(r) <= 0) {
				System.out.println("Rejected");
			} else {
				System.out.println("Accepted");
			}
		}
	}
}
