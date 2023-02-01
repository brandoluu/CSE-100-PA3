#include "BinaryTree.h"

int calculateHeights(BinaryTree::Node * root){
    if (root == nullptr){
        return 0; 
    }

    int countRight = 1; 
    int countLeft = 1; 
    countLeft += calculateHeights(root->leftChild);
    countRight += calculateHeights(root->rightChild);

    return max(countRight, countLeft); 
}

void getBalance(BinaryTree::Node * root, unordered_map<int, int> & map){
    if (root == nullptr){
        return; 
    }

    getBalance(root->leftChild, map);

    getBalance(root->rightChild, map);

    map.insert({root->label, calculateHeights(root->rightChild) - calculateHeights(root->leftChild)});
    
}

/**
 * Implement balanceFactors() correctly
 */
unordered_map<int,int> BinaryTree::balanceFactors() {
    /* YOUR CODE HERE */
    unordered_map<int,int> balanceMap; 

    balanceMap = unordered_map<int, int>();

    getBalance(root, balanceMap);

    return balanceMap; 
}
