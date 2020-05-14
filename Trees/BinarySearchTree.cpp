#include <iostream>
using namespace std;
class Node {
    public:
        int data;
        Node *leftchild, *rightchild, *parent;
        Node(int d) {
            data = d;
            leftchild = NULL;
            rightchild = NULL;
            parent = NULL;
        }
};
class BinarySearchTree {
    public:
        Node *root;
        BinarySearchTree(int data) {
            root = new Node(data);
        }
        void insert(int data) {
            Node *currentNode = root, *parentNode;
            while (true) {
                parentNode = currentNode;
                if (data < currentNode->data) {
                    currentNode = currentNode->leftchild;
                    if (currentNode == NULL) {
                        parentNode->leftchild = new Node(data);
                        currentNode = parentNode->leftchild;
                        currentNode->parent = parentNode;
                        return;
                    }
                }
                else {
                    currentNode = currentNode->rightchild;
                    if (currentNode == NULL) {
                        parentNode->rightchild = new Node(data);
                        currentNode = parentNode->rightchild;
                        currentNode->parent = parentNode;
                        return;
                    }               
                }
            }
        }
        void deleteNode(int data) {
            Node *currentNode = root;
            while (currentNode != NULL) {
                if (currentNode->data == data) {
                    if (currentNode->leftchild != NULL && currentNode->rightchild != NULL) {
                        Node *tempNode = currentNode->leftchild;
                        while (true) {
                            int largestNode = tempNode->data;
                            if (tempNode->rightchild != NULL) {
                                largestNode = tempNode->rightchild->data;
                                tempNode = tempNode->rightchild;
                            }                            
                        }


                       
                    }
                    
                }
                else if (currentNode->data > data) {
                    currentNode = currentNode->leftchild;
                }
                else {
                    currentNode = currentNode->rightchild;
                }
                                
            }

        }
        void preorderTraversal(Node *node) {
            if (node != NULL) {
                cout << node->data << " ";
                preorderTraversal(node->leftchild);
                preorderTraversal(node->rightchild);
            }
        }
        void inorderTraversal(Node *node) {
            if (node != NULL) {
                inorderTraversal(node->leftchild);
                cout << node->data << " ";
                inorderTraversal(node->rightchild);
            }
        }
        void postorderTraversal(Node *node) {
            if (node != NULL) {
                postorderTraversal(node->leftchild);
                postorderTraversal(node->rightchild);
                cout << node->data << " ";

            }
        }

};
int main() {
    BinarySearchTree bst(10);
    bst.insert(5);
    bst.insert(2);
    bst.insert(9);
    bst.insert(11);
    bst.insert(8);
   
    bst.preorderTraversal(bst.root);
}