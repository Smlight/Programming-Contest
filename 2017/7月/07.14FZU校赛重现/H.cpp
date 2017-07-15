#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int N=1000010;
int a[N],L[N],R[N];
int sta[2][N],top[2],del[N];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=1;i<=n;i++) {
            scanf("%d",a+i);
            L[i]=i-1;
            R[i]=i+1;
        }
        int head=1,tail=n+1;
        R[tail]=tail;
        memset(del,0,sizeof(del));
        top[0]=0;
        for (int i=R[head];i!=tail;i=R[i]) {
            if (a[L[i]]>a[i]) {
                sta[0][++top[0]]=i;
                del[i]=1;
            }
        }
        int ans=0;
        int pre=0,now=1;
        while (top[pre]) {
            ans++;
            top[now]=0;
            for (int j=1;j<=top[pre];j++) {
                int i=sta[pre][j];
                if (R[i]!=tail&&!del[R[i]]&&a[L[i]]>a[R[i]]) {
                    sta[now][++top[now]]=R[i];
                    del[R[i]]=1;
                }
                R[L[i]]=R[i];
                L[R[i]]=L[i];
            }
            swap(pre,now);
        }
        printf("%d\n",ans);
        for (int i=head;i!=tail;i=R[i]) {
            printf("%d%c",a[i],R[i]==tail?'\n':' ');
        }
    }
    return 0;
}
