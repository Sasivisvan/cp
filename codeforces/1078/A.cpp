#include <bits/stdc++.h>

using namespace std;


/*

for(int i=0; i<n; i++)
{
	
}

*/

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
	cin>>n;
	int w;
	cin>>w;
	int ans=n-(n/w);
	cout<<ans<<endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
		solve();
	return 0;
}