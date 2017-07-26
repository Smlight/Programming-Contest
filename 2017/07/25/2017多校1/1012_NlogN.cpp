#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
const int N=1e6+5,MO=1e9+7;
int l[N],r[N];
ll fac[N],invf[N];
map<PII,int> mp;
ll ans;

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

void dfs(int L,int R)
{
    if (ans==0) return;
    if (R<L) return;
    auto pos=mp.find(PII(L,R));
    if (pos==mp.end()) {
        ans=0;
        return;
    }
    int x=pos->second;
    ans*=C(R-L,x-L);
    ans%=MO;
    dfs(L,x-1);
    dfs(x+1,R);
}

int main()
{
    init();
    int n,cas=0;
    while (fastIO::read(n),!fastIO::IOerror) {
        for (int i=1;i<=n;i++) {
            fastIO::read(l[i]);
        }
        mp.clear();
        for (int i=1;i<=n;i++) {
            fastIO::read(r[i]);
            mp[PII(l[i],r[i])]=i;
        }
        ans=1;
        dfs(1,n);
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}
