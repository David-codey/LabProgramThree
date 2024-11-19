#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Pokemon.h"
#include <iostream>

template <typename T>
class BinarySearchTree{
    private: 
        struct treeNode{
            treeNode* left;
            treeNode* right;
            T value;
        };
        treeNode* rootNode;
    public:
        BinarySearchTree(){ // constructor with no parameters
            root = NULL;
        }
        ~BinarySearchTree(){
            destroySubTree(root);
        }
        void insertNode(T tree){ // inserts the node 
            treeNode* newNode = nullptr;

            newNode = new treeNode;
            newNode-> value = tree;
            newNode->left = newNode->right = nullptr;
            insert(root,newNode);
        }
        void displayInOrder(treeNode* nodePtr) const{
            if(nodePtr){
                cout << nodePtr->root << endl;
                displayInOrder(nodePtr->left);
                displayInOrder(nodePtr->right);
            }
        }
        bool searchNode(T node){
            treeNode *nodePtr = root;
            while(nodePtr){
                if(nodePtr->value == node){
                    return true;
                }else if(node < nodePtr->value){
                    nodePtr = nodePtr->left;
                }else{
                    nodePtr = nodePtr->right;
                }
            }
            return false;
        }

};

#endif BINARYSEARCHTREE_H