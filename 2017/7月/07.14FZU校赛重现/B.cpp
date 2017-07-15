#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int N=1005;
char s[N][14];
int p[N],ra[N],size[N];
const int M=1000005;
struct Edge {
	int u,v,w;
	Edge() {}
	Edge(int a,int b,int c):u(a),v(b),w(c) {}
} edge[M];

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
	int rnt=0;
	for(int i=1;i<=kn;i++) {
	     p[i]=i;
	     ra[i]=0;
    }
	sort(edge+1,edge+km+1,cmp);
	for(int i=1;i<=km;i++) {
		if(Union(edge[i].u,edge[i].v)) {
			rnt+=edge[i].w;
		}
	}
	return rnt;
}

int main()
{
    int n,m,w;
    while (scanf("%d%d%d",&n,&m,&w)!=EOF) {
        int tot=0;
        for (int i=1;i<=n;i++) {
            scanf("%s",s[i]);
            for (int j=1;j<i;j++) {
                int c=0;
                for (int k=0;k<m;k++) {
                    c+=(s[j][k]!=s[i][k]);
                }
                edge[++tot]=Edge(j,i,c*w);
            }
            edge[++tot]=Edge(n+1,i,m);
        }
        printf("%d\n",Kruskal(n+1,tot));
    }
    return 0;
}
