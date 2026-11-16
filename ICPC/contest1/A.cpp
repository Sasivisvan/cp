#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	int n;
	while(t--)
	{
		cin>>n;
		int temp = n;
		vector<int> arr;
		vector<int> ans;
		while(temp--)
		{
			int v;
			cin>>v;
			arr.push_back(v);
			ans.push_back(v);
		}

		sort(ans.begin(), ans.end());

		int inc = 0;
		int val = 0;
		bool flag = true;

		for (int i = 0; i < n; i++)
		{
			if(ans[i]!=arr[i])
			{
				if(inc == 0)
				{
					inc = 1;
					val = arr[i];
				}else
				{
					if(arr[i]>val)
					{
						flag = false;
						break;
					}else
					{
						val = arr[i];
					}
				}
			}
		}

		if(flag){cout<<"YES\n";}
		else{cout<<"NO\n";}

	}

	return 0;
}
