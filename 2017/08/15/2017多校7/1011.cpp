#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main()
{
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    int i=2,k=1;
    while (v.size()<10000000) {
        for (int j=1;j<=v[i];j++) {
            v.push_back(k);
        }
        i++;
        k=3-k;
    }
    int T,n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        printf("%d\n",v[n-1]);
    }
    return 0;
}
