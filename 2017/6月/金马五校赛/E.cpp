#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

char s[100];

int main()
{
    while (scanf("%s",s)!=EOF) {
        int n=strlen(s);
        int ans=0;
        for (int k=0;k<n;k++) {
            int i=k,j=k;
            while (i>=0&&j<n&&s[i]==s[j]) i--,j++;
            ans=max(ans,j-i-1);
        }
        for (int k=0;k<n-1;k++) {
            int i=k,j=k+1;
            while (i>=0&&j<n&&s[i]==s[j]) i--,j++;
            ans=max(ans,j-i-1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
