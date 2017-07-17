#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);

inline int sqr(int x)
{
    return x*x;
}

int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
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
        return Point(x - b.x,y - b.y);
    }
//叉积
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
//点积
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
//绕原点旋转角度B（弧度值），后x,y的变化
    void transXY(double B)
    {
        double tx = x,ty = y;
        x = tx*cos(B) - ty*sin(B);
        y = tx*sin(B) + ty*cos(B);
    }
};

double dist(Point a,Point b)
{
 return sqrt((a-b)*(a-b));
}

struct Line {
    Point s,e;
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
    }
    pair<int,Point> operator &(const Line &b)const
    {
        Point res = s;
        if(sgn((s-e)^(b.s-b.e)) == 0) {
            if(sgn((s-b.e)^(b.s-b.e)) == 0)
                return make_pair(0,res);//重合
            else return make_pair(1,res);//平行
        }
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return make_pair(2,res);
    }
};

Point NearestPointToLineSeg(Point P,Line L)
{
    Point result;
    double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
    if(t >= 0 && t <= 1) {
        result.x = L.s.x + (L.e.x - L.s.x)*t;
        result.y = L.s.y + (L.e.y - L.s.y)*t;
    } else {
        if(dist(P,L.s) < dist(P,L.e))
            result = L.s;
        else result = L.e;
    }
    return result;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int cx,cy,r,ax,ay,bx,by;
        scanf("%d%d%d%d%d%d%d",&cx,&cy,&r,&ax,&ay,&bx,&by);
        int da2=sqr(ax-cx)+sqr(ay-cy);
        int db2=sqr(bx-cx)+sqr(by-cy);
        if (da2<=sqr(r)&&db2<=sqr(r)) {
            if (ax==bx&&ay==by) {
                puts("All out");
            } else {
                puts("All in");
            }
        } else {
            Point pc(cx,cy);
            Point p=NearestPointToLineSeg(pc,Line(Point(ax,ay),Point(bx,by)));
            double dp2=dist(p,pc);
            if (sgn(dp2-r)<0) {
                puts("Part in");
            } else {
                puts("All out");
            }
        }
    }
    return 0;
}
