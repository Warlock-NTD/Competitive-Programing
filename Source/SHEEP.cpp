#include<bits/stdc++.h>

using namespace std;
typedef long long tp;


int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tp n,L;    cin>>n>>L;
    set<tp> d ;
    for (tp i = 0; i < L; ++i)
    {
        tp s;  cin>>s;
        d.insert(s);
    }
    tp cnt{1};
    for (tp i = 0; i < n; ++i)
    {
        bool flag {1};
        tp s = cnt;
        while(s)
        {
            tp dig = s % 10;
            const bool is_in = d.find(dig) != d.end();
            if(is_in)
            {
                flag = 0;
                break;
            }
            s /= 10;
        }
        if(!flag)   i--;
        cnt++;
    }
    cout<<cnt - 1;

    return 0;
}