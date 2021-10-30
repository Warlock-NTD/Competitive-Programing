#include<bits/stdc++.h>

using namespace std;
typedef long long tp;

inline void hotel(tp &n)
{
    if(n % 3 == 0)
    {
        cout<<0<<' '<<n/3;
        return;
    }
    tp i{1};
    while(1)
    {
        n -= 2;
        if(n % 3 == 0)
        {
            cout<<i<<' '<<n/3;
            return;
        }
        if(n <= 0){
            if(n == 0)  cout<<i<<' '<<0;
            return;
        }
        i++;
    }
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tp n;
    cin>>n;
    hotel(n);

    return 0;
}