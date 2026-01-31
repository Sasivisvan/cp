#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int t2 = t;
	vector<int>c;
	while(t--)
	{
		 int n;
		 cin>>n;
		 vector<int>a(n),b(n);
		 for(int i=0;i<n;i++){
			cin>>a[i];
		  b[i]=a[i]; 
		}
		sort(b.begin(),b.end());
		long long ans=INT32_MAX;
		long long mx = b[n-1];
		long long mi = b[0];
		for(int i=0;i<n;i++)
		{
			if(a[i]!=b[i])
			{
				long long te =max({a[i]-mi, mx-a[i]});
				ans  = min({te,ans});
				
			}
		}
		if(ans!=INT32_MAX){
			// c.push_back(ans);
			cout<<ans<<"\n";
		}else{
			cout<<-1<<"\n";
			// c.push_back(-1);
		}
	}
	
	return 0;
}