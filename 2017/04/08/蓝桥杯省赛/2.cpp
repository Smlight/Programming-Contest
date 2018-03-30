#include <bits/stdc++.h>
using namespace std;

const int mv[4]={1,2,7,8};
struct Node {
    int pos,dis;
    vector<int> sta;
    Node() {}
    Node(int a,int b,vector<int> c):pos(a),dis(b),sta(c) {}
};
set< vector<int> > allst;

int main()
{
    vector<int> st,ed;
    for (int i=0;i<9;i++) {
        st.push_back(i);
        ed.push_back(9-i);
    }
    ed[0]=0;
    queue<Node> Q;
    Q.push(Node(0,0,st));
    int ans=-1;
    while (!Q.empty()) {
        Node p=Q.front();
        Q.pop();

        /********print_detail********/
//        for (int i=0;i<9;i++) {
//            printf("%d",p.sta[i]);
//        }
//        puts("");
        /********print_detail********/

        pair<set< vector<int> >::iterator, bool> insres=allst.insert(p.sta);
        if (insres.second==false) continue;
        if (p.sta==ed) {
            ans=p.dis;
            break;
        }
        vector<int> now=p.sta;
        for (int i=0;i<4;i++) {
            int np=(p.pos+mv[i])%9;
            swap(now[p.pos],now[np]);
            Q.push(Node(np,p.dis+1,now));
            swap(now[p.pos],now[np]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
