#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
ll d[110][110],c[110][110],k[10][10];

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                scanf("%lld",&d[i][j]);
            }
        }
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                scanf("%lld",&k[i][j]);
            }
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                c[i][j]=0;
                for (int a=0;a<=min(n-i-1,2);a++) {
                    for (int b=0;b<=min(m-j-1,2);b++) {
                        c[i][j]+=d[i+a][j+b]*k[a][b];
                    }
                }
            }
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                printf("%lld%c",c[i][j],(j==m-1)?'\n':' ');
            }
        }
    }
    return 0;
}
