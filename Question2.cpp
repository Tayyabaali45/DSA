#include <iostream>
#include <queue>

using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int energy;  // Represents the energy consumption in kilowatts (kW)
    TreeNode* left;  // Left child
    TreeNode* right; // Right child

    // Constructor to initialize a node with a given energy value
    TreeNode(int val) : energy(val), left(nullptr), right(nullptr) {}
};

// Function to calculate the difference between energy consumption at odd and even levels
int calculateEnergyDifference(TreeNode* root) {
    if (!root) {
        return 0; // If the tree is empty, return 0
    }

    // Queue for level-order traversal
    queue<TreeNode*> q;
    q.push(root);

    // Variables to hold the sums for odd and even levels
    int oddLevelSum = 0, evenLevelSum = 0;
    int level = 1;  // Start from level 1 (the root)

    while (!q.empty()) {
        int levelSize = q.size();  // Get the number of nodes at the current level
        int currentLevelSum = 0;

        // Process all nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            currentLevelSum += node->energy;  // Add the energy consumption to the level sum

            // Add the child nodes to the queue for the next level
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        // If the level is odd, add to the oddLevelSum, else to evenLevelSum
        if (level % 2 == 1) {
            oddLevelSum += currentLevelSum;
        } else {
            evenLevelSum += currentLevelSum;
        }

        // Move to the next level
        ++level;
    }

    // Calculate and return the difference
    return oddLevelSum - evenLevelSum;
}

int main() {
    TreeNode* root = new TreeNode(50);  // Root node with energy value 50
    root->left = new TreeNode(30);      // Left child with energy value 30
    root->right = new TreeNode(40);     // Right child with energy value 40
    root->left->left = new TreeNode(10);    // Left child of 30 with energy 10
    root->left->right = new TreeNode(25);   // Right child of 30 with energy 25
    root->right->left = new TreeNode(35);   // Left child of 40 with energy 35
    root->right->right = new TreeNode(45);  // Right child of 40 with energy 45

    // Calculate the energy difference between odd and even levels
    int difference = calculateEnergyDifference(root);
    cout << "Energy difference between odd and even levels: " << difference << endl;

    // Clean up memory (delete nodes after use)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right; 
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
