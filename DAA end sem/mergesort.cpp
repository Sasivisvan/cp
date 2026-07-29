#include<bits/stdc++.h>

using namespace std;

vector<int> merge(vector<int>arr1,vector<int>arr2)
{
	vector<int > ans;

	int i = 0;
	int j=0;

	while(i<arr1.size()|| j<arr2.size())
	{
		if(i<arr1.size() && j<arr2.size() && arr1[i]<=arr2[j])
		{
			ans.push_back(arr1[i]);
			i++;
		}else if(i<arr1.size() && j<arr2.size() && arr2[j]<=arr1[i])
		{
			ans.push_back(arr2[j]);
			j++;
		}else if(i<arr1.size())
		{
			ans.push_back(arr1[i]);
			i++;
		}else if(j<arr2.size())
		{
			ans.push_back(arr2[j]);
			j++;
		}
	}
	return ans;
}

vector<int> mergesort(vector<int> arr)
{
	int n = arr.size();
	int mid = n/2;
	if(n==0 || n==1)return arr;

	vector<int>arr1;
	vector<int>arr2;

	for(int i=0; i<mid; i++)
	{
		arr1.push_back(arr[i]);
	}

	for(int i=mid; i<n;i++)
	{
		arr2.push_back(arr[i]);
	}

	arr1 = mergesort(arr1);
	arr2 = mergesort(arr2);

	return merge(arr1,arr2);
}

int main()
{
	vector<int>arr;
	int s;
	cout<<"Enter number of elements: ";
	cin >> s;
	cout<<"Enter the elements: ";
	while(s--)	{
		int t;
		cin>>t;
		arr.push_back(t);
	}

	vector<int>sorted = mergesort(arr);

	for(int i=0;i<sorted.size();i++)
	{
		cout<<sorted[i]<<" ";
	}
	cout<<endl;

}
