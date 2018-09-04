#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MO=1e9+7;
struct Matrix {
    int r,c;
    ll e[3][3];
    Matrix() {}
    Matrix(int _r,int _c) {
        r=_r;c=_c;
        memset(e,0,sizeof(e));
    }
    Matrix(ll x) {
        r=c=3;
        memset(e,0,sizeof(e));
        for (int i=0;i<r;i++) {
            e[i][i]=x;
        }
    }
    Matrix operator *(const Matrix &b) {
        Matrix C(r,b.c);
        assert(c==b.r);
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

ll f[9];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int C,D,P,n;
        scanf("%lld%lld%d%d%d%d",&f[1],&f[2],&C,&D,&P,&n);
        if (n<=2) {
            printf("%lld\n",f[n]);
        } else {
            for (int i=3,j;i<=P;i=j+1) {
                int K=P/i;
                j=P/K;
                Matrix A(3,3);
                A.e[0][0]=D;
                A.e[0][1]=C;
                A.e[0][2]=K;
                A.e[1][0]=1;
                A.e[2][2]=1;
                Matrix X(3,1);
                X.e[0][0]=f[2];
                X.e[1][0]=f[1];
                X.e[2][0]=1;
                if (n>=i&&n<=j) {
                    A=fpow(A,n-i+1);
                    X=A*X;
                    printf("%lld\n",X.e[0][0]);
                } else {
                    A=fpow(A,j-i+1);
                    X=A*X;
                }
                f[2]=X.e[0][0];
                f[1]=X.e[1][0];
            }
            if (n>P) {
                Matrix A(3,3);
                A.e[0][0]=D;
                A.e[0][1]=C;
                A.e[1][0]=1;
                A.e[2][2]=1;
                Matrix X(3,1);
                X.e[0][0]=f[2];
                X.e[1][0]=f[1];
                X.e[2][0]=1;
                A=fpow(A,n-max(P,2));
                X=A*X;
                printf("%lld\n",X.e[0][0]);
            }
        }
    }
    return 0;
}