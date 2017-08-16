#include <bits/stdc++.h>
using namespace std;

#define sqr(x) ((x)*(x))

struct Point {
    double x,y;
    Point(double _x=0,double _y=0):x(_x),y(_y) {}
    Point operator +(const Point &R) {
        return Point(x+R.x,y+R.y);
    }
    Point operator -(const Point &R) {
        return Point(x-R.x,y-R.y);
    }
    double operator *(const Point &R) {
        return x*R.x+y*R.y;
    }
    Point operator *(const double &R) {
        return Point(x*R,y*R);
    }
    double norm() {
        return sqrt(x*x+y*y);
    }
};

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        double r;
        int x,y;
        scanf("%lf",&r);
        scanf("%d%d",&x,&y);
        Point P(x,y);
        scanf("%d%d",&x,&y);
        Point Q(x,y),O(0,0);
        Point Px=P*(sqr(r)/sqr(P));
        Point Qx=Q*(sqr(r)/sqr(Q));
        Point mid=(Px+Qx)*0.5;
        if (sqr(mid)<=sqr(r)) {
            printf("%.7f\n",(Px-Qx).norm()*P.norm()/r);
        } else {
            mid=(P+Q)*0.5;
            double X=r-mid.norm();
            double Y=(P-Q).norm()*0.5;
            printf("%.7f\n",2*sqrt(sqr(X)+sqr(Y)));
        }
    }
    return 0;
}
