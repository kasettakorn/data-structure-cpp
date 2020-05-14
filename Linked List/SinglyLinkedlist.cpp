#include <iostream>
using namespace std;
class Node {
    public:
        int data;
        Node *next;
        Node(int d) {
            data = d;
            next = NULL;
        }
};
class linkedlist {
    public:
        Node *head, *tail;
        linkedlist() 
        {
            head = NULL;
            tail = NULL;
        }
        void append(int data)
        {
            Node *new_Node = new Node(data);
            if (head == NULL) {
                head = new_Node;
                tail = new_Node;
            }
            else {
                tail->next = new_Node;
                tail = new_Node;
            }
            
        }
        void deleteNode(int data) {
            if (head->data == data) {
                head = head->next;
            }
            Node *currentNode = head;
            while (currentNode->next != NULL) {
                if (currentNode->next->data == data) {
                    if (currentNode->next->next != tail) {
                        currentNode->next = currentNode->next->next;
                    }
                    else {
                        tail->next = NULL;
                        currentNode->next = NULL;
                        tail = currentNode;
                    }
                }
                currentNode = currentNode->next;
            }
        }
        void insertHead(int data) {
            Node *newNode = new Node(data);
            newNode->next = head;
            head = newNode;

        }
        
        void display() 
        {
            Node *currentNode = head;
            while (currentNode != NULL) {
                cout << currentNode->data << " ";
                currentNode = currentNode->next;
            }


        }

        

};
int main()
{
    linkedlist linkedlist;
    linkedlist.append(4);
    linkedlist.append(2);
    linkedlist.append(4);
    linkedlist.append(5);
    linkedlist.append(4);
    linkedlist.deleteNode(5);
    linkedlist.display();
    return 0;
}

