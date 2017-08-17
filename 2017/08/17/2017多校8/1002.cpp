#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6,MO=1e9+7;
ll ans[N+5],sum[N+5];
bool check[N+5];
int mu[N+5];
int prime[90000];

void get_mu()
{
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= N; i++) {
        if( !check[i] ) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; j++) {
            if(i * prime[j] > N) break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}

void init()
{
    for (int j=1;j<=N;j++) {
        ans[j]++;
        for (int i=j;i<=N;i+=j) {
            ans[i+1]++;
        }
    }
    for (int i=1;i<=N;i++) {
        ans[i]=(ans[i]+ans[i-1])%MO;
    }
    for (int j=1;j<=N;j++) {
        if (mu[j]==0) continue;
        for (int i=j;i<=N;i+=j) {
            if (mu[j]>0) {
                sum[i]=(sum[i]+ans[i/j])%MO;
            } else {
                sum[i]=(sum[i]-ans[i/j]+MO)%MO;
            }
        }
    }
    for (int i=1;i<=N;i++) {
        sum[i]=(sum[i]+sum[i-1])%MO;
    }
}

int main()
{
    get_mu();
    init();
    int n;
    while (scanf("%d",&n)!=EOF) {
        printf("%d\n",sum[n]);
    }
    return 0;
}
