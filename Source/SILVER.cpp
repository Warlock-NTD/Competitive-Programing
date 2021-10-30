#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long tp;


int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tp n;
    cin>>n;
    tp mx = 0;
    vector<tp> k(n);
    for (tp i = 0; i < n; ++i)
    {
        cin>>k[i];
        mx = max(mx,k[i]);
    }
    tp sm{0};
    for (auto &i : k)
    {
        if(i != mx)
        {
            sm = max(i, sm);
        }
    }

    cout<<sm;
    return 0;
}