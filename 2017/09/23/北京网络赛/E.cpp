#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Point {
    ll x,y;
    Point() {}
    Point(ll a,ll b):x(a),y(b) {}
    Point operator +(const Point &R) {
        return Point(x+R.x,y+R.y);
    }
    Point operator -(const Point &R) {
        return Point(x-R.x,y-R.y);
    }
    ll operator *(const Point &R) {
        return x*R.x+y*R.y;
    }
    ll operator ^(const Point &R) {
        return x*R.y-y*R.x;
    }
    bool operator <(const Point &R) const {
        return x<R.x||(x==R.x&&y<R.y);
    }
} p[110];
struct Line {
    Point s,e;
    Line() {}
    Line(Point _s,Point _e):s(_s),e(_e) {}
};
char ans[110];
int T,n;

bool threeonline()
{
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) if (j!=i) {
            for (int k=1;k<=n;k++) if (k!=i&&k!=j) {
                Point AB=p[j]-p[i];
                Point AC=p[k]-p[i];
                if ((AB^AC)==0&&AB*AC<0) {
                    ans[i]='B';
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%lld%lld",&p[i].x,&p[i].y);
            ans[i]='A';
        }
        if (threeonline()) {
            puts("YES");
            ans[n+1]=0;
            puts(ans+1);
        } else {
            puts("NO");
        }
    }
    return 0;
}
