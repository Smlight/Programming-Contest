#include <bits/stdc++.h>
using namespace std;

const int N=111;
string temp[N],s;
map<string,string> mp;
char buff[N];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("\n");
    for (int i=0;i<n;i++) {
        gets(buff);
        temp[i]=buff;
    }
    for (int i=0;i<m;i++) {
        gets(buff);
        int p=0;
        while (buff[p]!=' ') ++p;
        buff[strlen(buff)-1]=0;
        buff[p]=0;
        string key(buff);
        string val(buff+p+2);
        mp["{{ "+key+" }}"]=val;
    }
    for (int i=0;i<n;i++) {
        int cnt=0;
        string::iterator pos(temp[i].end());
        for (string::iterator it=temp[i].begin();it!=temp[i].end();++it) {
            if (*it=='{') {
                ++cnt;
                if (pos==temp[i].end()) pos=it;
            } else if (*it=='}') {
                if (--cnt==0) {
                    string key(pos,it+1);
                    if (mp.find(key)==mp.end()) {
                        mp[key]="";
                    }
                }
            }
        }
    }
    for (map<string,string>::iterator it=mp.begin();it!=mp.end();++it) {
        for (int i=0;i<n;i++) {
            int pos=temp[i].find(it->first);
            while (pos!=string::npos) {
                temp[i].replace(pos,it->first.length(),it->second);
                pos=temp[i].find(it->first);
            }
        }
    }
    for (int i=0;i<n;i++) {
        puts(temp[i].c_str());
    }
    return 0;
}
