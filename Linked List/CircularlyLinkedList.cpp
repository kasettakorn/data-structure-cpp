#include <iostream>
using namespace std;
class Node {
    public:
        int data;
        Node *next;
        Node(int _data) {
            data = _data;
            next = NULL;
        }
};
class CircularlyLinkedList {
    public:
        Node *head;
        CircularlyLinkedList(int data) {
            head = new Node(data);
            head->next = head;
        }
        void append(int data) {
            Node *currentNode = head;
            while (currentNode->next != head) {
                currentNode = currentNode->next;
            }
            Node *newNode = new Node(data);
            currentNode->next = newNode;
            newNode->next = head;
        }
        void print() {
            Node *currentNode = head;
            do {
                cout << currentNode->data << " -> ";
                currentNode = currentNode->next;
            }while (currentNode != head);
            cout << currentNode->data << endl;
        }
    
};
int main()
{
    CircularlyLinkedList circular(5);
    
    for(int i = 1; i <= 10; i++)
    {
        circular.append(i);
    }
    
    circular.print();
    return 0;
}
