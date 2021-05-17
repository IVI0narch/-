#include <iostream>
#include "vector"
using namespace std;

int main() {
    int n, m, gn=0, money = 0, gg;
    cin>>n;
    vector<int> k(n);
    for (int i = 0; i < n; ++i) {
        cin>>k[i];
    }
    cin>>m;
    vector<int> g(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; k[i]>0; k[i]--) {
            gg=0;
            for (int i = 0; i < m; i++) {
                if(g[i]==0){
                    gg++;
                }
            }
            if (gg>0){
                gn = (gn+i+2)%m;
                g[gn]++;
            }else{
                for (int i = 0; i < n; i++) {
                    money+=k[i];
                }
                cout<<"YES "<<money;
                return 0;
            }

        }
    }
    gg=0;
    for (int i = 0; i < m; i++) {
        if(g[i]==0){
            gg++;
        }
    }
    for (int i = 0; i < n; i++) {
        money+=k[i];
    }
    if(gg>0){
        cout<<"NO "<<gg;
    }else{
        cout<<"YES "<<money;
    }
    return 0;
}
