#include<bits/stdc++.h>
using namespace std;


inline void print(vector<int>&r)
{
    for(auto & i : r)
        cout<<i;
    cout<<'\n';
}
inline void Bin_(vector<int> &r, int k,int &n)
{
    if(k== n)
    {
        print(r);   return;
    }
    r[k] = 0;
    Bin_(r,k+1,n);
    r[k] = 1;
    Bin_(r,k+1,n);

}
int main(int argc,char*argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin>>n;
    vector<int> r(n);
    Bin_(r,0,n);

    return 0;
}
