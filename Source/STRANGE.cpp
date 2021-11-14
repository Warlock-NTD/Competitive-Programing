#include<bits/stdc++.h>

using namespace std;
typedef long long tp;


int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<bool> ascii(130, false);
    tp mx = 0, pos = -1, len = -1;
    string s;	cin >> s;
    for(tp i = 0, j = 0; i < s.length(); i ++){
    	while(j < s.length() && !ascii[s[j]])
    		ascii[s[j]] = true, j ++;
    	if(j - i >= mx)
    		pos = i, mx = len = j - i;
    	ascii[s[i]] = false;
	}
	cout << len << ' ' << pos << '\n' << s.substr(pos, len);
    return 0;
}