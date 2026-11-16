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
		pq.push(t);
	}

	for(int i=0; i<ans.size(); i++)
	{
		cout<<ans[i]<<" ";

	}
	cout<<endl;

	for(int i=0; i<ans.size(); i++)
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;






}
