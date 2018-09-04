#include <bits/stdc++.h>
using namespace std;

const int N=100005;
const int M=10000005;
unsigned X,Y,Z;
//struct Oper {
//    int l,r,v;
//} op[M];
int key[N<<2];
int L,R,D;

unsigned RNG61()
{
    X^=X<<11;
    X^=X>>4;
    X^=X<<5;
    X^=X>>14;
    unsigned W=X^Y^Z;
    X=Y;
    Y=Z;
    return Z=W;
}

#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r

void push_down(int rt,int l,int r)
{
    if (key[rt]) {
        key[rt<<1]=max(key[rt<<1],key[rt]);
        key[rt<<1|1]=max(key[rt<<1|1],key[rt]);
    }
}

void build(int rt,int l,int r)
{
    key[rt]=0;
    if (l==r) {
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}

void update(int rt,int l,int r)
{
    if(key[rt] > D) return;
    if (L<=l&&r<=R) {
        key[rt]=max(key[rt],D);
        return;
    }
    push_down(rt,l,r);
    int m=(l+r)>>1;
    if (L<=m) update(lson);
    if (m<R) update(rson);
}

long long ans;
void calc(int rt,int l,int r)
{
    if (l==r) {
        ans^=(long long)l*key[rt];
        return;
    }
    push_down(rt,l,r);
    int m=(l+r)>>1;
    calc(lson);
    calc(rson);
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m;
        scanf("%d%d%u%u%u",&n,&m,&X,&Y,&Z);
//        printf("%d %d %d %d %d\n",n,m,X,Y,Z);
        build(1,1,n);
        for (int i=1;i<=m;i++) {
            L=RNG61()%n+1;
            R=RNG61()%n+1;
            D=RNG61()%(1<<30);
            if (L>R) swap(L,R);
            update(1,1,n);
        }
        ans=0;
        calc(1,1,n);
        printf("%lld\n",ans);
    }
    return 0;
}