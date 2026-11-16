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

		for(int i=0; i<n; i++)
		{
			int temp;
			cin>>temp;
			arr.push_back(temp);
		}

		//distinct

		unordered_set<int> us;
		unordered_map<int,int> um;
		int distinct =0;

		for(int i=0; i<n; i++)
		{
			if(us.find(arr[i])==us.end())
			{
				distinct++;
				us.insert(arr[i]);
				um[arr[i]] = 1;
			}else
			{
				um[arr[i]]++;
			}
		}

		int max_num = 0;

		for(const auto& [key, a]:um)
		{
			max_num = max(max_num, a);
		}

		if(distinct > max_num )
		{
			cout<<max_num<<endl;
		}else if(distinct == max_num)
		{
			cout<<distinct-1<<endl;
		}else
		{
			cout<<distinct<<endl;
		}

	}
	return 0;
}
