#include <iostream>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* create_node(int value){
    TreeNode* new_node = new TreeNode;
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
}

TreeNode* initialization(TreeNode* root){
    root = NULL;
    return root;
}

TreeNode* search(TreeNode* root, int value){
    if (root == NULL) return NULL;
    while(1){
        if(root->data > value){
            if (root->left == NULL) return NULL;
            root = root->left;
        }else if (root->data < value)
        {
            if (root->right == NULL) return NULL;
            root = root->right;
        }
        else return root;
    }
    return NULL;
}

TreeNode* search_recursive(TreeNode* root, int value){
    if (root == NULL) return NULL;
    if (root->data > value){
        if (root->left == NULL) return NULL;
        else return search_recursive(root->left, value);
    } 
    else if (root->data < value){
        if(root->right == NULL) return NULL;
        else return search_recursive(root->right, value);
    }
    else return root;
}

TreeNode* insertion(TreeNode* root, int value){
    TreeNode* new_node = create_node(value);
    if (search_recursive(root, value) != NULL)
    {
        cout << "Exist node " << value << " in binary search tree" << endl;
        return root; 
    }
    if (root == NULL) return new_node;
    TreeNode* P = root;
    while (1)
    {
        if (P->data > value){
            if (P->left == NULL) 
            {
                P->left = new_node;
                break;
            }
            else P = P->left;
        }
        else{
            if (P->right == NULL){
                P->right = new_node;
                break;
            }
            else P = P->right;
        }
    }
    return root;
}

TreeNode* insert_recursive(TreeNode* root, int value){
    if (search_recursive(root, value) != NULL)
    {
        cout << "Exist node " << value << " in binary search tree" << endl;
        return root;
    }
    else
    {
        if (root == NULL) return create_node(value);
        if (root->data > value){
            if (root->left == NULL){
                root->left = create_node(value);
            }
            else
            {
                insert_recursive(root->left, value);
            }
        }
        else{
            if (root->right == NULL){
                root->right = create_node(value);
            }
            else
            {
                insert_recursive(root->right, value);
            }
        }
        return root;
    }
}

TreeNode* find_left_most_node(TreeNode *root){
    if (root == NULL) return NULL;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

TreeNode* remove(TreeNode* root, int x){
    if (search_recursive(root, x) == NULL){
        cout << "Doesn't exits node " << x << " in tree" << endl;
        return root;
    }
    else
    {
        // Step 1: Find node x which need to remove
        if (root->data > x) 
        {
            root->left = remove(root->left, x);
        }
        else if (root->data < x)
        {
            root->right = remove(root->right, x);
        }
        else
        {
            // Step 2: Remove node
            // Case 1: X is external
            if (root->left == NULL && root->right == NULL) return NULL;
            // Case 2: X has 1 child node
            if (root->left != NULL && root->right == NULL) return root->left;
            if (root->left == NULL && root->right != NULL) return root->right;
            // Case 3: X has 2 child node
            TreeNode *left_most_node = find_left_most_node(root->right);
            root->data = left_most_node->data;
            root->right = remove(root->right, left_most_node->data);
        }
        return root;
    }
}

int main(){
    // Init binary search tree
    int arr[7] = {6, 2, 9, 1, 4, 8, 4};
    TreeNode *root;
    root = initialization(root);
    for (int i = 0; i < 7; i++){
        root = insert_recursive(root, arr[i]);
    }
    // Find node 2
    TreeNode* tmp = search_recursive(root, 2);
    if (tmp == NULL) cout << "Doesn't exist node 2" << endl;
    else cout << "Exist node 2" << endl;
    // Find node 19
    tmp = search_recursive(root, 19);
    if (tmp == NULL) cout << "Doesn't exist node 19" << endl;
    else cout << "Exist node 19" << endl;
    // Remove node 2
    root = remove(root, 2);
    return 0;
}