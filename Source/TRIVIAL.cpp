#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long tp;

inline double trivial(tp &x)
{
    double tr = 1.0;
    for(tp i = 2; i * i <= x; ++i)
    {
        if(x % i == 0)
        {
            if(i * i == x)
            {
                tr += i;
            } else {
                tr += i;
                tr += x/i;
            }
        }
    }
    return tr/x;
}
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tp a, b;
    cin>>a>>b;
    double mi = b * 1.0;
    double ma = 0;
    map<tp,double> triv;
    for(tp i = a ; i <= b; ++i)
    {
        triv[i] = trivial(i);
        mi = min(triv[i],mi);
        ma = max(triv[i],ma);
    }
    for(auto &i : triv)
    {
        if(mi == i.second)
        {
            cout<<i.first<<' ';
            break;
        }
    }
    for(auto &i : triv)
    {
        if(ma == i.second)
        {
            cout<<i.first;
            break;
        }
    }

    return 0;
}