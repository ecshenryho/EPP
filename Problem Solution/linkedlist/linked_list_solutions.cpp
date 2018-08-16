// Linked List Solutions for ACM EPP Review
// Contact omolazabal@csu.fullerton.edu if you have any questions or concerns.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

//Inserts at the front of the list
void insertFront(Node* &head, int element) {
    Node* newNode = new Node;   // Allocates a new node.
    newNode->data = element;    // Assigns a value for data in newNode.
    newNode->next = head;       // The node head points to is now the node that comes after newNode.
    head = newNode;             // NewNode is now the head.
}

// Prints the list
void printList(Node* &head) {
    Node* current = head;           // Creates pointer to front of list.
    if (current == NULL) {          // If list is empty, say it is empty.
        cout << "List is empty";
    }
    else {
        while (current != NULL) {           // Else, traverse the list until you hit NULL.
            cout << current->data << " ";   // As you are traversing, output the data.
            current = current->next;
        }
    }
}

// Inserts a node at a specified position
void insert(Node* &head, int element, int position) {
    if (position == 0)                  // If the position to insert at is 0, the call the insertFront function.
        insertFront(head, element);
    else {
        Node* newNode = new Node;       // Else, create a new node and set the data.
        newNode->data = element;
        Node* current = head;           // Create a pointer to the front of the list.
        while (position > 1) {          // Traverse to the position before the insert position using the current pointer.
            current = current->next;
            position--;
        }
        Node* temp = current->next;     // Create a temp pointer to the node that will come after the newly inserted node.
        current->next = newNode;        // Set current's next pointer equal to the new node
        newNode->next = temp;           // and set the new node's next pointer equal to temp.
    }
}

// Combines two lists into one
void combine(Node* &head1, Node* &head2) {
    if (head1 == NULL) {                // If list 1 contains nothing, then just set list 1 equal to list 2.
        head1 = head2;
        head2 = NULL;                   // Make list 2 empty.
    }
    else {                                      // Else ...
        Node* endOfList1 = head1;               // Create a pointer to the head of list 1.
        while (endOfList1->next != NULL) {      // Move that pointer all the way to the end of list 1.
            endOfList1 = endOfList1->next;
        }
        endOfList1->next = head2;               // Set that node's next equal to the beginning of list 2.
        head2 = NULL;                           // Make list 2 empty
    }
}

// Deletes all the nodes in a list
void deleteList(Node* &head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Creates a copy of a list. Returns a pointer to the new list
Node* copyList(Node* &head1) {
    Node* head2 = NULL;             // Create a pointer to NULL for the new list. head1 represents the list that will be copied, head2 is the new list
    Node* current = head1;          // Temporary traversal node for the list that is going to be copied

    while (current != NULL) {               // While traversing the og list...
        insertFront(head2, current->data);  // insert the elements to the front of the new list
        current = current->next;
    }
                                    // Everything is now copied, but in the wrong order. We need to reverse the list
    Node* previous = NULL;          // Create a pointer that will be pointing the previous node
    Node* middle = head2;           // Create a pointer that will be pointing the node between previous and next
    Node* next = head2;             // Create a pointer that will be pointing to the pointer next to middle

    while (next != NULL) {          // Until next is NULL
        next = middle->next;        // Previous(NULL) [Middle]--> [Next]--> . . .
        middle->next = previous;    // Previous(NULL) <--[Middle] [Next]--> . . .
        previous = middle;          // NULL <--[Middle & Previous] [Next] --> . . .
        middle = next;              // NULL <--[Previous] [Middle & Next]--> . . .
    }

    head2 = previous;       // Set head2 equal to the front of the new list
    return head2;
}


int main() {

    Node *list1 = NULL;
    insertFront(list1, 3);  //  inserts 1 at the front of the list;
    insertFront(list1, 1);

    cout << "List 1: ";
    printList(list1);
    cout << endl << endl;

    cout << "Inserting 2 and 4 into list 1...\n\n";
    insert(list1, 2, 1);    // inserts 2 at position 1
    insert(list1, 4, 3);

    cout << "List 1: ";
    printList(list1);
    cout << endl << endl;

    Node *list2 = NULL;
    insertFront(list2, 8);
    insertFront(list2, 7);
    insertFront(list2, 6);
    insertFront(list2, 5);

    cout << "List 2: ";
    printList(list2);
    cout << endl << endl;

    cout << "Combining list 1 and list 2...\n\n";
    combine(list1, list2);  // Combines List 1 and List 2

    cout << "List 1: ";
    printList(list1);
    cout << endl;
    cout << "List 2: ";
    printList(list2);
    cout << endl << endl;

    cout << "Copying list 1 into list 3...\n\n";
    Node *list3 = NULL;
    list3 = copyList(list1);

    cout << "List 3: ";
    printList(list3);
    cout << endl << endl;

    cout << "Deleting List 1...";
    deleteList(list1);      // Deletes the whole list
    cout << endl << endl;

    cout << "List 1: ";
    printList(list1);
    cout << endl;
    cout << "List 3: ";
    printList(list3);
    cout << endl;
}
