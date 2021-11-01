#include<bits/stdc++.h>
using namespace std;

vector<string>ch(5); //8
// n

inline void print()
{
    for(auto & s : ch){
        for(auto & i : s)
            cout<<i<<' ';
        cout<<'\n';
    }
}
inline void SET(int l,vector<bool>&c,vector<bool>&cc,vector<bool>&cp)
{
    // n
    if(l == 5) //8
    {
        print();   cout<<"\n\n\n";
        return;
    }
    for(int i = 0; i < 5; ++i) // 8 // n
    {
        if(c[i] && cp[i+l] && cc[i-l+4]) // 7 // n-1
        {
            ch[l][i] = 'X';
            c[i] = 0 ; cp[i+l] = 0; cc[i-l+4] = 0; // 2n-1
            SET(l+1,c,cc,cp);
            ch[l][i] = 'O';
            c[i] = 1 ; cp[i+l] = 1 ; cc[i-l+4] = 1; // 2n-1
        }
    }

}
int main(int argc,char*argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(auto &i : ch)     i = "OOOOO"; // "OOOOOOOO" // n*O
    vector<bool> cc(9,1),cp(9,1),c (4,1); // 15 15 7 // 2n-1  2n-1  n-1
    SET(0,c,cc,cp);

    return 0;
}
