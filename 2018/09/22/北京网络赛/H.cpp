#include<bits/stdc++.h>
using namespace std;

const double eps=1e-7;
const int N=105;
int T,n,K,R;
int o[N],x[N];
bool neg[N];

int sgn(double x)
{
    if(abs(x) < eps) return 0;
    if(x < 0) return -1;
    else return 1;
}

double calc(double y)
{
    double res=0;
    for (int j=0;j<K;j++) {
        res+=max(x[j]-y,0.0);
    }
    return res-R;
}

double bs(double l,double r)
{
    double res=1e60;
    while (r-l>eps) {
        double m=0.5*(l+r);
        double dlt=calc(m);
        if (sgn(dlt)<=0) {
            res=m;
            r=m;
        } else {
            l=m;
        }
    }
    return res;
}

int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&n,&K,&R);
        for (int i=0;i<K;i++) {
            scanf("%d",&o[i]);
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<K;j++) {
                scanf("%d",&x[j]);
                if (x[j]<o[j]) {
                    neg[j]=true;
                    x[j]=o[j]-x[j];
                } else {
                    neg[j]=false;
                    x[j]=x[j]-o[j];
                }
            }
            double y=bs(0,*max_element(x,x+K));
            for (int j=0;j<K;j++) {
                double tmp=max(x[j]-y,0.0);
                printf("%.5f%c",neg[j]?-tmp+o[j]:tmp+o[j],(j==K-1)?'\n':' ');
            }
        }
    }
    return 0;
}
