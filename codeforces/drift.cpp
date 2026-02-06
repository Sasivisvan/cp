#include<stdio.h>
#include <iostream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
	string str;
	cin >> str; // Automatically reads the characters until whitespace/newline
	
	int s = str.length(); // Get the size after reading
	
	for(int i=0;i<s-1;i++)
	{
		if(str[i]=='*' && str[i+1]=='<')
		{
			cout<<"-1\n";
			return;
		}
		
		if(str[i]=='*' && str[i+1]=='*')
		{
			cout<<"-1\n";
			return;
		}
		
		if(str[i]=='>' && str[i+1]=='*')
		{
			cout<<"-1\n";
			return;
		}
		if(str[i]=='>' && str[i+1]=='<')
		{
			cout<<"-1\n";
			return;
		}
	}
	bool changed=false;
	int count=0;
	int ans=0;
	for(int i=0;i<s;i++)
	{
		if(str[i]=='*')
		{
			count++;
			changed=true;
			ans = count;
			count=1;
		}
		else if(!changed && str[i]=='<'){
			count++;
		}else if(str[i]=='>' && !changed){
			changed=true;
			ans = count;
			count=1;
		}else if(str[i]=='>' && changed){
			count++;
		}
		
	}
	
	cout<<max(max(ans,count),1)<<'\n';
	return;
}

int main()
{
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}