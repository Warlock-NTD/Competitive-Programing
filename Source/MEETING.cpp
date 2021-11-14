#include<bits/stdc++.h>

using namespace std;
typedef int tp;

tp minu(tp L1, tp R1, tp L2, tp R2, tp K) {
    if(L1 > R2 || L2 > R1) return 0;
    if(L2 <= R1 && L2 >= L1)
    {
        if(R1 < R2)
        {
            if(K>=L2 && K <= R1)
                return R1 - L2;
            return R1 - L2 + 1;
        }
        if(R1 >= R2)
        {
            if(K >= L2 && K <= R2)
            {
                return R2 - L2;
            }
            else
                return R2 - L2 + 1;
        }
    }
    if(L1 <= R2 && L1 >= L2)
    {
        if(R2 < R1)
        {
            if(K >= L1 && K <= R2)  return R2 - L1;
            return R2 - L1 + 1;
        }
        if(R2 >= R1)
        {
            if(K <= R1 && K >= L1)
                return R1 - L1;
            return R1 - L1 + 1;
        }
    }
    return 0;
}


int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    tp L1, R1, L2, R2, K;
    cin>>L1>>R1>>L2>>R2>>K;
    cout<<minu(L1,R1,L2,R2,K);

    return 0;
}
