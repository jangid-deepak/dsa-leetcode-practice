#include <iostream>

using namespace std;



class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

struct Pointer {
    Node* head;
    Node* tail;
};

class LinkedList {
    private:
        Node* head;
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            length = 1;
        }
    
        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    
        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        int getLength() {
            return length;
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }
    
        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currentNode = head;
                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
            length++;
        }
    
        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }
        
        void reverseBetween(int m, int n) {
            
        }
        
        Pointer reverse(Node* head, int num) {
            Node* prevPointer = nullptr;
            Node* current = head;
            Node* temp = nullptr;
            while(current) {
                 


                current = current->next;

                cout << head->value << " ";
                // reverse connection
                head->next = prevPointer;
            }
        }
        
};


int main() {

    LinkedList list(1);
    list.append(2);
    list.append(3);
    list.append(5);
    list.append(6);

    // list.printList();

    list.reverse(list.getHead(), 3);

    return 0;
}