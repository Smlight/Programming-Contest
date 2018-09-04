#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-12;
const double PI = acos(-1);
int sgn(double x)
{
    if(abs(x) < eps)
        return 0;
    if(x < 0)
        return -1;
    else
        return 1;
}
struct Point {
    double x,y;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x, y - b.y);
    }
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
};

double dist(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}

double delta_length(Point c1,double r1,Point c2,double r2)
{
    double d = dist(c1,c2);
    if (d < eps) return 0;
    if (r1 + r2 < d + eps) return 0;
    if (sgn(d - abs(r1 - r2)) < 0) return 0;
    double x = (d*d + r1*r1 - r2*r2)/(2*d);
    double t1 = acos(x / r1);
    double t2 = acos((d - x)/r2);
    return r1*t1 - r2*t2;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int m;
        double R;
        Point O(0,0);
        scanf("%d%lf",&m,&R);
        double ans=2*PI*R;
        for (int i=1;i<=m;i++) {
            double x,y,r;
            scanf("%lf%lf%lf",&x,&y,&r);
//            printf("%.6f\n",delta_length({x,y},r,O,R));
            ans+=2*delta_length({x,y},r,O,R);
        }
        printf("%.20f\n",ans);
    }
    return 0;
}
