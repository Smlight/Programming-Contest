#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=105;
int T,n,m;
int last[N][N*N],l[N],r[N];
ll ans;

void solve(int x,int y,int col)
{
    for (int i=1;i<=x;i++) {
        l[i]=0;r[i]=m+1;
    }
    for (int j=1;j<y;j++) {
        l[last[j][col]]=j;
    }
    for (int j=m;j>y;j--) {
        r[last[j][col]]=j;
    }
    int high=last[y][col];
    for (int i=x-1;i>high;i--) {
        l[i]=max(l[i],l[i+1]);
        r[i]=min(r[i],r[i+1]);
    }
    for (int i=high+1;i<=x;i++) {
        ans+=(ll)(y-l[i])*(r[i]-y)*(n-x+1);
    }
}

int main()
{
    scanf("%d",&T);
    while (T--) {
        memset(last,0,sizeof(last));
        ans=0;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                int col;
                scanf("%d",&col);
                solve(i,j,col);
                last[j][col]=i;
            }
        }
        ll all=(ll)n*(n+1)/2*m*(m+1)/2;
        printf("%.9f\n",(double)ans/all);
    }
    return 0;
}
