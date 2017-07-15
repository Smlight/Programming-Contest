#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    double k,n,m;
    while (scanf("%lf%lf%lf",&k,&n,&m)!=EOF) {
        double ans=0;
        for (int x=1;x<=n;x++) {
            for (int y=1;y<=m;y++) {
                ans+=pow(1-(2*x*x-(2*n+2)*x+1)*(2*y*y-(2*m+2)*y+1)/(n*n*m*m),k);
            }
        }
        double o=n*m-ans;
        printf("%.0f\n",o);
    }
    return 0;
}
