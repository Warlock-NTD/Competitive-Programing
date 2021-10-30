#include<bits/stdc++.h>

using namespace std;
typedef long long tp;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tp n, t, f, x;
    cin>>n>>t>>f>>x;
    tp t_ = (t - 1)*60 - (n - f)*x;
    if(t_ == 0)
    {
        cout<<"EXACT!";
    } else if(t_ > 0)
    {
        cout<<"YES\n"<<t_;
    } else
    {
        cout<<"NO\n"<<-t_<<'\n'<<-t_/45 + 1;
    }

    return 0;
}