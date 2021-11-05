#include<bits/stdc++.h>

using namespace std;

inline void merged(vector<int> &arr, int l, int r, int m)
{
    vector<int> L, R;
    for(int i = l; i <= m; ++i)     L.push_back(arr[i]);
    for(int i = m + 1; i <= r; ++i)     R.push_back(arr[i]);
    int il{0}, ir{0};
    int idx = l;
    /*
    cout<<"LLL : ";
    for(auto &i : L) { cout<<i<<' ';}
    cout<<"RRR : ";
    for(auto &i : R) { cout<<i<<' ';}
    cout<<'\n';
    */
    while(il < L.size() && ir < R.size())
    {
        if(L[il] <= R[ir])      arr[idx++] = L[il++];
        else       arr[idx++] = R[ir++];
    }
    while(il < L.size())  arr[idx++] = L[il++];
    while(ir < R.size())  arr[idx++] = R[ir++];
}

inline void merge_sort(vector<int> &arr, int l, int r)
{
    if(r <= l)   return;
    int m = l + (r - l)/2;

    // sort left first.
    merge_sort(arr, l, m);

    // sort right then.
    merge_sort(arr, m + 1, r);

    // finally merge them.
    merged(arr ,l ,r, m);
}

int main(int argc, char*argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin>>n;
    vector<int> arr;
    while(n--)
    {
        int tmp;    cin>>tmp;
        arr.push_back(tmp);
    }
    merge_sort(arr, 0, arr.size() - 1);
    for(auto &i : arr)  cout<<i<<' ';

    return 0;
}
