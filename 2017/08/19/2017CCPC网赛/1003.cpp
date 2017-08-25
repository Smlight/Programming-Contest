#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=3010;
int a[N];

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
using namespace fastIO;

int main()
{
    int T;read(T);
    while (T--) {
        int n;read(n);
        ll ans=(ll)n*(n-1)*(n-2)/6,sum=0;
        memset(a,0,sizeof(a));
        for (int i=1;i<n;i++) {
            for (int j=i+1;j<=n;j++) {
                int k;read(k);
                if (k==1) {
                    a[i]++;a[j]++;
                }
            }
        }
        for (int i=1;i<=n;i++) {
            sum+=1LL*a[i]*(n-a[i]-1);
        }
        ans-=sum/2;
        puts(ans?"Bad Team!":"Great Team!");
    }
    return 0;
}
