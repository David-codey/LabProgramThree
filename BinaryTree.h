#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Pokemon.h"
#include <iostream>

template <typename T>
class BinaryTree{ // class definition
    private: 
        struct treeNode{ //struct for binary tree nodes
            treeNode* left;
            treeNode* right;
            T value;
        };
        treeNode* rootNode; // root
        void insert(treeNode*& nodePtr, treeNode*& newNode){
            if(nodePtr == nullptr){ // if nodePtr equals null
                nodePtr = newNode;
            }else if(newNode->value < nodePtr->value){// if node has someting in the right 
                insert(nodePtr->left, newNode);
            }else{ //if node has something in the left
                insert(nodePtr->right, newNode);
            }
        }
        void destroySubTree(treeNode* nodePtr){
            if(nodePtr){// if there is a node pointer
                if(nodePtr->left){ // if there is something in the left
                    destroySubTree(nodePtr->left);
                }
                if(nodePtr->right){ // if there is something in the right
                    destroySubTree(nodePtr->right);
                }
                delete nodePtr;
            }
        }
        void displayInOrder(treeNode* nodePtr) const{
            if(nodePtr){ // if there is a node
                displayInOrder(nodePtr->left);
                cout << nodePtr->value << endl;
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
            insert(rootNode,newNode);
        }
        void displayInOrder()const{
            displayInOrder(rootNode);
        }
        bool searchNode(T node){
            treeNode* nodePtr = rootNode;
            while(nodePtr){// while  nodePtr exists
                if(nodePtr->value == node){ // if found
                    return true;
                }else if(node < nodePtr->value){ // if node is pointing left
                    nodePtr = nodePtr->left;
                }else{ // if node is pointing right
                    nodePtr = nodePtr->right;
                }
            }
            return false;
        }

};

#endif