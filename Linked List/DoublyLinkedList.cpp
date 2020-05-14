#include <iostream>
#define dummy -1
using namespace std;
class Node {
    public:
        int data;
        Node *next;
        Node *prev;
        Node() {
            data = dummy;
            next = NULL;
            prev = NULL;
        }
        Node(int d) {
            data = d;
            next = NULL;
            prev = NULL;
        }
};
class DoublyLinkedList {
    public:
        Node *header, *trailer, *node;
        DoublyLinkedList() {
            header = new Node();
            trailer = new Node();
            header->next = trailer;
            trailer->prev = header;
        }
        void append(int data) { //ต่อท้าย
            Node *currentNode = header;
            while (currentNode->next != trailer) {
                currentNode = currentNode->next;
            }
            Node *newnode = new Node(data);
            currentNode->next = newnode;
            newnode->prev = currentNode;
            newnode->next = trailer;
            trailer->prev = newnode;
        }
        void insertHead() {
            
        }
        void delete_node(int data) {
            Node *currentNode = header;
            while (currentNode->next != trailer) {
                if (currentNode->next->data == data) {
                    currentNode->next = currentNode->next->next;
                    currentNode->next->prev = currentNode;
                    return;
                }
                currentNode = currentNode->next;
            }
        }
        void printForward() {
            Node *currentNode = header;
            while (currentNode->next != trailer) {
                currentNode = currentNode->next;
                cout << currentNode->data << " -> ";
            }
            cout << "NULL" << endl;

        }
        void printBackward() {
            Node *currentNode = trailer;
            while (currentNode->prev != header) {
                currentNode = currentNode->prev;
                cout << currentNode->data << " -> ";
            }
            cout << "NULL" << endl;
        }
        

};
int main() {
    DoublyLinkedList doublyLinkedlist;
    for (int i=1 ; i<=10 ; i++) {
        doublyLinkedlist.append(i);
    }
    doublyLinkedlist.printForward();
    doublyLinkedlist.delete_node(6);
    doublyLinkedlist.printForward();
    doublyLinkedlist.printBackward();

}