#include<bits/stdc++.h>

using namespace std;
typedef long long tp;
#define m 1000000007

inline tp fib(tp &n)
{
    if(n == 1 || n == 2) return 1;

    tp a = 1, b = 1, c;
    for (tp i = 2; i < n; ++i)
    {
        c = (a % m + b % m) % m;
        a = b % m;
        b = c % m;
    }
    return c;
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FIBONACCI.inp","r",stdin);
    freopen("FIBONACCI.out","w",stdout);
    tp n;   cin>>n;
    cout<<fib(n);
    return 0;
}