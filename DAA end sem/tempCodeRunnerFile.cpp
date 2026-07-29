#include<bits/stdc++.h>

using namespace std;

int main(){
	int n = 5;
	
	cout<<"Enter No of edges of the graph ";
	cin>>n;
	
	vector<int,vector<int>>matrix(n, vector<int>(n,INT_INF));
	cout<<"ENter the edges :";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>matrix[i][j];
		}
	}
	
	int start = 3;
	
	cout<<"Enter start node ";
	
	vector<bool>visited(n,false);
	vector<bool>parent(n,-1);
	stack<int>stk;
	stk.push(start);
	
	while(!stk.empty())
	{
		
		int ele =stk.top();
		stk.pop();
		if(visited[ele])
		{
			continue;
		}else
		{
			visited[ele] = true;
			cout<<ele<<" ";
			for(int i=0; i<n; i++)
			{
				if(!visited[matrix[ele][i]])
				{
					parent[i] = ele;
					stk.push(i);
				}
			}
		}
		
		
	}
	cout<<endl;
	
	for(int i=0; i<n; i++)
	{
		cout<<parent[i]<<" ";
	}
	cout<<endl;
	
	for(int i=0; i<n; i++)
	{
		cout<<visited[i]<<" ";
	}
	cout<<endl;
	
	
}