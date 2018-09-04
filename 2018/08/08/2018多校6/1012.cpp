#include <bits/stdc++.h>
using namespace std;

const double g=9.8;
const double PI=acos(-1);

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        double a,b,x,y;
        scanf("%lf%lf%lf%lf",&a,&b,&x,&y);
        double axiv=atan2(b,-a);
        double v=sqrt(2*g*(y+b*x/a)),arg=2*axiv-PI;
//        printf("%.2f %.2f\n",v,arg/PI*180);
        int ans=0;
        while (1) {
            ++ans;
            double vx=v*sin(arg);
            double vy=v*cos(arg);
//            printf("%.2f %.2f\n",vx,vy);
            double t=(b*vx/a-vy)*2/g;
            x+=vx*t;
//            printf("X: %.2f\n",x);
            if (x>0) break;
            vy+=g*t;
            double alpha=atan2(vx,vy)+PI;
            arg=2*axiv-alpha;
            v=sqrt(vx*vx+vy*vy);
//            printf("%.2f %.2f\n",v,arg/PI*180);
        }
        printf("%d\n",ans);
    }
    return 0;
}