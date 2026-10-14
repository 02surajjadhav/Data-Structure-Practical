#include <iostream>
#include <string>
using namespace std;
#define MAX 5
string queue[MAX];
int front = -1, rear = -1;
void enqueue(string request) {
    if ((rear + 1) % MAX == front) {
        cout << "Queue Overflow! Queue is full.\n";
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = request;
    cout << "Request added successfully.\n";
}
void dequeue() {
    if (front == -1) {
        cout << "Queue Underflow! No pending requests.\n";
        return;
    }
    cout << "Processed Request: " << queue[front] << endl;
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}
void display() {
    if (front == -1) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "\nPending Customer Requests:\n";
    int i = front;
    while (true) {
        cout << queue[i] << endl;
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}
int main() {
    int choice;
    string request;
    do {
        cout << "\n--- Call Center Request System ---\n";
        cout << "1. Add Customer Request (Enqueue)\n";
        cout << "2. Process Customer Request (Dequeue)\n";
        cout << "3. Display Pending Requests\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(10000, '\n');
        switch (choice) {
            case 1:
                cout << "Enter customer request: ";
                getline(cin, request);
                enqueue(request);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting Call Center System.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
    return 0;
}
