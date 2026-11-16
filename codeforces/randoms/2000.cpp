#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	int max_score = 0;
	int current_score = arr[0];
	int max_till_now = arr[0];

	for(int mx = 1; mx<=30; mx++)
	{



	for(int i = 1; i < n; i++)
	{
		if(current_score < mx)
		{
			current_score = arr[i];
			max_till_now = arr[i];
		}
		else
		{
			if(arr[i] > max_till_now) max_till_now = arr[i];
			current_score += arr[i];
		}
		if(current_score - max_till_now > max_score)
			max_score = current_score - max_till_now;
	}
}

	cout << max_score << endl;
	return 0;
}
