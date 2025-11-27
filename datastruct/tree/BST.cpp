#include <iostream>
struct TreeNode{
    int value;
    TreeNode* left, *right;

    int size;
    int count;
    TreeNode(int value) : value(value), left(nullptr), right(nullptr), size(1), count(1) {}
};
// 本质是dfs, 中序遍历
void inorderTraversal(TreeNode *root){
    if (root == nullptr) return;

    inorderTraversal(root->left);
    std::cout << root->value << " ";
    inorderTraversal(root->right); 
}

// 一直搜索左子树
int findMin(TreeNode* root){
    if (root == nullptr) return -1;
    while (root->right != nullptr){
        root = root->right;
    }
    return root->value;
    
}
// 一直搜索右子树
int findMax(TreeNode* root){
    if (root == nullptr) return -1;
    while (root->right != nullptr){
        root = root->right;
    }
    return root->value;
}

//
TreeNode* is_exist(TreeNode* root,int value){
    if (root == nullptr) return nullptr;
    if (root->value == value)
        return root;
    else if (root->value < value)
        is_exist(root->right, value);
    else
        is_exist(root->left, value);
}

TreeNode* insert(TreeNode* root ,int value){
    if (root == nullptr) return new TreeNode(value);
    if (value == root->value)
        (root->count)++;
    else if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    
    root->size = root->count 
    + root->left ? root->left->size : 0
    + root->right ? root->right->size : 0;
    return root;
}
TreeNode* findMinNode(TreeNode *root){
    while (root->left != nullptr){
        root = root->left;
    }
    return root;
}
TreeNode* remove(TreeNode* root, int value){
    if (root == nullptr) return nullptr;
    if (value > root->value){
        remove(root->right, value);
    }else if (value < root->value){
        remove(root->left, value);
    }else{
        if (root->count > 1){
            (root->count)--;
        }else{
            if (root->left == nullptr && root->right == nullptr){
                root = nullptr;
                return root;
            }else if (root->left == nullptr || root->right == nullptr){
                (root->left == nullptr) ? root = root->right : root = root->left;
                return root;
            }else{ // 找到右子树的最小叶节点来替换即可
                TreeNode* succesor = findMinNode(root->right);
                // 替换的东西有 value count size(后面会自动维护) right
                root->value = succesor->value;
                root->count = succesor->count;
                // 删除原节点
                succesor->count = 1;
                root->right = remove(root->right, succesor->value); 
            }
        }
    
    }
    root->size = root->count + (root->left ? root->left->size : 0) +
               (root->right ? root->right->size : 0);
    return root;
}

int querySearch(TreeNode* root, int k){
    if (root == nullptr) return -1;
    int leftSize = root->left ? root->left->size : 0;
    if (k <= leftSize) return querySearch(root->left, k); // 左子树
    if (k <= root->count + leftSize) return root->value; // 本节点(实际返回的终点)
    return querySearch(root->right, k - leftSize - root->count); // 在右子树
}

