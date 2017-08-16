#include <bits/stdc++.h>
using namespace std;

vector<int> v,vx;

int main()
{
    v.push_back(1);
    v.push_back(2);
    while (v.size()<10000000) {
        int k=1;
        vx.clear();
        for (int i=0;i<v.size();i++) {
            for (int j=0;j<v[i];j++) {
                vx.push_back(k);
            }
            k=3-k;
        }
        v=vx;
    }
    int T,n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        printf("%d\n",v[n-1]);
    }
    return 0;
}
