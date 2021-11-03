#include<bits/stdc++.h>
using namespace std;

inline vector<int> quick_sort(int p, vector<int> ref_)
{
    if (ref_.size()==1) return ref_;
    vector<int>left,right,mid;
    for (auto &i : ref_)
    {
        if(i < p)   left.push_back(i);
        else if(i>p) right.push_back(i);
        else mid.push_back(i);
    }
    ref_.clear();
    if(!left.empty())   left = quick_sort(left[0],left);
    if(!right.empty())  right = quick_sort (right[0],right);
    ref_.insert(ref_.end(),left.begin(),left.end());
    ref_.insert(ref_.end(),mid.begin(),mid.end());
    ref_.insert(ref_.end(),right.begin(),right.end());
    return ref_;
}
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<int> ar;
    for (int i = 0 ; i < n ; ++i)
    {
        int ip; cin>>ip;    ar.push_back(ip);
    }
    // quicksort implementation
    ar = quick_sort(ar[0],ar);
    for(auto&i : ar)    cout<<i<<' ';
    return 0;
}
