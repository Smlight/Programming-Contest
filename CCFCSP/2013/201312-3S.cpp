#include <bits/stdc++.h>
using namespace std;

const int N=1010,INF=1<<30;
int a[N],L[N],R[N];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",a+i);
    }
    stack<int> st;
    for (int i=0;i<n;i++) {
        while (!st.empty()&&a[st.top()]>=a[i]) st.pop();
        if (st.empty()) L[i]=-1;
        else L[i]=st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i=n-1;i>0;i--) {
        while (!st.empty()&&a[st.top()]>=a[i]) st.pop();
        if (st.empty()) R[i]=n;
        else R[i]=st.top();
        st.push(i);
    }
    int ans=-1;
    for (int i=0;i<n;i++) {
        ans=max(ans,a[i]*(R[i]-L[i]-1));
    }
    printf("%d\n",ans);
    return 0;
}
