#include<iostream>
#include <string>
#include <queue>
#include <stack>
#include <utility>


#define INF 1000000

using namespace std;

struct TreeNode {
    bool end;
    int c;
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(INF), left(nullptr), right(nullptr), end(false) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), end(false) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right), end(false) {}
    TreeNode(int x, int c) : val(x), left(nullptr), right(nullptr), end(true), c(c) {}
};
struct MyComparator {
    bool operator()(TreeNode* n1, TreeNode* n2){
        return n1->val > n2->val;
    }
};
int main(){

    string input;
    cin>>input;

    //assume my stringonly contains ascii values

    int freq[256] = {0};

    for(int i=0; i<input.size(); i++){
        freq[input[i]]++;
    }

    cout<<"before sorting:"<<endl;
    for(int i=0; i<256; i++){
        if(freq[i]>0){
            cout<<(char)i<<" : "<<freq[i]<<endl;
        }
    }

    //sorting it
    int chars[256] ={0};
    for(int i=0; i<256; i++){
        chars[i]=i;
    }

    for(int i=0; i<256; i++){
        for(int j=i+1; j<256; j++){
            if(freq[i]<freq[j]){
                //swap i andj
                int temp= freq[i];
                freq[i] = freq[j];
                freq[j] = temp;

                temp = chars[i];
                chars[i]= chars[j];
                chars[j] = temp;
            }
        }
    }
    int highest = 0;
    priority_queue<TreeNode*, vector<TreeNode*>, MyComparator> myheap;
    cout<<"After sorting:"<<endl;
    for(int i=0; i<256; i++){
        if(freq[i]>0){
            highest += freq[i];
            TreeNode* newNode = new TreeNode(freq[i], chars[i]);
            myheap.push(newNode);
            cout<<(char)chars[i]<<" : "<<freq[i]<<endl;
        }
    }
    cout<<endl;
    //core logic
    int currHigh =0;
    while(myheap.size()!=1){
        // if(highest == currHigh)break;
        // pop least 2 elements create a new node combine them push back into the queue untill highest is achived
       
        TreeNode * e1 = myheap.top();
        myheap.pop();
        TreeNode * e2 = myheap.top();
        myheap.pop();
       
        cout<<(char)e1->c<<" "<<e1->val<<"  &&  "<<(char)e2->c<<" "<<e2->val<<endl;
       
       
            int total=e1->val+e2->val;
            TreeNode* newNode = new TreeNode(total, e1, e2);
            myheap.push(newNode);
            // if(total>currHigh){
            //  currHigh = total;
            // }
    }
    //till the above is my code correct logically dont say a better impplimentation is there i just wantto know if it is correct
    // for each element in beforereaching the end if you go left it is 0 andif you goright it is 1
    TreeNode* root = myheap.top();
    stack<pair<TreeNode*,string>>stk;
    stk.push({root,""});
    while(stk.size()!=0){
        TreeNode* e = stk.top().first;
        string code = stk.top().second;
        stk.pop();
        if(e->end){
            cout<<(char)e->c<<"  "<<e->val<<"  "<<code<<endl;
        }else{
            if(e->left!=nullptr)stk.push({e->left, code+"1"});
            if(e->right!=nullptr)stk.push({e->right, code+"0"});
        }
    }

}
