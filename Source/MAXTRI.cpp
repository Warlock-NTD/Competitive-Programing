#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long tp;


int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<tp> t(3);
    cin>>t[0]>>t[1]>>t[3];
    sort(t.begin(),t.end());
    cout<<t[2]<<t[1]<<t[0];
    return 0;
}