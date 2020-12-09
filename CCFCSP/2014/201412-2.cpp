#include <bits/stdc++.h>
using namespace std;

const int N=550;
int mp[N][N];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            scanf("%d", &mp[i][j]);
        }
    }
    int x=1,y=1,k=1;
    int tot=n*n;
    for (int i=1;i<=tot;i++) {
        printf("%d%c", mp[x][y], i==tot?'\n':' ');
        x-=k;
        y+=k;
        if (y>n) {
            x+=k;
            y-=k;
            x+=k;
            k=-k;
        } else if (x>n) {
            x+=k;
            y-=k;
            y-=k;
            k=-k;
        } else if (x<1) {
            x+=k;
            k=-k;
        } else if (y<1) {
            y-=k;
            k=-k;
        }
    }
    return 0;
}
