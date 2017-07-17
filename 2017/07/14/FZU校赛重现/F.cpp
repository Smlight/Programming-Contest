#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        int ans=0;
        for (int i=1;i<=n;i++) {
            double gpa=0;
            int flag=0;
            for (int j=0;j<3;j++) {
                int x;
                scanf("%d",&x);
                if (x>=60) {
                    gpa+=(double)x/10-5;
                } else {
                    flag=1;
                }
            }
            if (!flag&&gpa>=9.0) {
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
