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
        void insert(treeNode&* nodePtr, treeNode&* newNode){
            if(nodePtr == nullptr){
                nodePtr = newNode;
            }else if(newNode->value < nodePtr->value){
                insert(nodePtr->left, newNode);
            }else{
                insert(nodePtr->right, newNode);
            }
        }
        void destroySubTree(treeNode* nodePtr){
            if(nodePtr){
                if(nodePtr->left){
                    destroySubTree(nodePtr->left);
                }
                if(nodePtr->right){
                    destroySubTree(nodePtr->right);
                }
                delete nodePtr;
            }
        }
        void displayInOrder(treeNode* nodePtr) const{
            if(nodePtr){
                displayInOrder(nodePtr->left);
                cout << nodePtr->root << endl;
                displayInOrder(nodePtr->right);
            }
        }

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
        bool searchNode(T node){
            treeNode *nodePtr = root;
            
            while(nodePtr){// while  nodePtr exists
                if(nodePtr->value == node){ // if found
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