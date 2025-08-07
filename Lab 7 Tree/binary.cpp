#include<iostream>
#include<vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};


Node* insertValTree(int val, Node* root){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root -> left = insertValTree(val, root->left);
    }
    if(val > root->data){
        root -> right = insertValTree(val, root->right);
    }
    return root;
}

Node* buildTree(vector<int> dataa){
    Node* root = NULL;
    int length = dataa.size();
    for(int i = 0; i < length; i++){
        root = insertValTree(dataa[i], root);
    }
    return root;
}

    

void preOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data<< ' ';
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    return;
}

void inOrderTraversal(Node* root){
    if(root == NULL ) return;
    inOrderTraversal(root->left);
    cout << root->data << ' ' ;
    inOrderTraversal(root->right);
    return;
}

void postOrderTraversal(Node* root){
    if(root == NULL ) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << ' ' ;

    return;
}

int main(){

    vector<int> givenData = {45, 12, 34, 33, 10, 20, 15, 67, 56, 70, 48, 26};
    
    // Node* root = NULL;
    // for(int i =0; i<length; i++){
    //     root = buildTree(givenData[i], root);
    // }
    Node* root = buildTree(givenData);
    preOrderTraversal(root);
    cout << endl;
    cout << endl;
    inOrderTraversal(root);
    cout << endl;
    cout<< endl;
    postOrderTraversal(root);
}