#include<bits/stdc++.h>

using namespace std;
typedef long long tp;


int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<tp, bool> ump;
    tp n, m;	cin >> n >> m;
    vector<tp> a(n), b(m), res;
    for(tp &x: a)	cin >> x;
    for(tp &x: b)	cin >> x;
    sort(begin(a), end(a)), sort(begin(b), end(b));
    for(tp i = 0; i < n; i ++)
    	ump[a[i]] = true;
    for(tp j = 0; j < m; j ++)
    	if(ump[b[j]])
    		res.push_back(b[j]);
    cout << res.size() << '\n';
    for(tp x: res)
    	cout << x << ' ';
    return 0;
}