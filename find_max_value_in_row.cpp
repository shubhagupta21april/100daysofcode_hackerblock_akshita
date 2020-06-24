#include <iostream>
#include<queue>
#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
     int val;
     Node* left;
     Node* right;
     Node(int val){
         this->val = val;
         left = NULL;
         right = NULL;
     }
};
void cal(Node* root,vector<int>&ans){
        if(root==NULL)
            return ;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        int a = INT_MIN;
        while(!q.empty()){
            Node* x = q.front();
            q.pop();
            if(x==NULL){
                ans.push_back(a);
                if(!q.empty()){
                    q.push(NULL);
                    a=INT_MIN;
                }
            }
            else{
                a = max(a,x->val);
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
            }
        }
        return ;
    }

    vector<int> largestValues(Node* root) {
          vector<int>ans;
          cal(root,ans);
          return ans;
    }
Node* levelOrderInput(){
    int root_val; cin>>root_val;
    Node* root = new Node(root_val);
    queue<Node*> qu;    qu.push(root);
    while(!qu.empty()){
        Node* child = qu.front();
        qu.pop();
        int a,b; cin>>a>>b;
        if(a != -1){
           Node* n = new Node(a);
           qu.push(n);
           child->left = n;
        }
        if(b != -1){
            Node* n = new Node(b);
            qu.push(n);
            child->right = n;
        }
    }
    return root;
}
void levelOrder_print(Node* root){
    queue<Node*> qu;
    qu.push(root); qu.push(NULL);
    while(!qu.empty()){
        Node* n = qu.front();
        qu.pop();
        if(n != NULL){
            cout<<n->val<<" ";
            if(n->left) qu.push(n->left);
            if(n->right) qu.push(n->right);
        }
        else {
            cout<<endl;
            if(!qu.empty()) qu.push(NULL);
        }
    }
    return ;
}


int main() {
     Node* root = levelOrderInput();
     vector<int>res = largestValues(root);
     for(int i=0;i<res.size();i++)
        cout << res[i]<< " ";
     return 0;
}





