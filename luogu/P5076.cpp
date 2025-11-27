#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int value, count, size;
    TreeNode *left, *right;
    TreeNode(int v): value(v), count(1), size(1), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int v){
    if (!root) return new TreeNode(v);
    if (v < root->value) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
    root->size = root->count + (root->left ? root->left->size : 0) + (root->right ? root->right->size : 0);
    return root;
}

// 查询排名（小于 x 的元素数量 + 1）
int query(TreeNode *root, int x){
    if (!root) return 1;
    int leftsize = root->left ? root->left->size : 0;
    if (x < root->value) return query(root->left, x);
    if (x == root->value) return leftsize + 1;
    return (leftsize) + root->count + query(root->right, x);
}

// 查询第 k 小
int kth(TreeNode* root, int k){
    int leftsize = root->left ? root->left->size : 0;
    if (k <= leftsize) return kth(root->left, k);
    if (k <= leftsize + root->count) return root->value;
    return kth(root->right, k - leftsize - root->count);
}

// 前驱
int predecessor(TreeNode* root, int x){
    int ans = (1 << 31) + 1;
    while (root){
        if (root->value < x) ans = root->value, root = root->right;
        else root = root->left;
    }
    return ans;
}

// 后继
int successor(TreeNode* root, int x){
    int ans = 2147483647;
    while (root){
        if (root->value > x) ans = root->value, root = root->left;
        else root = root->right;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, op, x;
    cin >> q;
    TreeNode* root = nullptr;

    while (q--){
        cin >> op >> x;
        if (op == 1) cout << query(root, x) << "\n";
        else if (op == 2) cout << kth(root, x) << "\n";
        else if (op == 3) cout << predecessor(root, x) << "\n";
        else if (op == 4) cout << successor(root, x) << "\n";
        else root = insert(root, x);
    }
}
