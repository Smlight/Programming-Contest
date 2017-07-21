#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);

int sgn(long double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}

struct Point {
    int x,y;
    Point() {}
    Point(int _x,int _y):x(_x),y(_y) {}
    Point operator -(const Point &b) const {
        return Point(x - b.x,y - b.y);
    }
    int operator *(const Point &b) const {
        return x*b.x + y*b.y;
    }
    int operator ^(const Point &b)const {
        return x*b.y - y*b.x;
    }
} p[15];

int n,vis[15];
int ans;
int a[3],top;

double dist(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}

bool form_tri(double a,double b,double c)
{
    return sgn(a+b-c)>0&&sgn(a+c-b)>0&&sgn(b+c-a)>0;
}

double alen[3],blen[3];

bool equals(int i,int j,int k)
{
    blen[0]=dist(p[i],p[j]);
    blen[1]=dist(p[i],p[k]);
    blen[2]=dist(p[k],p[j]);
    if (sgn(alen[0]-blen[0])==0&&sgn(alen[1]-blen[1])==0&&sgn(alen[2]-blen[2])==0) {
        if (((p[j]-p[i])^(p[k]-p[i]))==((p[a[1]]-p[a[0]])^(p[a[2]]-p[a[0]]))) return true;
    }
    return false;
}

void dfs(int dep,int lst)
{
    if (dep>3) {
        alen[0]=dist(p[a[0]],p[a[1]]);
        alen[1]=dist(p[a[0]],p[a[2]]);
        alen[2]=dist(p[a[2]],p[a[1]]);
        if (!form_tri(alen[0],alen[1],alen[2])) return;
//        puts("A selected!");
        for (int i=1;i<=n;i++) if (!vis[i]) {
            for (int j=i+1;j<=n;j++) if (!vis[j]) {
                for (int k=j+1;k<=n;k++) if (!vis[k]) {
                    if (equals(i,j,k)) ans++;
                    else if (equals(i,k,j)) ans++;
                    else if (equals(j,i,k)) ans++;
                    else if (equals(j,k,i)) ans++;
                    else if (equals(k,i,j)) ans++;
                    else if (equals(k,j,i)) ans++;
                }
            }
        }
        return;
    }
    if (dep+n-lst<=3) return;
    for (int i=lst+1;i<=n;i++) {
        vis[i]=1;
        a[top++]=i;
        dfs(dep+1,i);
        top--;
        vis[i]=0;
    }
}

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        ans=top=0;
        memset(vis,0,sizeof(vis));
        dfs(1,0);
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
