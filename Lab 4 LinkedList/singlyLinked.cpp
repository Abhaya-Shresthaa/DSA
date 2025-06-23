#include <iostream>
using namespace std;

class Node {
    
private:
    int val;
    Node *next;

public:
    Node(int val) : val(val), next(nullptr) {}

    static void insertAtHead(Node* &head, int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    static void insertAtTail(Node *head, int val) {
        if (head == nullptr) return; // Return if empty list
        Node *temp = head;
        Node *newNode = new Node(val);
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode; //pointing the previous tail node to the newly added tail node
    }


    static void insertAtPosition(Node* &head, int val, int position) {
        if (position < 0) return;

        if (position == 0) {
            insertAtHead(head, val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        int currPos = 0;

        while (currPos != position - 1 && temp != nullptr) {
            temp = temp->next;
            currPos++;
        }

        if (temp == nullptr) return; // Invalid position

        newNode->next = temp->next;
        temp->next = newNode;
    }

    static void insertAfterNode(Node* &head, int val, int data) {
        Node* temp = head;

        while (temp != nullptr && temp->val != data) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    static void insertBeforeNode(Node* &head, int val, int data) {
        if (head == nullptr) return;

        if (head->val == data) {
            insertAtHead(head, val);
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->val != data) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return; // data not found

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    static void deleteFromHead(Node* &head) {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next; // changing head to the next node after the head
        delete temp;
    }

    static void deleteFromTail(Node* head) {
        if (head == nullptr || head->next == nullptr) return; // If zero or one node, return

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    static void deleteAfterNode(Node* head, int data) {
        if (head == nullptr) return;

        Node* temp = head;
        while (temp != nullptr && temp->val != data) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) return; // No such node or no node after it

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    static void deleteFromPosition(Node* &head, int position) {
        if (head == nullptr || position < 0) return;

        if (position == 0) {
            deleteFromHead(head);
            return;
        }

        int currPosition = 0;
        Node* temp = head;

        while (currPosition != position - 1 && temp != nullptr) {
            temp = temp->next;
            currPosition++;
        }

        if (temp == nullptr || temp->next == nullptr) return; // Invalid position

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    static void display(Node* &head) {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    Node *head = nullptr;

    cout << endl << "Insertion Operations" << endl;
    cout << "-------------------------------";

    Node::insertAtHead(head, 1);
    
    cout << endl << "After inserting 1 at head: \n";
    Node::display(head); 

    Node::insertAtHead(head, 5);
    cout << endl << "After inserting 5 at head: \n";
    Node::display(head);

    Node::insertAtTail(head, 33);
    cout << endl << "After inserting 33 at tail: \n";
    Node::display(head);

    Node::insertAtPosition(head, 99, 1); 
    cout << endl << "After inserting 99 at position 1:\n";
    Node::display(head); 


    Node::insertAfterNode(head, 88, 1); 
    cout << endl << "After inserting 88 after value 1:\n";
    Node::display(head); 


    Node::insertBeforeNode(head, 77, 99); 
    cout << endl << "After inserting 77 before value 99:\n";
    Node::display(head); 


    // DELETION OPERATIONS
    cout << endl << "Deletion Operations" << endl ;
    cout << "-------------------------------";

    Node::deleteFromHead(head);
    cout << endl << "After deleting from the head: \n";
    Node::display(head); // 1 -> 45 -> 33 -> nullptr

    Node::deleteFromTail(head);
    cout << endl << "After deleting from the tail: \n";
    Node::display(head); // 1 -> 45 -> nullptr

    Node::deleteAfterNode(head, 1);
    cout << endl << "After deleting after a node 1 \n";
    Node::display(head); // 1 -> nullptr

    cout << endl << "After inserting 19,88,99 at the head position one by one:" << endl;
    Node::insertAtHead(head, 99);
    Node::insertAtHead(head, 88);
    Node::insertAtHead(head, 19);
    Node::display(head); // 77 -> 88 -> 99 -> 1 -> nullptr

    Node::deleteFromPosition(head, 2);
    cout << endl << "After deleting from position 2 of the list: \n";
    Node::display(head); // 77 -> 88 -> 1 -> nullptr

    return 0;
}
