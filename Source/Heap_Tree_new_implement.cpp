#include<bits/stdc++.h>
using namespace std;
class MinHeap
{
    public:
    int heapsize;
    vector<int> heap;
    map<int,int> ex;
    map<int,int> idx;
    int parent (int i)  {return (i-1)/2;}
    int child_left (int i ){return (2*i + 1)/2;}
    int child_right (int i) { return (2*i +2)/2;}
    void insertKey (int key)
    {
        heap.push_back(key);
        ex[key]++;
        heapsize++; if(heapsize == 1)   return;
        int i = heapsize - 1;
        idx[key] = i;
        while ((i != 0) && (heap[parent(i)] > heap[i]))
        {
            swap(heap[i], heap[parent(i)]);
            swap(idx[heap[i]], idx[heap[parent(i)]]);
            i = parent(i);
        }
    }
    void heapify(int dix)
    {
        int smallest = dix;
        int l = 2*dix + 1;  int r = 2*dix + 2;
        if( l < heapsize && heap[l]<heap[smallest])
            smallest = l;
        if(r < heapsize && heap[r]<heap[smallest])
            smallest = r;
        if(smallest != dix)
        {
            swap(heap[dix],heap[smallest]);
            swap(idx[heap[dix]],idx[heap[smallest]]);
            heapify(smallest);
        }
    }
    void deleteKey (int key)
    {
        if(!ex[key])    return;
        ex[key]--;
        int last = heap[heapsize-1];
        int ind = idx[key]; idx.erase(heap[ind]);
        heap[ind] = last;
        idx[last] = ind;
        heap.pop_back();    --heapsize;
        heapify(ind);
    }
    int getMin ()   {return heap[0];}
};
int main(int argc, char*argv[]) 
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0);
    int Q;  cin>>Q;
    MinHeap H;
    int t;
    while(Q--)
    {
        int q; cin>>q;
        switch (q)
        {
            case 1:
            {
                cin>>t;
                H.insertKey(t);
                break;
            }
            case 2:
            {
                cin>>t;
                H.deleteKey(t);
                break; 
            }
            case 3:
            {
                cout<<H.getMin()<<'\n';
                break;
            }
        }
    }
    return 0;
}
