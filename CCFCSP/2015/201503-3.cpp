#include <bits/stdc++.h>
using namespace std;

int zeller(int y,int m,int d)
{
    if (m<=2) y-=1,m+=12;
    int c=y/100; y-=c*100;
    int wd=(c/4)-2*c+(y+y/4)+(13*(m+1)/5)+d+6;
    return wd%7;
}

bool leap(int y)
{
    return y%400==0||(y%100!=0&&y%4==0);
}

int mon[22]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int getmdays(int y,int m)
{
    if (m!=2) return mon[m];
    return mon[2]+leap(y);
}

bool ok(int y,int m,int w,int d)
{
    int p=1;
    int wd=zeller(y,m,1);
    while (wd!=d) {
        wd=(wd+1)%7;
        ++p;
    }
    p+=(w-1)*7;
    if (p>getmdays(y,m)) return false;
    printf("%04d/%02d/%02d\n",y,m,p);
    return true;
}

int main()
{
    int a,b,c,s,t;
    scanf("%d%d%d%d%d",&a,&b,&c,&s,&t);
    c%=7;
    for (int i=s;i<=t;i++) {
        if (!ok(i,a,b,c)) puts("none");
    }
    return 0;
}
