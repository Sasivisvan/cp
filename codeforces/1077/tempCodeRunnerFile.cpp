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
	
	// 1 -1 0 -1 1 -1 
	// 1 -1 0 0 0 0 0 0-1 1
	// 10 0 01
// 10 00 01	

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
	// for(int i=0;i<n;i++)
	// {
	// 	// if(a[i]==1)ans++;
	// 	cout<<a[i]<<" ";
	// }
	// cout<<endl;
	// 10 0
	
	// 000  010       00   010 00
	//0 1 0  -1 1 -1  1 -1 -1 1 -1 0 0 
	for(int i=0;i<n;i++)
	{
		// if(a[i]==0 && a[i+1]==-1 && a[i-1]==-1)
		// {
		// 	a[i]=1;
		// }
		// if(a[i]==0 && a[i+1]==0 && a[i-1]==0)
		// {
		// 	a[i-1]=-1;
		// 	a[i+1]=-1;
		// 	a[i]=1;
		// }
		// else if(a[i]==0 && a[i-1]==0 && a[i+1]==-1)
		// {
		// 	a[i-1]=1;
		// 	a[i]=-1;
		// }
		// 010 010 
		if(a[i]!=0)
		{
			ans += ceil(count/3.0);
			// ans++;
			count=0;
		}
		if(a[i]==0)count+=1;
		if(a[i]==1)ones++;
		
		
		
		
		
		
	}
	ans += ceil(count/3.0);
			// ans++;
	
	// 010 0 010
	
	
	// if(n>=3)
	// {
	// 	if(a[0]==0 && a[1]==-1 && a[2]==1)a[0]=1;
		
	// 	if(a[n-3]==1 && a[n-2]==-1 && a[n-1]==0 )a[n-1]=1;
	// 	if(a[n-3]==-1 && a[n-2]==0 && a[n-1]==0 )a[n-1]=1;
	// 	if(a[n-3]==1 && a[n-2]==-1 && a[n-1]==0 )a[n-1]=1;
	// }
	
	
	
	
	
	// int ans=0;
	
	// for(int i=0;i<n;i++)
	// {
	// 	// if(a[i]==1)ans++;
	// 	// cout<<a[i]<<" ";
	// }
	// // cout<<endl;
	// if(n<3)ans=1;
	cout<<ans+ones<<'\n';
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)solve();
}