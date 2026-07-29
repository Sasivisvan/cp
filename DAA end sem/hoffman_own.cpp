#include<bits/stdc++.h>

using namespace std;

typedef struct Node
{
	int val;
	char c;
	struct Node* left;
	struct Node* right;
}node;

struct CustumCOmparator
{

	bool operator()(const node* a, const node* b)
	{
		return a->val > b->val;
	}
};


node* createnode(int val, char c, node* left, node* right)
{
	return new node{val,c,left,right};
}
int main()
{
	vector<int>counts(26,0);

	string s;
	cin>>s;

	for(auto a:s)
	{
		counts[a-'a']++;
	}

	for(int i=0; i<26; i++)
	{
		cout<<counts[i]<<" ";
	}
	cout<<endl;
	//build the pq

	priority_queue<node*, vector<node*>, CustumCOmparator>pq;

	for(int i=0; i<26; i++)
	{
		if(counts[i]!=0)
		{
			pq.push(createnode(counts[i], i+'a', nullptr,nullptr));
		}
	}


	while(pq.size()>1)
	{
		node* ele1 = pq.top(); pq.pop();
		node* ele2 = pq.top(); pq.pop();

		pq.push(createnode(ele1->val+ele2->val, 0, ele1, ele2));

	}

	stack<pair<node*, vector<char>>>stk;

	stk.push({pq.top(), {}});

	while(!stk.empty())
	{
		auto e = stk.top();stk.pop();
		node* n = e.first;

		vector<char>path = e.second;

		if((int)n->c != 0 )
		{
			cout<<(char)n->c <<" : ";
			for(auto c : path)
			{
				cout<<c<<" ";
			}
			cout<<endl;
		}else
		{
			vector<char>leftpath = path;
			leftpath.push_back('0');
			stk.push({n->left, leftpath});

			vector<char>rightpath = path;
			rightpath.push_back('1');
			stk.push({n->right, rightpath});

		}

	}

}
