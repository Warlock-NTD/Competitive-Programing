#include<bits/stdc++.h>
using namespace std;

inline void print(vector<int> &r)
{
    for (int i=0; i < r.size(); ++i)
        cout<<r[i];
    cout<<'\n';
}
inline void P(vector<bool> &c, vector<int> &r, int s,int &n)
{
    if(s == n)
    {
        print(r);   return;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(c[i]==1)
        {
            c[i] = 0;
            r[s] = i;
            P(c,r,s+1,n);
            c[i] = 1;
        }
    }


}
int main(int argc,char*argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<bool> c (n+1,1);
    vector<int> r (n);
    P(c,r,0,n);

    return 0;
}
