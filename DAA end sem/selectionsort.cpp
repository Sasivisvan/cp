#include<bits/stdc++.h>

using namespace std;

int main()
{
	int temp ;
	int s;
	cin>>s;
	priority_queue<int>pq;
	vector<int>ans;
	while(s--)
	{
		int t;
		cin>>t;
		ans.push_back(t);
	}
	s = ans.size();

	for(int i=0; i<s; i++)
	{
		int minindex = i;
		int least = ans[i];
		for(int j=i+1; j<s; j++)
		{
			if(ans[j]<least)
			{
				minindex = j;
				least = ans[j];
			}
		}

		int temp = ans[minindex];
		ans[minindex]= ans[i];
		ans[i] = temp;
	}

	for(int i=0; i<s; i++)
	{
		cout<<ans[i]<<" ";

	}
	cout<<endl;

}
