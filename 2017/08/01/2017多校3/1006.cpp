#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 1000;
const int MO = 998244353;
const ll P = MO; // NTT费马质数
const ll G = 3; // P的原根,当且仅当 G^(P-1) = 1 % P
const int NUM = 23;
int fac[N],facinv[N];
int n, m;

ll mul(ll x,ll y)
{
//return (x * y - (long long)(x / (long double)P * y + 1e-3) * P + P) % P;
    return x * y % P;
}

ll fpow(ll a,ll b)
{
    ll res = 1,tmp = a;
    while(b) {
        if(b &1) res = res * tmp % P;
        tmp = tmp * tmp % P;
        b >>= 1;
    }
    return res;
}

void init()
{
    fac[0]=1;
    for (int i=1;i<N;i++) {
        fac[i]=1LL*i*fac[i-1]%MO;
    }
    facinv[0]=facinv[1]=1;
    for (int i=2;i<N;i++) {
        facinv[i]=1LL*(MO-MO/i)*facinv[MO%i]%MO;
    }
    for (int i=1;i<N;i++) {
        facinv[i]=1LL*facinv[i-1]*facinv[i]%MO;
    }
}

ll wn[NUM];
ll a[2*N],b[2*N],c[N];

void GetWn()
{
    for(int i = 0; i< NUM; i++) {
        int t = 1 << i;
        wn[i] = fpow(G, (P - 1) / t);
    }
}

void Rader(ll a[], int len)
{
    int j = len >> 1;
    for(int i=1; i<len-1; i++) {
        if(i < j) swap(a[i], a[j]);
        int k = len >> 1;
        while(j >= k) {
            j -= k;
            k >>= 1;
        }
        if(j < k) j += k;
    }
}

void NTT(ll a[], int len, int on)
{
    Rader(a, len);
    int id = 0;
    for(int h = 2; h <= len; h <<= 1) {
        id++;
        for(int j = 0; j < len; j += h) {
            ll w = 1;
            for(int k = j; k < j + h / 2; k++) {
                ll u = a[k];
                ll t = mul(w,a[k + h / 2]);
                a[k] = (u + t) % P;
                a[k + h / 2] = ((u - t) % P + P) % P;
                w = mul(w,wn[id]);
            }
        }
    }
    if(on == -1) {
        for(int i = 1; i < len / 2; i++)
            swap(a[i], a[len - i]);
        ll Inv = fpow(len, P - 2);
        for(int i = 0; i < len; i++)
            a[i] = mul(a[i],Inv);
    }
}

void Conv(ll a[], ll b[], int n)
{
    NTT(a, n, 1);
    NTT(b, n, 1);
    for (int i = 0; i < n; i++) {
        a[i] = mul(a[i],b[i]);
    }
    NTT(a, n, -1);
}

int main()
{
    GetWn();
    init();
    while (scanf("%d",&n) != EOF) {
        for (int i = 0; i <= n; i++) {
            scanf("%d", &c[i]);
        }
        int sum = 0;
        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            int x;
            scanf("%d", &x);
            sum = (sum - x + MO) % MO;
        }
        int len = 1;
        while (len < 2 * (n + 1)) len <<= 1;
        int now = 1;
        for (int i = 0; i <= n; i++) {
            a[i] = 1LL * now * facinv[i] % MO;
            now = 1LL * now * sum % MO;
            b[i] = c[n - i] * fac[n - i] % MO;
        }
        for (int i = n + 1; i < len; i++) {
            a[i] = b[i] = 0;
        }
        Conv(a,b,len);
        for (int i = 0; i <= n; i++) {
            printf("%lld ",a[n - i] * facinv[i] % MO);
        }
        puts("");
    }
    return 0;
}
