#include <bits/stdc++.h>

using namespace std;

void printarr(vector<int>arr)
{
	int n = arr.size();
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> hp1(n+1);
	vector<int> hp2(n+1) ;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		hp2[arr[i]]++;
	}
	
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
	{
		// cout<<"i: "<<i<<endl;
		// printarr(arr);
		// printarr(hp1);
		// printarr(hp2);
		hp1[arr[i]]++;
		hp2[arr[i]]--;
		
		for(int j=0; j<=n; j++)
		{
			if(hp1[j]==hp2[j] && hp1[j]==0)
			{
				cout<<"NO\n";
				return;
			}
			if(hp1[j]==0)break;
			if(hp2[j]==0)break;
		}
	}
	cout<<"YES\n";
}

int main()
{
	int t;
	cin >> t;

	while (t--)
		solve();
	return 0;
}