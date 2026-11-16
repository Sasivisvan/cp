#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> arr;

		int even = 0;

		for(int i=0; i<n; i++)
		{
			int temp;
			cin>>temp;

			if(temp%2==0)even++;
			arr.push_back(temp);
		}
		int odd = n-even;

		if(even%2==0)
		{
			cout<<"YES"<<endl;
		}else
		{

			sort(arr.begin(), arr.end());
			for(int i=0; i<n-1; i++)
			{
				if(arr[i]==arr[i+1]-1)
				{
					cout<<"YES"<<endl;
					break;
				}

				if(i==n-2)cout<<"NO"<<endl;
			}
		}


	}
}
