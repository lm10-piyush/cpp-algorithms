#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)

struct TreeNode {
  int data;
  TreeNode *left, *right;
  TreeNode(int _data) {
    data = _data;
    left = right = nullptr;
  }
};

void insert(TreeNode * &root, int data) {
  if (root == nullptr) {
    root = new TreeNode(data);
    return;
  }
  if (data < root->data) {
    if (root->left) insert(root->left, data);
    else root->left = new TreeNode(data);
  }
  else {
    if (root->right) insert(root->right, data);
    else root->right = new TreeNode(data);
  }
}

void inorder(TreeNode *root) {
  if (root == nullptr) return;
  inorder(root->left);
  cout << root->data << ' ';
  inorder(root->right); 
}

void preorder(TreeNode *root) {
  if (root == nullptr) return;
  cout << root->data << ' ';
  preorder(root->left);
  preorder(root->right); 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    TreeNode *root = nullptr;
    insert(root, 50);
    insert(root, 40);
    insert(root, 80);
    insert(root, 30);
    insert(root, 45);
    insert(root, 70);
    insert(root, 90);
    insert(root, 20);
    insert(root, 48);
    insert(root, 88);
    insert(root, 100);

    inorder(root); cout << endl;
    preorder(root); cout << endl;

    return 0;
}

/*
  50 40 80 30 45 70 90 20 48 88 100
       50
      /  \
     /    \
    40     80
    / \    /\
   30  45 70 90
  /    \     / \
  20    48  88  100
*/