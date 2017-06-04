#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    long long n,m;
    while (scanf("%lld%lld",&n,&m)!=EOF) {
        if ((n+m)%2==0) {
            puts("YES");
        } else {
            if (abs(m-n)>=3) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    return 0;
}
