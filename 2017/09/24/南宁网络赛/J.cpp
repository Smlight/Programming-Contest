#include <bits/stdc++.h>
using namespace std;

typedef pair<string,int> psi;
queue<psi> Q;
unordered_set<string> vis;
int n;
char s[20],t[20];

int bfs()
{
    string goal(t);
    while (!Q.empty()) Q.pop();
    Q.push(make_pair(s,0));
    vis.clear();
    vis.insert(s);
    while (!Q.empty()) {
        auto p=Q.front();
        Q.pop();
        for (int i=2;i<=n;i++) {
            string tmp(p.first);
            swap(tmp[0],tmp[i-1]);
//            puts(tmp.c_str());
            if (vis.find(tmp)!=vis.end()) continue;
            vis.insert(tmp);
            if (tmp==goal) {
                return p.second+1;
            }
            Q.push(make_pair(tmp,p.second+1));
        }
    }
    return -1;
}

int main()
{
    while (scanf("%d",&n)!=EOF) {
        for (int P=1;P<=5;P++) {
            scanf("%s%s",s,t);
            if (strcmp(s,t)==0) {
                puts("0");
            } else {
                printf("%d\n",bfs());
            }
        }
    }
    return 0;
}
