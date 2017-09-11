#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MO=998244353;

struct Matrix {
    int r,c;
    ll e[2][2];
    Matrix() {}
    Matrix(int _r,int _c) {
        r=_r;c=_c;
        memset(e,0,sizeof(e));
    }
    Matrix(ll x) {
        r=c=2;
        memset(e,0,sizeof(e));
        for (int i=0;i<r;i++) {
            e[i][i]=x;
        }
    }
    Matrix operator *(const Matrix &b) {
        Matrix C(r,b.c);
        for (int i=0;i<r;i++) {
            for (int j=0;j<b.c;j++) {
                for (int k=0;k<c;k++) {
                    C.e[i][j]+=e[i][k]*b.e[k][j]%MO;
                    if (C.e[i][j]>=MO) C.e[i][j]%=MO;
                }
            }
        }
        return C;
    }
    void print()
    {
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                printf("%lld ",e[i][j]);
            }
            puts("");
        }
    }
};

Matrix fpow(Matrix x,ll n)
{
    Matrix res(1);
    while (n) {
        if (n&1) {
            res=res*x;
        }
        x=x*x;
        n>>=1;
    }
    return res;
}

int main()
{
    ll k;
    while (scanf("%lld",&k)!=EOF) {
        ll n=k+k+3;
        Matrix x(2,2);
        x.e[0][0]=x.e[0][1]=1;
        x.e[1][0]=1;
        x=fpow(x,n);
        Matrix ans(2,1);
        ans.e[0][0]=1;
        ans.e[1][0]=0;
        ans=x*ans;
        ll res=ans.e[1][0]-1;
        if (res<0) res+=MO;
        printf("%lld\n",res);
    }
    return 0;
}
