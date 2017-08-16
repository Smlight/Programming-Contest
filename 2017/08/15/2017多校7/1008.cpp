#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e4+5;
struct Point {
    ll x,y,v;
    Point() {}
    Point(ll _x,ll _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }
//叉积
    ll operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
//点积
    ll operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
//绕原点旋转角度B（弧度值），后x,y的变化
    void transXY(ll B)
    {
        ll tx = x,ty = y;
        x = tx*cos(B) - ty*sin(B);
        y = tx*sin(B) + ty*cos(B);
    }
} p[N],O;

ll dist(const Point &a,const Point &b)
{
    return (a-b)*(a-b);
}

bool _cmp(const Point &p1,const Point &p2)
{
    ll tmp = (p1-O)^(p2-O);
    if(tmp > 0)return true;
    else if(tmp== 0 && dist(p1,O) - dist(p2,O) <= 0)
        return true;
    else return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    O={0,0};
    int T,n;
    cin>>T;
    while (T--) {
        cin>>n;
        ll par=0,sum=0;
        for (int i=1;i<=n;i++) {
            cin>>p[i].x>>p[i].y>>p[i].v;
            sum+=p[i].v;
        }
        sort(p+1,p+n+1,_cmp);
        int j=1;
        ll ans=0;
        for (int i=1;i<=n;i++) {
            while (((p[i]-O)^(p[j]-O))>=0) {
                par+=p[j].v;
                if (++j>n) j=1;
                if (j==i) break;
            }
            ans=max(ans,par*(sum-par));
            par-=p[i].v;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
