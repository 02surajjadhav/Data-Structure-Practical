#include <iostream>
#include <string>
using namespace std;

#define MAX 100

// Queue Using Array
class ArrayQueue {
    string q[MAX];
    int front, rear;

public:
    ArrayQueue() {
        front = rear = -1;
    }

    void enqueue(string request) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow!\n";
            return;
        }

        if (front == -1)
            front = 0;

        q[++rear] = request;
        cout << "Reservation added successfully.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow!\n";
            return;
        }

        cout << "Processed Request: "
             << q[front++] << endl;

        if (front > rear)
            front = rear = -1;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Pending Reservations:\n";
        for (int i = front; i <= rear; i++)
            cout << q[i] << endl;
    }
};

// Queue Using Linked List
struct Node {
    string request;
    Node* next;

    Node(string r) {
        request = r;
        next = NULL;
    }
};

class LinkedQueue {
    Node *front, *rear;

public:
    LinkedQueue() {
        front = rear = NULL;
    }

    void enqueue(string request) {
        Node* newNode = new Node(request);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Reservation added successfully.\n";
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow!\n";
            return;
        }

        Node* temp = front;

        cout << "Processed Request: "
             << temp->request << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Pending Reservations:\n";
        Node* temp = front;

        while (temp != NULL) {
            cout << temp->request << endl;
            temp = temp->next;
        }
    }

    ~LinkedQueue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    ArrayQueue aq;
    LinkedQueue lq;

    int choice, type;
    string request;

    do {
        cout << "\n--- Ticket Reservation System ---\n";
        cout << "1. Queue Using Array\n";
        cout << "2. Queue Using Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            do {
                cout << "\n1. Enqueue Reservation\n";
                cout << "2. Dequeue Reservation\n";
                cout << "3. Display Reservations\n";
                cout << "4. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> type;
                cin.ignore(10000, '\n');

                switch (type) {
                    case 1:
                        cout << "Enter reservation details: ";
                        getline(cin, request);

                        if (choice == 1)
                            aq.enqueue(request);
                        else
                            lq.enqueue(request);
                        break;

                    case 2:
                        if (choice == 1)
                            aq.dequeue();
                        else
                            lq.dequeue();
                        break;

                    case 3:
                        if (choice == 1)
                            aq.display();
                        else
                            lq.display();
                        break;

                    case 4:
                        break;

                    default:
                        cout << "Invalid choice!\n";
                }

            } while (type != 4);
        }
        else if (choice == 3) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
