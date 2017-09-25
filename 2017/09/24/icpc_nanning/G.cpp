#include <bits/stdc++.h>
using namespace std;

const double IR2=100;

struct Point {
    double x,y;
    Point operator +(const Point &R) {
        return {x+R.x,y+R.y};
    }
    Point operator -(const Point &R) {
        return {x-R.x,y-R.y};
    }
    Point operator *(const double &R) {
        return {x*R,y*R};
    }
    double operator *(const Point &R) {
        return x*R.x+y*R.y;
    }
};

#define sqr(x) ((x)*(x))
inline Point inv_point(Point O,Point X)
{
    return X*(IR2/sqr(X));
}

inline double inv_circle(Point O,Point C,double r,Point &Cx)
{
    double sd=sqr(C-O)-sqr(r);
    double k=IR2/sd;
    Cx=O+(C-O)*k;
    return IR2*r/sd;
}

inline double inv_circle(Point O,Point C,double r)
{
    return IR2*r/(sqr(C-O)-sqr(r));
}

int main()
{
    int l;
    double R;
    scanf("%d",&l);
    scanf("%lf",&R);
    Point O{0,0},C{0,-R*sqrt(3)},Cx;
    double r=inv_circle(O,C,R,Cx);
    while (l--) {
        int k;
        scanf("%d",&k);
        printf("%d %d\n",k,(int)inv_circle(O,{0,Cx.y-2*k*r},r));
    }
    return 0;
}
