#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define MAX 100
string arrayQueue[MAX];
int frontA = -1, rearA = -1;
void enqueueArray()
{
    string request;
    if (rearA == MAX - 1)
    {
        cout << "\nQueue Overflow!\n";
        return;
    }
    cout << "Enter ticket reservation request: ";
    cin.ignore();
    getline(cin, request);
    if (frontA == -1)
        frontA = 0;
    rearA++;
    arrayQueue[rearA] = request;
    cout << "Request added successfully.\n";
}
void dequeueArray()
{
    if (frontA == -1 || frontA > rearA)
    {
        cout << "\nQueue Underflow! No requests to process.\n";
        return;
    }
    cout << "\nProcessed Request: " << arrayQueue[frontA] << endl;
    frontA++;
    if (frontA > rearA)
    {
        frontA = -1;
        rearA = -1;
    }
}
void displayArray()
{
    if (frontA == -1 || frontA > rearA)
    {
        cout << "\nQueue is empty.\n";
        return;
    }
    cout << "\nTicket Reservation Requests (Array Queue):\n";
    for (int i = frontA; i <= rearA; i++)
    {
        cout << i - frontA + 1 << ". "
             << arrayQueue[i] << endl;
    }
}
struct Node
{
    string request;
    Node *next;
};
Node *frontL = nullptr;
Node *rearL = nullptr;
void enqueueLinkedList()
{
    string request;
    Node *newNode = new Node;
    cout << "Enter ticket reservation request: ";
    cin.ignore();
    getline(cin, request);
    newNode->request = request;
    newNode->next = nullptr;
    if (rearL == nullptr)
    {
        frontL = rearL = newNode;
    }
    else
    {
        rearL->next = newNode;
        rearL = newNode;
    }
    cout << "Request added successfully.\n";
}
void dequeueLinkedList()
{
    if (frontL == nullptr)
    {
        cout << "\nQueue Underflow! No requests to process.\n";
        return;
    }
    Node *temp = frontL;
    cout << "\nProcessed Request: "
         << temp->request << endl;
    frontL = frontL->next;
    if (frontL == nullptr)
        rearL = nullptr;
    delete temp;
}
void displayLinkedList()
{
    if (frontL == nullptr)
    {
        cout << "\nQueue is empty.\n";
        return;
    }
    cout << "\nTicket Reservation Requests (Linked List Queue):\n";
    Node *temp = frontL;
    int i = 1;
    while (temp != nullptr)
    {
        cout << i << ". " << temp->request << endl;
        temp = temp->next;
        i++;
    }
}
int main()
{
    int choice, operation;
    while (true)
    {
        cout << "\n========== TICKET RESERVATION QUEUE ==========\n";
        cout << "1. Queue Using Array\n";
        cout << "2. Queue Using Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 3)
        {
            cout << "\nProgram terminated.\n";
            break;
        }
        if (choice != 1 && choice != 2)
        {
            cout << "\nInvalid choice! Try again.\n";
            continue;
        }
        while (true)
        {
            cout << "\n---------- Operations ----------\n";
            cout << "1. Enqueue Request\n";
            cout << "2. Dequeue Request\n";
            cout << "3. Display Requests\n";
            cout << "4. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> operation;
            if (operation == 4)
                break;
            if (choice == 1)
            {
                switch (operation)
                {
                    case 1:
                        enqueueArray();
                        break;
                    case 2:
                        dequeueArray();
                        break;
                    case 3:
                        displayArray();
                        break;
                    default:
                        cout << "\nInvalid operation!\n";
                }
            }
            else
            {
                switch (operation)
                {
                    case 1:
                        enqueueLinkedList();
                        break;
                    case 2:
                        dequeueLinkedList();
                        break;
                    case 3:
                        displayLinkedList();
                        break;
                    default:
                        cout << "\nInvalid operation!\n";
                }
            }
        }
    }
    return 0;
}
