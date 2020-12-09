#include <bits/stdc++.h>
using namespace std;

bool mp[105][105];

int main()
{
    int n;
    scanf("%d",&n);
    while (n--) {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        --c;--d;
        for (int i=a;i<=c;i++) {
            for (int j=b;j<=d;j++) {
                mp[i][j]=true;
            }
        }
    }
    int ans=0;
    for (int i=0;i<101;i++) {
        for (int j=0;j<101;j++) {
            ans+=mp[i][j];
        }
    }
    printf("%d\n",ans);
    return 0;
}
