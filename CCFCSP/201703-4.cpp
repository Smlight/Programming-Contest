#include <bits/stdc++.h>
using namespace std;

const int N=100110;
int p[N],ra[N];
const int M=1000005;
struct Edge {
	int u,v,w;
} edge[M];
int T,n,m;

int cmp(const Edge &p1,const Edge &p2) {
	return p1.w<p2.w;
}
int find(int x) {
	return p[x]==x?x:p[x]=find(p[x]);
}
int Union(int x,int y) {
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

int Kruskal(int kn,int km) {
	for(int i=1;i<=kn;i++) {
	     p[i]=i;
	     ra[i]=0;
    }
	sort(edge+1,edge+km+1,cmp);
	for(int i=1;i<=km;i++) {
		if(Union(edge[i].u,edge[i].v)) {
			if (find(kn)==find(1)) {
                return edge[i].w;
			}
		}
	}
	return -1;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) {
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    printf("%d\n",Kruskal(n,m));
    return 0;
}
