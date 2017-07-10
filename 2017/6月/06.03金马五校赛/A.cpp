#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> alls;
char s[10]="DEEST";

int main()
{
    alls.push_back(s);
    for (int i=1;i<60;i++) {
        next_permutation(s+0,s+5);
        alls.push_back(s);
    }
    int n;
    while (scanf("%d",&n)!=EOF) {
        puts(alls[n-1].c_str());
    }
    return 0;
}
