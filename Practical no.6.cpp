#include <iostream>
#include <string>
#include <limits>
using namespace std;
#define MAX 100
string arrayQueue[MAX];
int frontA = -1;
int rearA = -1;
int countA = 0;
void enqueueArray()
{
    if (countA == MAX)
    {
        cout << "\nQueue Overflow! Array queue is full.\n";
        return;
    }
    string request;
    cout << "Enter ticket reservation request: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, request);
    if (countA == 0)
    {
        frontA = 0;
        rearA = 0;
    }
    else
    {
        rearA = (rearA + 1) % MAX;
    }
    arrayQueue[rearA] = request;
    countA++;
    cout << "Request added successfully.\n";
}
void dequeueArray()
{
    if (countA == 0)
    {
        cout << "\nQueue Underflow! No requests to process.\n";
        return;
    }
    cout << "\nProcessed Request: "
         << arrayQueue[frontA] << endl;
    frontA = (frontA + 1) % MAX;
    countA--;
    if (countA == 0)
    {
        frontA = -1;
        rearA = -1;
    }
}
void displayArray()
{
    if (countA == 0)
    {
        cout << "\nQueue is empty.\n";
        return;
    }
    cout << "\nTicket Reservation Requests (Array Queue):\n";
    int index = frontA;
    for (int i = 0; i < countA; i++)
    {
        cout << i + 1 << ". "
             << arrayQueue[index] << endl;

        index = (index + 1) % MAX;
    }
}
struct Node
{
    string request;
    Node* next;
};
Node* frontL = NULL;
Node* rearL = NULL;
void enqueueLinkedList()
{
    string request;
    cout << "Enter ticket reservation request: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, request);
    Node* newNode = new Node;
    newNode->request = request;
    newNode->next = NULL;
    if (rearL == NULL)
    {
        frontL = newNode;
        rearL = newNode;
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
    if (frontL == NULL)
    {
        cout << "\nQueue Underflow! No requests to process.\n";
        return;
    }
    Node* temp = frontL
    cout << "\nProcessed Request: "
         << temp->request << endl;
    frontL = frontL->next;
    if (frontL == NULL)
    {
        rearL = NULL;
    }
    delete temp;
}
void displayLinkedList()
{
    if (frontL == NULL)
    {
        cout << "\nQueue is empty.\n";
        return;
    }
    cout << "\nTicket Reservation Requests (Linked List Queue):\n";
    Node* temp = frontL;
    int i = 1;
    while (temp != NULL)
    {
        cout << i << ". "
             << temp->request << endl;
        temp = temp->next;
        i++;
    }
}
int main()
{
    int choice;
    int operation;
    while (true)
    {
        cout << "\n===============================================\n";
        cout << "       TICKET RESERVATION QUEUE SYSTEM\n";
        cout << "===============================================\n";
        cout << "1. Queue Using Array\n";
        cout << "2. Queue Using Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nInvalid input! Please enter a number.\n";
            continue;
        }
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
            cout << "\n-----------------------------------------------\n";
            cout << "              QUEUE OPERATIONS\n";
            cout << "-----------------------------------------------\n";
            cout << "1. Enqueue Request\n";
            cout << "2. Dequeue Request\n";
            cout << "3. Display Requests\n";
            cout << "4. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> operation;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input! Please enter a number.\n";
                continue;
            }
            if (operation == 4)
            {
                break;
            }
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
    while (frontL != NULL)
    {
        Node* temp = frontL;
        frontL = frontL->next;
        delete temp;
    }
    rearL = NULL;
    return 0;
}
