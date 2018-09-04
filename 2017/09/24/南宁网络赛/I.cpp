#include <bits/stdc++.h>
using namespace std;

const double SQRT3=sqrt(3);

int main()
{
    int T=10;
    while (T--) {
        int x,y,ansx,ansy;
        scanf("%d%d",&x,&y);
        double mn=1e60;
        for (int i=-9;i<=10;i++) {
            for (int j=-9;j<=10;j++) {
                double Y=7.5*j;
                double X=2.5*SQRT3*j+5*SQRT3*i;
                #define sqr(x) ((x)*(x))
                double dis=sqr(X-x)+sqr(Y-y);
                if (dis<mn) {
                    mn=dis;
                    ansx=i;ansy=j;
                }
            }
        }
        if (T==0) {
            printf("[%d,%d]\n",ansx,ansy);
        } else {
            printf("[%d,%d], ",ansx,ansy);
        }
    }
    return 0;
}
