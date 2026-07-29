#include<bits/stdc++.h>

bool check(long long x) {
	// TODO: Write your condition logic here.
	// Example: Can we build a bridge with cost x?
	return true; 
}

long long binarySearchAnswer(long long low, long long high, vector<int>t) {
	long long ans = -1; // Default if no solution exists
	
	while (low <= high) {
		long long mid = low + (high - low) / 2;

		if (check(mid)) {
			ans = mid;      // Record possible answer
			high = mid - 1; // Try to find a smaller valid value (shift left)
		} else {
			low = mid + 1;  // Condition not met, need larger value (shift right)
		}
	}
	return ans;
}

void printarr(vector<int>arr)
{
	int n = arr.size();
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void solve()
{
	int n,m;
	
	cin>>n;
	cin>>m;
	
	vector<int>t(n);
	vector<int>c(m);
	
	for(int i=0; i<n; i++)
	{
		cin>>t[i];
	}
	
	for(int i=0; i<m; i++)
	{
		cin>>c[i];
	}
	
	
	
	
}

int main()
{
	int t;
	cin >> t;

	while (t--)
		solve();
	return 0;
}