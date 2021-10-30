#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long tp;

inline tp res(tp &n, tp &k)
{
    tp Min = pow(10,n - 1);
    if(Min % k == 0)    return Min;
    return (Min + k) - ((Min + k) % k);

}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tp n,k;    cin>>n>>k;
    cout<<res(n,k);

    return 0;
}