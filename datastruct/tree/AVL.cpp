#include <cmath>
struct TreeNode{
    int value{};
    int height{}; // 节点高度(离他的最远的叶节点的边)
    TreeNode *left{}, *right{}; // {}会把指针初始化为nullptr

    TreeNode() = default;
    explicit TreeNode(int x) : value(x) {} // explicit 可以避免int隐式转换为TreeNode
};

int height(TreeNode* node){
    return node == nullptr ? -1 : node->height;
}

void updateHeight(TreeNode *node){ // 根据子结点的高度
    if (node == nullptr) return;
    node->height = std::max(height(node->left), height(node->right)) + 1;
}
//  -1 <= BF <= 1
int balanceFactor(TreeNode *node){
    return node == nullptr ? 0 : height(node->left) - height(node->right);
}

// f >= 2, 右旋, 返回旋转后的根节点
TreeNode* rightRotate(TreeNode *node){
    TreeNode* child = node->left;
    TreeNode* grandchild = child->right;

    node->left = grandchild;
    child->right = node;;
    // 更新高度从下至上
    updateHeight(node);
    updateHeight(child);
    return child;
}

// f <= -2, 左旋, 返回旋转后的根节点
TreeNode* leftRotate(TreeNode *node){
    TreeNode* child = node->right;
    TreeNode* grandchild = child->left;

    node->right = grandchild;
    child->left = node;

    updateHeight(node);
    updateHeight(child);
    return child;
}

// f(node) >= 2且 f(child) < 0, 先child左旋后node右旋
// f(node) <= -2且 f(child) > 0, 先node右旋后child左旋

// 返回旋转后的根节点
TreeNode* rotate(TreeNode *node){
    int _balanceFactor = balanceFactor(node);
    if (_balanceFactor >= 2){
        TreeNode* child = node->left;
        if (balanceFactor(child) < 0){
            node->left = leftRotate(child);
        }
        return rightRotate(node);
    }else if (_balanceFactor <= -2){
        TreeNode* child = node->right;
        if (balanceFactor(child) > 0){
            node->right = rightRotate(child);
        }
        return leftRotate(node);
    }

    return node;
}

TreeNode* insert(TreeNode* root, int value){
    root = insertHelper(root, value);
}

TreeNode* insertHelper(TreeNode* node, int value){
    if (node == nullptr) return new TreeNode(value); // 空结点直接返回
    if (value == node->value) return node; // 重复结点直接返回
    else if (value < node->value) node->left = insertHelper(node->left, value); // 左子树递归
    else node->right = insertHelper(node->right, value); // 右子树递归

    // 左右子树递归后做的事情(从下至上)
    updateHeight(node);
    node = rotate(node);
    return node; // 旋转后递归返回新的根节点
}

TreeNode* remove(TreeNode* root, int value){
    root = removeHelper(root, value);
}

TreeNode* removeHelper(TreeNode* node, int value){
    if (node == nullptr) return nullptr; // 空结点直接返回
    if (value == node->value){  // 重复结点直接返回
        // 叶节点或者链节点
        if (node->left == nullptr || node->right == nullptr){
            TreeNode *child = node->left ? node->left : node->right;
            if (child == nullptr){ // 叶节点
                delete node;
                return nullptr;
            }else{ // 链节点
                delete node;
                node = child;
            }
        }else{ // 一般节点, 找到该节点右子树最小的那个节点来代替该节点
            TreeNode *tmp = node->right;
            while (tmp->left){
                tmp = tmp->left;
            }
            int tmpval = tmp->value;
            node->right = removeHelper(node->right, tmp->value);
            node->value = tmpval;
        }
    }
    else if (value < node->value) node->left = removeHelper(node->left, value); // 左子树递归
    else node->right = removeHelper(node->right, value); // 右子树递归

    // 左右子树递归后做的事情(从下至上)
    updateHeight(node);
    node = rotate(node);
    return node; // 旋转后递归返回新的根节点
}
