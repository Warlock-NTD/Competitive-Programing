#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y);

class MinHeap
{
	int *harr;
	int capacity;
	int heap_size;
public:
	MinHeap(int capacity);

    	void PrintHeap();

	void MinHeapify(int );

	int parent(int i) { return (i-1)/2; }


	int left(int i) { return (2*i + 1); }


	int right(int i) { return (2*i + 2); }


	int extractMin();


	void decreaseKey(int i, int new_val);


	int getMin() { return harr[0]; }


	void deleteKey(int i);


	void insertKey(int k);
};

void MinHeap::PrintHeap()
{
    int *trav = harr;
    int k = 0;
    while(k < heap_size)
    {
        cout<<(*trav)<<' ';
        trav++;
        ++k;
    }
    cout<<'\n';
}
MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

void MinHeap::insertKey(int k)
{
	if (heap_size == capacity)
		return;

	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
	i = parent(i);
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
	i = parent(i);
	}
}

int MinHeap::extractMin()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	MinHeapify(0);

	return root;
}


void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}


void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	MinHeap h(13);
	h.insertKey(2);
	h.insertKey(1);
	h.insertKey(10);
	h.insertKey(6);
	h.insertKey(3);
	h.insertKey(8);
	h.insertKey(7);
    h.insertKey(13);
	h.insertKey(20);
	// first print .
	h.PrintHeap();
    //
    h.insertKey(14);
    h.insertKey(0);
    h.insertKey(35);
    // second print .
    h.PrintHeap();
    //
	h.deleteKey(6);
	h.deleteKey(13);
	h.deleteKey(35);
	// third print .
	h.PrintHeap();
	return 0;
}
