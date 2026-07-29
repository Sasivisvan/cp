#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t ;
	cin >> t;
	while(t--)
	{
		long long n,c,f;
		cin>>n;
		cin>>c;
		cin>>f;

		vector<int> arr;

		for(int i=0; i<n;i ++)
		{
			int temp;
			cin>>temp;
			arr.push_back(temp);
		}

		sort(arr.begin(), arr.end());
		for(int i=0; i<n; i++)
		{

			if(arr[i]<= c )
			{
				if(f>0)
				{
					int temp = min(f,c-arr[i]);
					c+=temp+arr[i];
					f-=temp;
				}else
				{
					c+=arr[i];
				}

			}else
			{
				break;
			}
		}
		cout<<c<<endl;



	}

}
