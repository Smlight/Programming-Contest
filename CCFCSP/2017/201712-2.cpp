#include <bits/stdc++.h>
using namespace std;

const int N=1010;
int n,k;
int dead[N];

int main()
{
    scanf("%d%d",&n,&k);
    int m=n,p=0;
    int tot=0;
    while (m>1) {
        while (true) {
            if (++p==n+1) p=1;
            while (dead[p]) {
                if (++p==n+1) p=1;
            }
            ++tot;
            if (tot%k==0||tot%10==k) {
                dead[p]=1;
                --m;
                break;
            }
        }
    }
    int ans=min_element(dead+1,dead+n+1)-dead;
    printf("%d\n",ans);
    return 0;
}
