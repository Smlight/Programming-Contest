#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld IR2=100;
const ld PI=3.141592653589793238462643383279502884197169399375105820974944592307816L;
struct Point {
    ld x,y;
    Point(ld _x=0,ld _y=0):x(_x),y(_y) {}
    Point operator +(const Point &R) {
        return Point(R.x+x,R.y+y);
    }
    Point operator -(const Point &R) {
        return Point(R.x-x,R.y-y);
    }
    ld operator *(const Point &R) {
        return R.x*x+R.y*y;
    }
    Point operator *(const ld &R) {
        return Point(x*R,y*R);
    }
    void print() {
        double o1=x,o2=y;
        cout<<o1<<" "<<o2<<"\n";
    }
};

#define sqr(x) ((x)*(x))
ld inv_circle(Point O,Point C,ld r)
{
    return IR2*r/(sqr(O-C)-sqr(r));
}

int main()
{
    int T;
    scanf("%d",&T);
    Point O(0,0);
    while (T--) {
        double t1,t2;
        scanf("%lf%lf",&t1,&t2);
        if (t1>t2) swap(t1,t2);
        ld r=t1,R=t2;
        int n;
        scanf("%d",&n);
        Point P(0.5*IR2/R,0);
        Point Q(0.5*IR2/r,0);
        ld L=Q.x-P.x;
        Point o((P+Q)*0.5);
        ld ans=0;
        if (n%2==0) {
            Point C(o.x,o.y+(n/2)*L);
            ld rr=inv_circle(O,C,L*0.5);
            ans+=PI*rr*rr;
        }
        for (int i=1;i+i-1<=n;i++) {
            Point C(o.x,o.y+(i-1)*L);
            ld rr=inv_circle(O,C,L*0.5);
            ld area=PI*rr*rr;
            if (area<1e-12) break;
            ans+=area;
            if (i>1) ans+=area;
        }
        double out=ans;
        printf("%.5f\n",out);
    }
    return 0;
}
