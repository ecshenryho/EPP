// Data Structures Solutions for ACM EPP Review
// Contact Oscar Olazabal at omolazabal@csu.fullerton.edu if you have any
// questions or concerns.

#include <iostream>
#include <string>
#include "queue.h"
#include "binary_search_tree.h"
#include "customer.h"

using namespace std;

void Menu();      // Menu that displays options.
void CheckIn();   // Check in a customer.
void CheckOut();  // Remove customer from list.
void Search();
void Quit();

Queue<Customer> customer_queue;
BinarySearchTree<Customer> history_tree;

int main() {
    bool loop = true;
    int selection;

    do {
        Menu();
        cout << "Input: ";
        cin >> selection;
        cin.ignore();

        switch (selection)
        {
        case 1:
            cout << endl;
            CheckIn();
            cout << endl;
            break;
        case 2:
            cout << endl;
            CheckOut();
            cout << endl;
            break;
        case 3:
            cout << endl;
            Search();
            cout << endl;
            break;
        case 4:
            cout << endl;
            Quit();
            loop = false;
            cout << "Exiting program...\n";
            break;
        default:
            break;
        }

    } while (loop);
}

void Menu() {
    cout << "1) Check in\n";
    cout << "2) Check out\n";
    cout << "3) Search\n";
    cout << "4) Quit\n";
}

void CheckIn() {
    string name;
    string plate;
    bool premium_wash;
    char yn;

    // User inputs data for the Customer object: Name, License Plate, and if they
    // they want a premium wash or not.
    cout << "Name: ";
    getline(cin, name);
    cout << "License Plate: ";
    cin >> plate;
    cout << "Premium Wash? (y/n): ";
    cin >> yn;

    if (yn == 'y')
        premium_wash = true;
    else
        premium_wash = false;

    // Create customer and put into queue.
    Customer customer(name, plate, premium_wash);
    if (customer_queue.enqueue(customer))
        cout << "Customer checked in\n";
    else
        cout << "Customer not checked in\n";
}

void CheckOut() {
    // Get customer at the front.
    Customer customer;
    customer_queue.get_front(customer);

    // Insert the customer at the front into the tree and dequeue.
    if (history_tree.insert(customer)) {
        if (customer_queue.dequeue())
            cout << customer.get_name() << " checked out.\n";
        else
            cout << "Customer not checked out.\n";
    }
}

void Search() {
    // Create a temporary customer with the name to search for.
    string name;
    cout << "Name: ";
    getline(cin, name);
    cout << endl;
    Customer customer_name;
    customer_name.set_name(name);

    // Retreive the customer.
    Customer retrieved_customer;
    if (history_tree.retrieve(customer_name, retrieved_customer))
        cout << retrieved_customer << endl;
    else
        cout << "Customer not found.\n";

}

void Quit() {
    // Remove customers until queue is empty.
    Customer customer;
    while (!customer_queue.is_empty()) {
        customer_queue.get_front(customer);
        cout << "Checking out " << customer.get_name() << endl;
        customer_queue.dequeue();
    }

    // Remove all customers from tree.
    history_tree.remove_all();
}
