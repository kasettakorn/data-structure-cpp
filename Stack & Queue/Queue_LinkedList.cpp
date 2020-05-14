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
class Queue {
    private:
        Node *top;
        int size, MAX;
    public:
        Queue() {
            top = NULL;
            size = 0;
            MAX = 10;
        }
        ~Queue() {
            cout << "End of Queue";
        }
        bool isEmpty() {
            return top == NULL;
        }
        void enqueue(int data) {
            if (isEmpty()) {
                top = new Node(data);
                size++; 
            }
            else if (size > MAX) {
                cout << "Queue is full." << endl;
            }
            else {
                Node *currentNode = top;
                while (currentNode->next != NULL) {
                    currentNode = currentNode->next;
                }
                Node *newNode = new Node(data);
                newNode->data = data;
                newNode->next = NULL;
                currentNode->next = newNode;
                size++;

            }

        }
        int dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty." << endl;
                return -1;
            }
            int data = top->data;
            top = top->next;
            size--;
            return data;
        }
        void printQueue() {
            Node *currentNode = top;
            for (int i = 0; i < size; i++)
            {
                cout << currentNode->data << " <- ";
                currentNode = currentNode->next;
            }
            
        }

};
int main() {
    Queue queue;
    for (int i=1 ; i<=10 ; i++) {
        queue.enqueue(i);
    }
    queue.dequeue();
    queue.printQueue();

    
}