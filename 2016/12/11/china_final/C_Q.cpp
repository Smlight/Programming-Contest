//By quailty, contest: 2016-2017 ACM-ICPC CHINA-Final, problem: (C) Mr. Panda and Strips, Accepted, #
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=1005;
const int MAXV=100005;
int c[MAXN],r[MAXN];
bool vis[MAXV];
vector<int>loc[MAXV];
set<pair<int,int> >st;
multiset<int>len;
inline int getMax()
{
    return (len.empty() ? 0 : *(--len.end()));
}
inline void setBlock(int x)
{
    auto itr=st.lower_bound(make_pair(x+1,0));
    if(itr==st.begin())return;
    itr--;
    int ml=x,mr=x;
    while(1)
    {
        if(itr->second<x)break;
        len.erase(len.lower_bound(itr->second-itr->first+1));
        ml=min(ml,itr->first);
        mr=max(mr,itr->second);
        if(itr==st.begin())
        {
            st.erase(itr);
            break;
        }
        else st.erase(itr--);
    }
    if(ml<x && st.find(make_pair(ml,x-1))==st.end())
        st.insert(make_pair(ml,x-1)),len.insert(x-ml);
    if(mr>x && st.find(make_pair(x+1,mr))==st.end())
        st.insert(make_pair(x+1,mr)),len.insert(mr-x);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&c[i]);
            loc[c[i]].push_back(i);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)vis[c[j]]=0;
            r[i]=i-1;
            while(r[i]<n && !vis[c[r[i]+1]])vis[c[++r[i]]]=1;
        }
        int res=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)vis[c[j]]=0;
            st.clear(),len.clear();
            for(int j=i+1;j<=n;j++)
            {
                st.insert(make_pair(j,r[j]));
                len.insert(r[j]-j+1);
            }
            res=max(res,getMax());
            for(int j=i;j>=1;j--)
            {
                if(vis[c[j]])break;
                vis[c[j]]=1;
                for(int k=0;k<(int)loc[c[j]].size();k++)
                    if(loc[c[j]][k]>i)setBlock(loc[c[j]][k]);
                res=max(res,getMax()+(i-j+1));
            }
        }
        printf("Case #%d: %d\n",ca,res);
        for(int i=1;i<=n;i++)
            loc[c[i]].clear();
    }
    return 0;
}
