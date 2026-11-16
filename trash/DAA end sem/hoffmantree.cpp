#include<bits/stdc++.h>

using namespace std;

typedef struct Node
{
	int val;
	char c;
	struct Node* left;
	struct Node* right;

}node;

struct CustumComparator
{
	bool operator()(node* a, node* b)
	{
		return a->val>b->val;
	}
};
node* createnode(int val, char c, node* left, node* right)
{
	return new node{val,(char)(c+'a'),left,right};
}

int main()
{
	vector<int> counts(26,0);

	string s;
	cin>>s;

	for(int i=0; i<s.size(); i++)
	{
		int index = s[i]-'a';
		counts[index]++;
	}

	priority_queue<node*,vector<node*>,CustumComparator>pq;

	//build the pq
	for(int i=0; i<26; i++)
	{
		if(counts[i]>0)
		{
			pq.push(createnode(counts[i],i, nullptr, nullptr));

		}
	}

	while(pq.size()>1)
	{
		//pop least 2 merge them push it inside
		auto e1 = pq.top();
		pq.pop();
		auto e2 = pq.top();
		pq.pop();

		pq.push(createnode(e1->val+e2->val, (char)-(int)'a', e1,e2));

	}

	stack<pair<node*,vector<char>>> stk;

	stk.push({pq.top(), vector<char>()});

	while(stk.size()!=0)
	{
		auto ele = stk.top();
		stk.pop();

		node* n = ele.first;
		auto path = ele.second;

		if(n->c!=0)
		{
			cout<<n->c<<" : ";

			for(int i=0; i<path.size(); i++)
			{
				cout<<path[i];
			}
			cout<<endl;
		}

		if(n->left!=nullptr)
		{
			vector<char>leftpath;
			for(int i=0; i<path.size(); i++)
			{
				leftpath.push_back(path[i]);
			}
			leftpath.push_back('0');
			stk.push({n->left, leftpath});
		}

		if(n->right!=nullptr)
		{
			vector<char>rightpath;
			for(int i=0; i<path.size(); i++)
			{
				rightpath.push_back(path[i]);
			}
			rightpath.push_back('1');
			stk.push({n->right, rightpath});
		}
	}
}
