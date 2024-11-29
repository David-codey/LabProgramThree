#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Pokemon.h"
#include <iostream>

template <typename T>
class BinaryTree{
    private: 
        struct treeNode{
            treeNode* left;
            treeNode* right;
            T value;
        };
        treeNode* rootNode;
        void insert(treeNode** nodePtr, treeNode* newNode){
            if(nodePtr == nullptr){
                *nodePtr = newNode;
            }else if(newNode->value < (*nodePtr)->value){
                insert(&(*nodePtr)->left, newNode);
            }else{
                insert(&(*nodePtr)->right, newNode);
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
                cout << (*nodePtr)->rootNode << endl;
                displayInOrder(nodePtr->right);
            }
        }

    public:
        BinaryTree(){ // constructor with no parameters
            rootNode = NULL;
        }
        ~BinaryTree(){
            destroySubTree(rootNode);
        }
        void insertNode(T tree){ // inserts the node 
            treeNode* newNode = nullptr;

            newNode = new treeNode;
            newNode-> value = tree;
            newNode->left = newNode->right = nullptr;
            insert(&rootNode,newNode);
        }
        void displayInOrder()const{
            displayInOrder(rootNode);
        }
        bool searchNode(T node){
            treeNode *nodePtr = rootNode;
            
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

#endif