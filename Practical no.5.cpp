#include <iostream>
#include <string>
using namespace std;
#define MAX 10
string stack[MAX];
int top = -1;
void push(string page)
{
    if (top == MAX - 1)
    {
        cout << "History Full!" << endl;
    }
    else
    {
        top++;
        stack[top] = page;
        cout << "Visited: " << page << endl;
    }
}
void pop()
{
    if (top == -1)
    {
        cout << "No previous page!" << endl;
    }
    else
    {
        cout << "Back from: " << stack[top] << endl;
        top--;
        if (top >= 0)
            cout << "Current page: " << stack[top] << endl;
    }
}
void peek()
{
    if (top == -1)
    {
        cout << "History Empty!" << endl;
    }
    else
    {
        cout << "Current page: " << stack[top] << endl;
    }
}
void display()
{
    if (top == -1)
    {
        cout << "History Empty!" << endl;
    }
    else
    {
        cout << "Browser History:" << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
}
int main()
{
    int choice;
    string page;
    do
    {
        cout << "\n1. Visit Page";
        cout << "\n2. Back";
        cout << "\n3. Current Page";
        cout << "\n4. Display History";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter webpage: ";
                cin >> page;
                push(page);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
    return 0;
}
