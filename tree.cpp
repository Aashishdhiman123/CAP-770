 #include <iostream>

// Define a node structure for the binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary tree class
class BinaryTree {
private:
    TreeNode* root;

    // Helper function to recursively insert a node
    TreeNode* insertRecursive(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }

        if (value < root->data) {
            root->left = insertRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

    // Helper function to recursively search for a value
    bool searchRecursive(TreeNode* root, int value) {
        if (root == nullptr) {
            return false;
        }

        if (value == root->data) {
            return true;
        } else if (value < root->data) {
            return searchRecursive(root->left, value);
        } else {
            return searchRecursive(root->right, value);
        }
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Destructor
    ~BinaryTree() {
        // Call a helper function to delete all nodes
        destroyTree(root);
    }

    // Public function to insert a node
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Public function to search for a value
    bool search(int value) {
        return searchRecursive(root, value);
    }

private:
    // Helper function to delete all nodes
    void destroyTree(TreeNode* root) {
        if (root != nullptr) {
            destroyTree(root->left);
            destroyTree(root->right);
            delete root;
        }
    }
};

int main() {
    // Create a binary tree
    BinaryTree tree;

    // Insert some elements
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    // Search for elements
    std::cout << "Searching for 7: " << (tree.search(7) ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for 20: " << (tree.search(20) ? "Found" : "Not found") << std::endl;

    return 0;
}
