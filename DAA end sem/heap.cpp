#include <bits/stdc++.h>

using namespace std;

//heapmax heap implimentation
int heapmax = 25;
int heapsize = 0;
vector<int>heap(heapmax, INT_MIN);

void heappush(int i)
{
	if(heapsize >= heapmax)
	{
		cout<<"Heap is full"<<endl;
		return;
	}

	heap[heapsize] = i;
	bool changed = true;
	int t = heapsize;

	while(changed)
	{
		changed = false;

		//parents = x/2, x/2 -1
		int p1 = (t-1)/2;

		if(i>heap[p1])
		{
			//swap p1 and t

			int temp = heap[p1];
			heap[p1] = heap[t];
			heap[t] = temp;
			changed = true;
			t = p1;

		}

	}
	heapsize+=1;

}

int heaptop()
{
	if(heapsize<=0){
		cout<<"heap is empty";
		return -1;
	}
	return heap[0];

}

int heappop()
{
	if(heapsize<=0){
		cout<<"heap is empty";
		return -1;
	}
	int top = heap[0];
	heapsize--;
	heap[0] = heap[heapsize];
	bool changed = true;
	int t = 0;


	while(changed)
	{
		changed = false;

		int c1 = t*2 + 1;
		int c2 = t*2 + 2;

		int c1val;
		int c2val;

		if(c1<heapsize)
		{
			c1val = heap[c1];
		}else
		{
			c1val = INT_MIN;
		}

		if(c2<heapsize)
		{
			c2val = heap[c2];
		}else
		{
			c2val = INT_MIN;
		}

		if(c1val>=c2val && c1val>heap[t])
		{
			//swap c1 and 0
			int temp = heap[c1];
			heap[c1] = heap[t];
			heap[t] = temp;
			changed = true;
			t= c1;

		}else if(c1val<c2val && c2val>heap[t])
		{
			int temp = heap[c2];
			heap[c2] = heap[t];
			heap[t] = temp;
			changed = true;
			t= c2;
		}
	}
	return top;

}
int main()
{


	vector<int>nums  = {4,35,2,78,93,44,1,3,6};

	for(auto a: nums)
	{
		heappush(a);
	}

	while(heapsize!=0)
	{
		cout<<heappop()<<" ";
	}
	cout<<endl;

}
