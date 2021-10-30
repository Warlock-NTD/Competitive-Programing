#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long tp;

inline tp md(tp &n)
{
    if(n == 1) return 9;
    if(n == 2) return 72;
    tp maxdiff = 0;
    tp s,b;
    tp m = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        m += (9 * pow(10,i));
        s = pow(10, n - 1) + m;
        b = pow(10, n - i - 2) * (10 * m + 1);
        maxdiff = (maxdiff > (b - s)) ? maxdiff : (b - s);
    }
    return maxdiff;
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tp n; cin>>n;
    cout<<md(n);

    return 0;
}