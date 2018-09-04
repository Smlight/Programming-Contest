#include <bits/stdc++.h>
using namespace std;

const int MAX=20000000;
int tot = 0;
int prime[MAX/10];
bool check[MAX+5];
int ans[MAX+5];
int lowp[MAX+5];
int po[MAX+5];

int main()
{
    lowp[1] = 0;
    po[1] = 0;
    int tot = 0;
    for(int i = 2; i <= MAX; i++) {
        if( !check[i] ) {
            prime[tot++] = i;
            lowp[i] = i;
            po[i] = 1;
        }
        for(int j = 0; j < tot; j++) {
            if(i * prime[j] > MAX) break;
            check[i * prime[j]] = true;
            lowp[i * prime[j]] = prime[j];
            if (lowp[i] == prime[j]) {
                po[i * prime[j]] = po[i] + 1;
            } else {
                po[i * prime[j]] = 1;
            }
            if( i % prime[j] == 0) break;
        }
    }
    ans[1]=1;
    for (int i=2;i<=MAX;i++) {
        if (po[i]>2) {
            ans[i]=0;
        } else if (po[i]==2) {
            ans[i]=ans[i/(lowp[i]*lowp[i])];
        } else {
            ans[i]=ans[i/lowp[i]]*2;
        }
    }
    for (int i=1;i<=MAX;i++) ans[i]+=ans[i-1];
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
