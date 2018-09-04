#include <bits/stdc++.h>
using namespace std;

const char st[10][10]= {
    {"!!+-+"},
    {"!/ /|"},
    {"+-+ +"},
    {"| |/"},
    {"+-+"}
};
const int M=300;
char c[M][M];
int h,l,a[M/5][M/5],mxp[M/5];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        int n=y;
        int m=x;
        int mx=0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                a[i][j]=z;
                mx=max(mx,1+a[i][j]*2+(n-i+1)*2);
                mxp[i]=max(mxp[i],a[i][j]);
            }
        }
        memset(c,0,sizeof(c));
        for(int i=n; i>=1; i--)
            for(int k=mxp[i]; k>=1; k--)
                for(int j=m; j>=1; j--)
                    if(a[i][j]>=k)
                        for(int o=mx-(n-i)*2-4-(k-1)*2; o<=mx-(n-i)*2-(k-1)*2; o++)
                            for(int p=(n-i)*2+j*2-1; p<=(n-i)*2+j*2+3; p++)
                                if(!c[o][p]||c[o][p]=='!')
                                    c[o][p]=st[o-(mx-(n-i)*2-4-(k-1)*2)][p-((n-i)*2+j*2-1)];
        for(int i=1; i<=mx; i++) {
            for(int j=1; j<=n*2+m*2+1; j++) {
                if (!c[i][j]||c[i][j]=='!'||c[i][j]==' ')
                    putchar('.');
                else
                    putchar(c[i][j]);
            }
            puts("");
        }
    }
    return 0;
}