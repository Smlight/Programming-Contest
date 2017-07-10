#include <bits/stdc++.h>
using namespace std;

const int N=20000;
int a[N];
vector<int> ans[200],tmp;

int main()
{
    int T,n,m;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) {
            scanf("%d",a+i);
        }
        int sp=sqrt(n);
        for (int k=1;k<=sp;k++) {
            ans[k].clear();
            for (int i=0;i<n;i+=k) {
                ans[k].push_back(a[i]);
            }
            sort(ans[k].begin(),ans[k].end(),greater<int>());
        }
        while (m--) {
            int k,s;
            scanf("%d%d",&k,&s);
            if (k<=sp) {
                if (s<=ans[k].size()) {
                    printf("%d\n",ans[k][s-1]);
                } else {
                    puts("-1");
                }
            } else {
                tmp.clear();
                for (int i=0;i<n;i+=k) {
                    tmp.push_back(a[i]);
                }
                sort(tmp.begin(),tmp.end(),greater<int>());
                if (s<=tmp.size()) {
                    printf("%d\n",tmp[s-1]);
                } else {
                    puts("-1");
                }
            }
        }
    }
    return 0;
}
