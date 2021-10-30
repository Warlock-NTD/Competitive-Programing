#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long tp;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tp n;   cin>>n;
    vector<tp> r(n);
    tp mx = 0;
    for(tp i = 0; i < n; ++i)
    {
        cin>>r[i];
        mx = (mx > r[i]) ? mx : r[i];
    }
    tp q;   cin>>q;
    tp sm {0};
    for (auto &i : r)
        sm += (mx - i);
    cout<<q*sm;

    return 0;
}