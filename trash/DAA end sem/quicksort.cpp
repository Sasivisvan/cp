#include<bits/stdc++.h>

using namespace std;


void quicksort(vector<int>&arr, int start, int end)
{
	int n= arr.size();
	if(start>=end-1)return;

	int mid = (start+end)/2;

	int pivot = start;

	int index = start+1;

	for(int i=start+1; i<end; i++)
	{
		if(arr[i]<=arr[pivot])
		{

			//swap arr[i] and arr[index]
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
	}
	index--;

	//put pivot to proper place
	int temp = arr[pivot];
	arr[pivot] = arr[index];
	arr[index] = temp;
	


	quicksort(arr, start, index);
	index++;
	quicksort(arr, index, end);

}


int main()
{
	vector<int>arr = {3, 45, 2, 1 , 54, 888, 33, 85, 34};
	int s = arr.size();

	quicksort(arr, 0, arr.size());

	for(int i=0;i<s;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
