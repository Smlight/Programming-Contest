#include <bits/stdc++.h>
using namespace std;

const int N=100010;
string s[N];
bool vis[N];

namespace AC_DFA {
    const int Csize=27,AN=N;
    int tot,son[AN][Csize],ed[AN],fail[AN],q[AN];
    void Initialize() {
        memset(fail,0,sizeof(int)*(tot+1));
        memset(ed,0,sizeof(int)*(tot+1));
        for (int i=0;i<=tot;i++) {
            for (int j=0;j<Csize;j++) {
                son[i][j]=0;
            }
        }
        tot=0; fail[0]=-1;
    }
    inline int Tr(char ch) {
        return ch-'a';
    }
    bool Insert(const string &s,int k) {
        int x=0;
        for (int l=s.length(),i=0,w;i<l;i++) {
            if (!son[x][w=Tr(s[i])]) {
                son[x][w]=++tot;
            }
            x=son[x][w];
        }
        if (ed[x]) return false;
        ed[x]=k; return true;
    }
    void MakeFail() {
        int h=1,t=0,i,j,x;
        for (i=0;i<Csize;i++) {
            if (son[0][i]) q[++t]=son[0][i];
        }
        while (h<=t) {
            for (x=q[h++],i=0;i<Csize;i++) {
                if (son[x][i]) {
                    fail[son[x][i]]=son[fail[x]][i];
                    q[++t]=son[x][i];
                } else {
                    son[x][i]=son[fail[x]][i];
                }
            }
        }
    }
    void Find(const string &s) {
        for (int l=s.length(),i=0,x=0,w;i<l;i++) {
            while (x&&!son[x][Tr(s[i])]) x=fail[x];
            x=son[x][Tr(s[i])];
            for (int j=x;j;j=fail[j]) {
                if (ed[j]) {
                    vis[ed[j]]=1;
                }
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T,n;
    cin>>T;
    while (T--) {
        cin>>n;
        int mx=0,id;
        for (int i=1;i<=n;i++) {
            cin>>s[i];
			if (s[i].length()>mx) {
				mx=s[id=i].length();
			}
        }
        int ok=1;
        for (int i=1;i<=n;i++) {
            if (s[i].length()==mx&&s[i]!=s[id]) {
                ok=0;
                break;
            }
        }
        if (!ok) {
            cout<<"No\n";
            continue;
        }
        using namespace AC_DFA;
        Initialize();
        for (int i=1;i<=n;i++) vis[i]=0;
        int t=1;
        for (int i=1;i<=n;i++) {
            if (s[i].length()==mx) continue;
            if (Insert(s[i],t)) t++;
        }
        MakeFail();
        Find(s[id]);
        for (int i=1;i<t;i++) {
            if (!vis[i]) {
                ok=0;
                break;
            }
        }
        cout<<(ok?s[id]:"No")<<"\n";
    }
    return 0;
}
