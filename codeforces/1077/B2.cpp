#include<bits/stdc++.h>

using namespace std;


void solve()
{
	int n;
	cin>>n;
	vector<int>a(n);
	int i = n;
	while(i--){
		char temp;
		cin >>temp;
		a[n-i-1] = temp-'0';
	}
	
	// 1 0 0 0 1 0 
	// 1 0 0 0 0 0 1
// 10 00 01	

for(int i=1;i<n-1;i++)
	{
		if(a[i]==1)
		{
			a[i+1]=-1;
		}
		if(a[i]==1)a[i-1]=-1;
	}
	for(int i=1;i<n-1;i++)
	{
		if(a[i]==0 && a[i+1]==0 && a[i-1]==0)
		{
			a[i]=1;
		}
		
	}
	
	if(n>=3)
	{
		if(a[0]==0 && a[1]==0 && a[2]==1)a[0]=1;
		if( a[n-2]==0 && a[n-1]==0)a[n-1]=1;
		if(a[n-3]==1 && a[n-2]==0 && a[n-1]==0 )a[n-1]=1;
	}
	
	
	
	
	
	int ans=0;
	
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)ans++;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	if(n<3)ans=1;
	cout<<ans<<'\n';
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)solve();
}