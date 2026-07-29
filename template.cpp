#include <bits/stdc++.h>

using namespace std;


/*

for(int i=0; i<n; i++)
{
	
}

*/



/*



*/

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
	
}

int main()
{
	int t;
	cin >> t;

	while (t--)
		solve();
	return 0;
}




/* BINARY SEARCH TEMPLATE 
   ----------------------
   Use 'binarySearch' for simple array lookups.
   Use 'binarySearchAnswer' for finding optimal values (FFFFTTTT pattern).
*/

// 1. STANDARD BINARY SEARCH
// Returns index of target if found, otherwise -1.
int binarySearch(const vector<int>& arr, int target) {
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2; // Prevent overflow

		if (arr[mid] == target)
			return mid;
		if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

// 2. BINARY SEARCH ON ANSWER (The "Meta" Strategy)
// Finds the SMALLEST value 'x' in range [low, high] where check(x) is true.
// Pattern: [False, False, ..., True, True] -> We want the first True.
bool check(long long x) {
	// TODO: Write your condition logic here.
	// Example: Can we build a bridge with cost x?
	return true; 
}

long long binarySearchAnswer(long long low, long long high) {
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