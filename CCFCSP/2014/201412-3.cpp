#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5010;
char op[N][8];
int pr[N],c[N];
bool disable[N];
map<int,ll> in,out;

int main()
{
    int n = 0;
    for (int i=1;;i++) {
        if (scanf("%s", op[i])==EOF) {
            break;
        }
        int x, y;
        if (strcmp(op[i], "cancel")==0) {
            scanf("%d", &x);
            disable[x] = true;
            disable[i] = true;
        } else {
            scanf("%d.%d %d", &x,&y, &c[i]);
            pr[i] = x*100+y;
        }
        n = i;
    }
    ll tot_in = 0;
    ll tot_out = 0;
    for (int i=1;i<=n;i++) {
        if (!disable[i]) {
            if (strcmp(op[i], "buy")==0) {
                in[pr[i]] += c[i];
                tot_in += c[i];
            } else {
                out[pr[i]] += c[i];
                // tot_out += c[i];
            }
        }
    }
    map<int,ll>::iterator it1 = in.begin();
    map<int,ll>::iterator it2 = out.begin();
    ll ans = 0;
    int pans = -1;
    while (it1!=in.end() || it2!=out.end()) {
        int pnow = 1e9;
        if (it1!=in.end()) {
            pnow = min(pnow, it1->first);
        }
        if (it2!=out.end()) {
            pnow = min(pnow, it2->first);
        }
        if (it2->first == pnow)  {
            tot_out += it2->second;
            ++it2;
        }
        if (min(tot_in, tot_out) >= ans) {
            ans = min(tot_in, tot_out);
            pans = pnow;
        }
        if (it1->first == pnow) {
            tot_in -= it1->second;
            ++it1;
        }
    }
    printf("%.2f %lld\n", pans/100.0, ans);
    return 0;
}
