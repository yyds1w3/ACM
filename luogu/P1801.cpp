#include <bits/stdc++.h>
using namespace std;

struct AVLNode {
    int value;
    int height;
    int size;  // 子树大小
    int count; // 重复数量
    AVLNode *left, *right;
    AVLNode(int v) : value(v), height(1), size(1), count(1), left(nullptr), right(nullptr) {}
};

int getHeight(AVLNode* node) { return node ? node->height : 0; }
int getSize(AVLNode* node) { return node ? node->size : 0; }

void update(AVLNode* node) {
    if(!node) return;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    node->size = node->count + getSize(node->left) + getSize(node->right);
}

int getBalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// 右旋
AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    update(y);
    update(x);
    return x;
}

// 左旋
AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    update(x);
    update(y);
    return y;
}

// 插入
AVLNode* insert(AVLNode* node, int val) {
    if(!node) return new AVLNode(val);

    if(val == node->value) {
        node->count++;
    } else if(val < node->value) {
        node->left = insert(node->left, val);
    } else {
        node->right = insert(node->right, val);
    }

    update(node);

    int balance = getBalance(node);

    // LL
    if(balance > 1 && val < node->left->value)
        return rotateRight(node);
    // RR
    if(balance < -1 && val > node->right->value)
        return rotateLeft(node);
    // LR
    if(balance > 1 && val > node->left->value) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // RL
    if(balance < -1 && val < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// 查询第 k 小元素
int queryKth(AVLNode* node, int k) {
    if(!node) return INT_MIN;
    int leftSize = getSize(node->left);
    if(k <= leftSize) return queryKth(node->left, k);
    if(k <= leftSize + node->count) return node->value;
    return queryKth(node->right, k - leftSize - node->count);
}

int a[200001], b[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    for(int i=1;i<=m;i++) cin >> a[i];
    for(int j=1;j<=n;j++) cin >> b[j];

    AVLNode* root = nullptr;
    int i_counter = 0, r = 1;
    for(int l=1; l<=m; l++) {
        root = insert(root, a[l]);
        while(r <= n && b[r] == l) {
            i_counter++;
            cout << queryKth(root, i_counter) << "\n";
            r++;
        }
    }
}
