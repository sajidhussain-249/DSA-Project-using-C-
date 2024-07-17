#include <iostream>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    TreeNode* search(int key) {
        return search(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void inorderTraversal() {
        inorderTraversal(root);
        cout << endl;
    }

private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }

        if (key < node->val) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }

        return node;
    }

    TreeNode* search(TreeNode* node, int key) {
        if (node == nullptr || node->val == key) {
            return node;
        }

        if (key < node->val) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    TreeNode* deleteNode(TreeNode* node, int key) {
        if (node == nullptr) {
            return node;
        }

        if (key < node->val) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->val) {
            node->right = deleteNode(node->right, key);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteNode(node->right, temp->val);
        }

        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;

        while (current && current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->val << " ";
            inorderTraversal(node->right);
        }
    }
};

int main() {
    BinarySearchTree bst;
    int choice, value;

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Inorder Traversal\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // clear the fail state
            cin.ignore(INT_MAX, '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    continue;
                }
                bst.insert(value);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    continue;
                }
                cout << (bst.search(value) != nullptr ? "Found" : "Not Found") << endl;
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    continue;
                }
                bst.deleteNode(value);
                break;
            case 4:
                cout << "Inorder Traversal: ";
                bst.inorderTraversal();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
