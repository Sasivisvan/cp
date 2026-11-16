//1133C
#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> arr;
	int n;
	cin >> n;
	int i=n;
	while(i--)
	{
		int temp;
		cin>> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	i=0;
	int j=0;
	int ans =0 ;

	while(j<n)
	{
		if((arr[j] - arr[i]) <= 5)
		{
			ans = max(ans, j-i+1);
			j+=1;

		}
		else if((arr[j] - arr[i]) > 5)
		{
			i +=1;

		}
	}
	cout<<ans<<"\n";
}
