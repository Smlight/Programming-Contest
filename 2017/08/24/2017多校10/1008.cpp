#include  <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
struct Edge {
    int to,next;
} eg[MAXN<<1];
int head[MAXN],tot;
bool vis[MAXN];
int T,n,m,k,x;

namespace fastIO {
	#define BUF_SIZE 40000000
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

void addedge(int u,int v)
{
    eg[tot].to = v;
    eg[tot].next = head[u];
    head[u] = tot++;
}

void dfs(int u,int fa)
{
    for (int i=head[u];i!=-1;i=eg[i].next) {
        int &v=eg[i].to;
        if (v==fa) continue;
        dfs(v,u);
        if (!vis[u]&&!vis[v]) {
            m+=2;
            vis[u]=vis[v]=true;
        }
    }
}

int main()
{
    fastIO::read(T);
    while (T--) {
        fastIO::read(n);
        fastIO::read(k);
        tot=m=0;
        memset(head,-1,sizeof(int)*(n+1));
        memset(vis,0,sizeof(bool)*(n+1));
        for (int i=2;i<=n;i++) {
            fastIO::read(x);
            addedge(x,i);
            addedge(i,x);
        }
        dfs(1,0);
        int ans;
        if (k>m) {
            ans=(k-m)+m/2;
        } else {
            ans=(k+1)/2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
