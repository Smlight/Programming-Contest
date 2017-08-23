#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,int> PLI;
const int N=100010;
struct Edge {
    int go,val,next;
} eg[N*5];
int last[N<<1],tot;
ll d[N<<1];
int vis[N<<1],st[N];
set<int> re[N<<1];
int T,n,m,k,cas=0;

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

void dij(int S)
{
    priority_queue< PLI,vector<PLI>,greater<PLI> > q;
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[S]=0; q.push(PLI(d[S],S));
    while (!q.empty()){
        PLI tmp=q.top();
        q.pop();
        int u=tmp.second;
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=last[u];i!=-1;i=eg[i].next) {
            int &v=eg[i].go;
//            printf("%d %d\n",u,v);
            if (u<=n&&v>n&&st[v-n]) {
                if (re[u+n].find(v-n)!=re[u+n].end()) continue;
            }
            if (d[v]>d[u]+eg[i].val) {
                re[v].insert(u);
                d[v]=d[u]+eg[i].val;
                q.push(PLI(d[v],v));
            }
        }
    }
}

void addedge(int x,int y,int z)
{
    eg[tot]={y,z,last[x]};
    last[x]=tot++;
}

int main()
{
    fastIO::read(T);
    while (T--) {
        fastIO::read(n);
        fastIO::read(m);
        tot=0;
        memset(last,-1,sizeof(last));
        for (int i=1;i<=m;i++) {
            int x,y,z;
            fastIO::read(x);
            fastIO::read(y);
            fastIO::read(z);
            addedge(x,n+y,z);
        }
        fastIO::read(k);
        memset(st,0,sizeof(st));
        int S=0,T=n+n+1;
        for (int i=1;i<=k;i++) {
            int x;
            fastIO::read(x);
            st[x]=1;
            addedge(S,x,0);
            addedge(n+x,T,0);
        }
        for (int i=1;i<=n;i++) {
            addedge(n+i,i,0);
        }
        for (int i=0;i<=n+n+1;i++) {
            re[i].clear();
        }
        dij(S);
        printf("Case #%d: %lld\n",++cas,d[T]);
    }
    return 0;
}
