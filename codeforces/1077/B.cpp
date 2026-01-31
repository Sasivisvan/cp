#include<bits/stdc++.h>

using namespace std;


void solve()
{
	int n;
	cin>>n;
	vector<int>a(n);
	int i = n;
	int ones = 0;
	while(i--){
		char temp;
		cin >>temp;
		a[n-i-1] = temp-'0';
	}

	for(int i=0;i<n;i++)
	{
		if(a[i]==1&& i<n-1)
		{
			a[i+1]=-1;
		}
		if(a[i]==1 && i-1>=0)a[i-1]=-1;
	}
	int ans = 0;
	int count = 0;

	for(int i=0;i<n;i++)
	{
		if(a[i]!=0)
		{
			ans += ceil(count/3.0);
			count=0;
		}
		if(a[i]==0)count+=1;
		if(a[i]==1)ones++;
		
	}
	ans += ceil(count/3.0);
	cout<<ans+ones<<'\n';
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)solve();
}