#include <bits/stdc++.h>
using namespace std;

const int M=125260;
int a[M];
multiset<int> ss;

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

int main()
{
    int m,x;
    while (fastIO::read(m),!fastIO::IOerror) {
        for (int i=1;i<=m;i++) {
            fastIO::read(x);
            ss.insert(x);
        }
        int n=0;
        a[++n]=*ss.begin();
        ss.erase(ss.begin());
        while (!ss.empty()) {
            a[++n]=*ss.begin();
            ss.erase(ss.begin());
            for (int i=1;i<n;i++) {
                ss.erase(ss.find(a[i]+a[n]));
            }
        }
        printf("%d\n",n);
        for (int i=1;i<=n;i++) {
            printf("%d%c",a[i]," \n"[i==n]);
        }
    }
    return 0;
}
