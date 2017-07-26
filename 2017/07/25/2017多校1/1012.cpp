#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+5,MO=1e9+7;
int l[N],r[N];
ll fac[N],invf[N];

namespace fastIO {
	#define BUF_SIZE 100000
	//fread -> read
	bool IOerror = 0;
	inline char nc() {
		static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
		if(p1 == pend) {
			p1 = buf;
			pend = buf + fread(buf, 1, BUF_SIZE, stdin);
			if(pend == p1) {
				IOerror = 1;
				return -1;
			}
		}
		return *p1++;
	}
	inline bool blank(char ch) {
		return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
	}
	inline void read(int &x) {
		char ch;
		while(blank(ch = nc()));
		if(IOerror)
			return;
		for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
	}
	#undef BUF_SIZE
};

void init()
{
    fac[0]=invf[0]=invf[1]=1;
    for (int i=1;i<N;i++) {
        fac[i]=fac[i-1]*i%MO;
    }
    for (int i=2;i<N;i++) {
        invf[i]=(MO-MO/i)*invf[MO%i]%MO;
    }
    for (int i=2;i<N;i++) {
        invf[i]=invf[i]*invf[i-1]%MO;
    }
}

ll C(int n,int m)
{
    return fac[n]*invf[m]%MO*invf[n-m]%MO;
}

int st[N],ed[N];

int main()
{
    init();
    int n,cas=0;
    while (fastIO::read(n),!fastIO::IOerror) {
        for (int i=1;i<=n;i++) {
            fastIO::read(l[i]);
        }
        for (int i=1;i<=n;i++) {
            fastIO::read(r[i]);
        }
        ll ans=1;
        int top=0;
        st[++top]=1;
        ed[top]=n;
        for (int i=1;i<=n;i++) {
            if (l[i]!=st[top]) ans=0;
            if (r[i]>ed[top]) ans=0;
            st[++top]=i+1;
            ed[top]=r[i];
            ans=ans*C(r[i]-l[i],i-l[i])%MO;
            while (ed[top]<=i) {
                top--;
            }
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}
