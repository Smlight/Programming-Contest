#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5+10;
int cover[maxn];
ll sum[maxn],X[maxn];
struct Unit {
    ll xl,xr,y;
    int val;
    bool operator <(const Unit &R) const {
        return y<R.y;
    }
} line[maxn];

void push_up(int l, int r, int root)
{
    if (cover[root]) {
        sum[root] = X[r+1] - X[l];
    } else if (l==r) {
        sum[root] = 0;
    } else {
        sum[root] = sum[root<<1] + sum[root<<1|1];
    }
}

void update(int l,int r,int root,int L,int R,int val)
{
    if (L<=l&&r<=R) {
        cover[root] += val;
        push_up(l,r,root);
        return;
    }
    int middle = (l+r)>>1;

    if (R<=middle) {
        update(l,middle,root<<1,L,R,val);
    } else if (L>middle) {
        update(middle+1,r,root<<1|1,L,R,val);
    } else {
        update(l, middle, root<<1, L, middle, val);
        update(middle+1, r, root<<1|1, middle+1, R, val);
    }
    push_up(l,r,root);
}

int find(ll x,int k)
{
    int low = 1, high = k,middle;
    while(low<=high) {
        middle = (low+high)/2;
        if (X[middle]==x) {
            return middle;
        } else if (X[middle]>x) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
}

int main()
{
    int n,num,i,j,k;
    ll x1,x2,y1,y2;
    Unit now;
    while (scanf("%d",&n)!=EOF) {
        if (n==0) {
            puts("*");
            break;
        }
        memset(cover,false,sizeof(cover));
        memset(sum,0,sizeof(sum));
        num = 0;
        for(i=1; i<=n; i++) {
            scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
            now.xl = x1;
            now.xr = x2;
            now.y = y1;
            now.val = 1;
            line[++num] = now;
            X[num] = x1;
            now.y = y2;
            now.val = -1;
            line[++num] = now;
            X[num] = x2;
        }
        sort(X+1,X+1+num);
        sort(line+1,line+1+num);
        k = 1;
        for(i=2; i<=num; i++) {
            if (X[i]!=X[i-1]) {
                X[++k] = X[i];
            }
        }
        ll ans = 0;
        for(i=1; i<num; i++) {
            int left = find(line[i].xl,k);
            int right = find(line[i].xr,k) - 1;
            update(1,k,1,left,right,line[i].val);
            ans += sum[1] * (line[i+1].y-line[i].y);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
