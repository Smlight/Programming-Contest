#include <bits/stdc++.h>
using namespace std;

const double eps=1e-8;
struct Point {
    double x,y;
    Point() {}
    Point(double a,double b):x(a),y(b) {}
    Point operator +(const Point &R) {
        return Point(x+R.x,y+R.y);
    }
    Point operator -(const Point &R) {
        return Point(x-R.x,y-R.y);
    }
    Point operator *(const double &R) {
        return Point(x*R,y*R);
    }
    double operator ^(const Point &R) {
        return x*R.y-y*R.x;
    }
    void print() {
        printf("%.2f %.2f\n",x,y);
    }
} t[2][4];
struct Line {
    Point s,e;
    Line() {}
    Line(Point a,Point b):s(a),e(b) {}
};

int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}

int inner(int p,int q)
{
    int res=0;
    double area=fabs((t[p][1]-t[p][0])^(t[p][2]-t[p][0]));
    for (int j=0;j<3;j++) {
        double arx=fabs((t[p][1]-t[q][j])^(t[p][2]-t[q][j]));
        arx+=fabs((t[p][0]-t[q][j])^(t[p][2]-t[q][j]));
        arx+=fabs((t[p][0]-t[q][j])^(t[p][1]-t[q][j]));
        if (sgn(arx-area)==0) ++res;
    }
    return res;
}

inline bool inter(Line l1,Line l2)
{
    return
     max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
     max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
     max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
     max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
     sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
     sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}

bool line_cross()
{
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (inter({t[0][i],t[0][(i+1)%3]},{t[1][j],t[1][(j+1)%3]})) return true;
        }
    }
    return false;
}

bool static_tri_cross()
{
    if (line_cross()) return true;
    return inner(0,1)||inner(1,0);
}

bool dynamic_tri_cross(int p,int q)
{
    Point dlt(t[q][3]-t[p][3]);
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            Point P0(t[p][(i+1)%3]-t[p][i]);
            double rat=(P0^(t[q][j]-t[p][i]))/(dlt^P0);
            double mxx=max(t[p][(i+1)%3].x,t[p][i].x);
            double mnx=min(t[p][(i+1)%3].x,t[p][i].x);
            double mxy=max(t[p][(i+1)%3].y,t[p][i].y);
            double mny=min(t[p][(i+1)%3].y,t[p][i].y);
            if (rat>=0&&mnx<=t[q][j].x+rat*dlt.x&&t[q][j].x+rat*dlt.x<=mxx
                &&mny<=t[q][j].y+rat*dlt.y&&t[q][j].y+rat*dlt.y<=mxy) return true;

        }
    }
    return false;
}

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        for (int i=0;i<2;i++) {
            for (int j=0;j<4;j++) {
                scanf("%lf%lf",&t[i][j].x,&t[i][j].y);
            }
        }
        printf("Case #%d: ",++cas);
        if (sgn(t[1][3].x-t[0][3].x)==0&&sgn(t[1][3].y-t[0][3].y)==0) {
            puts(static_tri_cross()?"YES":"NO");
        } else {
            puts(dynamic_tri_cross(0,1)||dynamic_tri_cross(1,0)?"YES":"NO");
        }
    }
    return 0;
}
