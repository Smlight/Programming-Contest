#include <bits/stdc++.h>
using namespace std;

const int N=1010;
int now[N];
bool fallen[N];

int main()
{
    int n,m;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&m);
        scanf("%d",&now[i]);
        for (int j=2;j<=m;j++) {
            int x;
            scanf("%d",&x);
            if (x<=0) {
                now[i]+=x;
            } else {
                if (x<now[i]) {
                    fallen[i]=true;
                    now[i]=x;
                }
            }
        }
    }
    int sum=0;
    int fcnt=0,contcnt=0;
    for (int i=0;i<n;i++) {
        sum+=now[i];
        fcnt+=fallen[i];
        contcnt+=fallen[i]&fallen[(i+1)%n]&fallen[(i+2)%n];
    }
    printf("%d %d %d\n",sum,fcnt,contcnt);
    return 0;
}
