#include<bits/stdc++.h>

using namespace std;
typedef long long tp;

inline tp travel(tp m, tp n)
{
    if(n == 1)  return (m > 1) ? 1 : 0;
    if(n == 2) return (m > 2) ? 3 : ((m == 2)? 2 : 0);
    return 4 + travel(m - 2, n - 2);
}

inline tp spiral(tp m, tp n)
{
    if(m < n)
    {
        swap(m,n);
        return travel(m,n) - 1;
    }
    return travel(m,n);
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tp m,n;
    cin>>m>>n;
    cout<<spiral(m,n);

    return 0;
}