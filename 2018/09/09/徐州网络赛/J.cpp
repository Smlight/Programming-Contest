#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
const int N=250010;
int p[N],ra[N];
const int M=N*2;
struct Edge {
	int u,v,w;
} eg[M];
int tot;
vector<int> g[N];

int cmp(const Edge &p1,const Edge &p2)
{
	return p1.w>p2.w;
}

int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}

int Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return 0;
	if(ra[x]>ra[y]) {
		p[y]=x;
	} else {
		if(ra[x]==ra[y]) ra[y]++;
		p[x]=y;
	}
	return 1;
}

ll Kruskal(int kn,int km)
{
	ll rnt=0;
	for(int i=0;i<kn;i++) {
	    p[i]=i;
        ra[i]=0;
        g[i].clear();
    }
	sort(eg,eg+km,cmp);
	for(int i=0;i<km;i++) {
		if(Union(eg[i].u,eg[i].v)) {
			rnt+=eg[i].w;
//			printf("%d %d\n",eg[i].u,eg[i].v);
			g[eg[i].u].push_back(eg[i].v);
			g[eg[i].v].push_back(eg[i].u);
		}
	}
	return rnt;
}

const int VN = N, EN = M;
struct ST {
    //1 base, query O(1)
    int dp[VN << 1][20];
    int n;
    int arr[VN << 1];

    void make(int _n) {
        n = _n;
        for(int i = 1; i <= n; ++i) {
            dp[i][0] = i;
        }
        for(int j = 1; (1 << j) <= n; ++j) {
            for(int i = 1; (i + (1 << (j - 1))) <= n; ++i) {
                int l = dp[i][j - 1], r = dp[i + (1 << (j - 1))][j - 1];
                dp[i][j] = arr[l] < arr[r] ? l : r;
            }
        }
    }

    int query(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        int li = dp[l][k], ri = dp[r - (1 << k) + 1][k];
        return arr[li] < arr[ri] ? li : ri;
    }
} st;
int dis[VN], id[VN], la[VN << 1], lacnt;
bool vis[VN];

int lca(int u, int v) {
    int l = min(id[u], id[v]), r = max(id[u], id[v]);
    return la[st.query(l, r)];
}

void dfs(int v, int height)
{
//    printf("%d %d\n",v,height);
    vis[v] = true;
    id[v] = lacnt;
    dis[v] = height;
    st.arr[lacnt] = height;
    la[lacnt++] = v;
    for(auto x:g[v]) {
        if(!vis[x]) {
            dfs(x, height + 1);
            st.arr[lacnt] = height;
            la[lacnt++] = v;
        }
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    tot=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            char a[6],c[6];
            int b,d;
            scanf("%s%d%s%d",a,&b,c,&d);
            if (a[0]=='D') eg[tot++]={i*m+j,(i+1)*m+j,b};
            if (c[0]=='R') eg[tot++]={i*m+j,i*m+j+1,d};
        }
    }
    Kruskal(n*m,tot);
    memset(vis, 0x00, sizeof(vis));
    lacnt = 1;
    dfs(0,0);
    st.make(lacnt);
    int q;
    scanf("%d",&q);
    while (q--) {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        --a;--b;--c;--d;
        int x=a*m+b,y=c*m+d;
        int z=lca(x,y);
//        printf("%d %d %d\n",x,y,z);
        printf("%d\n",dis[x]+dis[y]-2*dis[z]);
    }
    return 0;
}
