#include <iostream>

using namespace std;

struct Node {
    int left;
    int right;
};
static Node tree[26];

void preorder(int node);
void inorder(int node);
void postorder(int node);

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < 26; i++) {
        tree[i].left = -1;
        tree[i].right = -1;
    }

    for (int i = 0; i < N; i++) {
        char parent;
        cin >> parent;
        char leftChild, rightChild;
        cin >> leftChild >> rightChild;
        if (leftChild != '.') {
            tree[(parent - 'A')].left = leftChild - 'A';
        }
        if (rightChild != '.') {
            tree[(parent - 'A')].right = rightChild - 'A';
        }
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';
}

void preorder(int node) {
    if (node == -1) return;
    cout << char(node + 'A');
    preorder(tree[node].left);
    preorder(tree[node].right);
}

void inorder(int node) {
    if (node == -1) return;
    inorder(tree[node].left);
    cout << char(node + 'A');
    inorder(tree[node].right);
}

void postorder(int node) {
    if (node == -1) return;
    postorder(tree[node].left);
    postorder(tree[node].right);
    cout << char(node + 'A');
}