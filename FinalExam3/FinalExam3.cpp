// Final Exam P3
// Braden Owens
// 7/25/2022

#include <iostream>
#include "tree.h"
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
};
int righth(struct node* node)
{
    int height = 0;
    while (node) {
        height++;
        node = node->right;
    }
    return heightt;
}
int lefth(struct node* node)
{
    int height = 0;
    while (node) {
        height++;
        node = node->left;
    }
    return height;
}

int NodeCount(struct node* root)
{
    
    if (root == NULL)
        return 0;
   
    int lh = lefth(root);
    int rh = righth(root);
   
    if (lh == rh)
        return (1 << lh) - 1;
    
    return 1 + NodeCount(root->left)
        + NodeCount(root->right);
}
int countinternalleaf(struct Node* root)
{
    if (root == NULL || (root->left == NULL &&
        root->right == NULL))
        return 0;

    
    return 1 + countinternalleaf(root->left) +
        countinternalleaf(root->right);
}

int main()
{
    return 0;
}


https://www.reddit.com/r/cpp_questions/comments/wztagx/how_to_split_a_string_with_multiple_delimiters_in/