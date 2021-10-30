#include<bits/stdc++.h>

using namespace std;


int main(int argc, char*argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 1;
    while(1)
    {
        cin>>n;
        if(n == 0)  break;
        while(1)
        {
            int num;    cin>>num;
            if(num == 0)
            {
                cout<<'\n'; break;
            }
            stack<int> S;
            queue<int> B;   B.push(num);
            for(int i = 1; i < n; ++i)
            {
                cin>>num;   B.push(num);
            }
            for(int i = 1; i <= n; ++i)
            {
                if(!B.empty() && B.front() != i)
                {
                    while(!S.empty() && !B.empty())
                    {
                        if(S.top() != B.front())  break;
                        B.pop();    S.pop();
                    }
                    if(!B.empty() && B.front() != i)
                    {
                        S.push(i);  continue;
                    }
                    if(!B.empty())  B.pop();
                    continue;
                }
                if(!B.empty())
                {
                    B.pop();
                }
            }
            bool legal {1};
            while(!S.empty())
            {
                if(S.top() != B.front())
                {
                    legal = 0;
                    break;
                }
                S.pop();    B.pop();
            }
            if(legal)   cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}
