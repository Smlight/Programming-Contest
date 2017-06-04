#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int mp[110][110];
int vis[110][110];

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        int tot=n*m;
        int x=1,y=1,kx=0,ky=1;
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=tot;i++) {
            int tmp;
            scanf("%d",&tmp);
            if (x>n||y>m||x<1||y<1||vis[x][y]) {
                x-=kx;y-=ky;
                if (ky==-1) {
                    ky=0;kx=-1;
                } else if (ky==1) {
                    ky=0;kx=1;
                } else {
                    if (kx==1) {
                        kx=0;ky=-1;
                    } else {
                        kx=0;ky=1;
                    }
                }
                x+=kx;y+=ky;
            }
            mp[x][y]=tmp;
            vis[x][y]=1;
            x+=kx;y+=ky;
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                printf("%d%c",mp[i][j],(j==m)?'\n':' ');
            }
        }
    }
    return 0;
}
