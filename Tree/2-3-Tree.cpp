#include <iostream>
using namespace std;

struct node {
    int keys[2];
    int cnt;
    node* childs[3];
};

class TwoThreeTree {
    node* root = nullptr;

    struct Split {
        node* left;
        int midKey;
        node* right;
        bool splitb;
    };

    node* createNode(int key) {
        node* nn = new node;
        nn->keys[0] = key;
        nn->cnt = 1;
        for (int i = 0; i < 3; i++)
            nn->childs[i] = nullptr;
        return nn;
    }

    bool isLeaf(node* n) {
        return n->childs[0] == nullptr;
    }

    void insertKey(node* n, int key) {
        if (n->cnt == 1) {
            if (key < n->keys[0]) {
                n->keys[1] = n->keys[0];
                n->keys[0] = key;
            } else {
                n->keys[1] = key;
            }
            n->cnt = 2;
        }
    }

    Split insert(node* n, int key) {
        if (isLeaf(n)) {
            if (n->cnt == 1) {
                insertKey(n, key);
                return {nullptr, 0, nullptr, false};
            }

            node* left = createNode(0);
            node* right = createNode(0);
            int mid;

            if (key < n->keys[0]) {
                left->keys[0] = key;
                right->keys[0] = n->keys[1];
                mid = n->keys[0];
            } else if (key > n->keys[1]) {
                left->keys[0] = n->keys[0];
                right->keys[0] = key;
                mid = n->keys[1];
            } else {
                left->keys[0] = n->keys[0];
                right->keys[0] = n->keys[1];
                mid = key;
            }

            left->cnt = right->cnt = 1;
            return {left, mid, right, true};
        }

        int idx;
        if (key < n->keys[0]) idx = 0;
        else if (n->cnt == 1 || key < n->keys[1]) idx = 1;
        else idx = 2;

        Split result = insert(n->childs[idx], key);
        if (!result.splitb) return {nullptr, 0, nullptr, false};

        if (n->cnt == 1) {
            if (idx == 0) {
                n->keys[1] = n->keys[0];
                n->keys[0] = result.midKey;
                n->childs[2] = n->childs[1];
                n->childs[0] = result.left;
                n->childs[1] = result.right;
            } else {
                n->keys[1] = result.midKey;
                n->childs[1] = result.left;
                n->childs[2] = result.right;
            }
            n->cnt = 2;
            return {nullptr, 0, nullptr, false};
        }

        node* left = createNode(0);
        node* right = createNode(0);
        int mid;

        if (idx == 0) {
            left->keys[0] = result.midKey;
            left->childs[0] = result.left;
            left->childs[1] = result.right;

            right->keys[0] = n->keys[1];
            right->childs[0] = n->childs[1];
            right->childs[1] = n->childs[2];
            mid = n->keys[0];
        } else if (idx == 1) {
            left->keys[0] = n->keys[0];
            left->childs[0] = n->childs[0];
            left->childs[1] = result.left;

            right->keys[0] = n->keys[1];
            right->childs[0] = result.right;
            right->childs[1] = n->childs[2];
            mid = result.midKey;
        } else {
            left->keys[0] = n->keys[0];
            left->childs[0] = n->childs[0];
            left->childs[1] = n->childs[1];

            right->keys[0] = result.midKey;
            right->childs[0] = result.left;
            right->childs[1] = result.right;
            mid = n->keys[1];
        }

        left->cnt = right->cnt = 1;
        return {left, mid, right, true};
    }

    void inorderTrav(node* n) {
        if (!n) return;

        if (n->cnt == 1) {
            if (!isLeaf(n)) inorderTrav(n->childs[0]);
            cout << n->keys[0] << " ";
            if (!isLeaf(n)) inorderTrav(n->childs[1]);
        } else {
            if (!isLeaf(n)) inorderTrav(n->childs[0]);
            cout << n->keys[0] << " ";
            if (!isLeaf(n)) inorderTrav(n->childs[1]);
            cout << n->keys[1] << " ";
            if (!isLeaf(n)) inorderTrav(n->childs[2]);
        }
    }

public:
    void insert(int key) {
        if (!root) {
            root = createNode(key);
            return;
        }

        Split result = insert(root, key);
        if (result.splitb) {
            node* newRoot = createNode(result.midKey);
            newRoot->childs[0] = result.left;
            newRoot->childs[1] = result.right;
            root = newRoot;
        }
    }

    void display() {
        inorderTrav(root);
        cout << endl;
    }
};

int main() {
    TwoThreeTree tree;
    int values[] = {10, 20, 5, 15, 25, 2, 8};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++) {
        tree.insert(values[i]);
    }    
    tree.display();
    return 0;
}
