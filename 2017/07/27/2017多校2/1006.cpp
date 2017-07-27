#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MO=1e9+7;

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
        e[0][0]=e[1][1]=x;
        e[0][1]=e[1][0]=0;
    }
    Matrix operator *(const Matrix &b) {
        Matrix C(r,b.c);
        for (int i=0;i<r;i++) {
            for (int j=0;j<b.c;j++) {
                C.e[i][j]=0;
                for (int k=0;k<c;k++) {
                    C.e[i][j]+=e[i][k]*b.e[k][j]%MO;
                    C.e[i][j]%=MO;
                }
            }
        }
        return C;
    }
    Matrix operator %(const Matrix &b) {
        return *this;
    }
};

template<class TT>
TT fpow(TT x,ll n)
{
    TT res(1);
    while (n) {
        if (n&1) {
            res=res*x%MO;
        }
        x=x*x%MO;
        n>>=1;
    }
    return res;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        ll n,m,tmpm=-1;
        scanf("%lld%lld",&n,&m);
        if (n%2==0) {
            if (m==1) {
                puts("1");
                continue;
            } else {
                tmpm=m;
                n--;m=2;
            }
        }
        ll p=(fpow(2LL,n)-1+MO)%MO;
        ll q=((fpow(4LL,n/2)-1)*2+MO)%MO;
        q=MO-q*fpow(3LL,MO-2)%MO;
        Matrix x(2,2);
        x.e[0][0]=p;x.e[0][1]=q;
        x.e[1][0]=0;x.e[1][1]=1;
        x=fpow(x,m-1);
        Matrix ans(2,1);
        ans.e[0][0]=ans.e[1][0]=1;
        ans=x*ans;
        if (tmpm==-1) {
            printf("%lld\n",ans.e[0][0]);
        } else {
            p=(p*2+1)%MO;
            printf("%lld\n",ans.e[0][0]*2%MO*fpow(p,tmpm-2)%MO);
        }
    }
    return 0;
}
