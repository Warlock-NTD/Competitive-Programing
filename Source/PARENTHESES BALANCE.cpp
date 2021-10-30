#include<bits/stdc++.h>

using namespace std;


int main(int argc, char*argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin>>n;
    cin.ignore(32767,'\n');
    while(n--)
    {
        string ip;
        getline(cin,ip);
        if(ip.length() == 0 && ip == "\n")
        {
            cout<<"Yes\n";  continue;
        }
        stack<char> onl;
        bool legal(1);
        for(int i = 0; i < ip.length(); ++i)
        {
            if(ip[i] == '(' || ip[i] == '[')    onl.push(ip[i]);
            if(ip[i] == ')' && (onl.empty() || onl.top() != '('))
            {
                legal = 0;  break;
            }
            if(ip[i] == ']' && (onl.empty() || onl.top() != '['))
            {
                legal = 0;  break;
            }
            if(ip[i] == ')' && onl.top() == '(')    onl.pop();
            if(ip[i] == ']' && onl.top() == '[')    onl.pop();
        }
        if(onl.empty() && legal)  cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}
