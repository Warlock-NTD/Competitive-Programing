// type of Dynamic Bitmarks Programming Session

#include <bits/stdc++.h>

using namespace std;
int m,n;

inline bool check(int &a, int &b) {
for (int i = 1; i < n; ++i) {
    int a_ = ~a; int b_ = ~b;
    int cl = 1<<i; int cr = 1<<(i-1);
    bool c1 = (cl & a)&& (cr & a) && (cl & b) && (cr & b);
    bool c2 = (a_ & cl) && (b_ & cl) && (a_ & cr) && (b_ & cr);
    if(c1 || c2)    return 0;
}

return 1;
}


int main(int argc, char*argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>m>>n;
        if (n>m)    swap(m,n);
        vector<int> l(1<<n);
        vector<vector<int>> mp (m,l);
        for(int i = 0 ; i < (1<<n); ++i) {
            mp[0][i] = 1;
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 0; j < (1<<n); ++j) {
                for(int k = 0; k < (1<<n); ++k) {
                    if(check(j,k)) {
                        mp[i][j] += mp[i - 1][k];
                    }
                }
            }
        }
        unsigned long long res{0};
        for(int i = 0; i < (1<<n); ++i) {
            res += mp[m - 1][i];
        }
        cout<<res<<'\n';
    }


    return 0;
}
