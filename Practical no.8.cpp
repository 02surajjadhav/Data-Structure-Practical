#include <iostream>
using namespace std;
struct Book {
    int id;
    string title;
};
void linearSearch(Book books[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (books[i].id == key) {
            cout << "Book Found using Linear Search!\n";
            cout << "Book ID: " << books[i].id << endl;
            cout << "Book Title: " << books[i].title << endl;
            return;
        }
    }
    cout << "Book not found using Linear Search.\n";
}
void binarySearch(Book books[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (books[mid].id == key) {
            cout << "Book Found using Binary Search!\n";
            cout << "Book ID: " << books[mid].id << endl;
            cout << "Book Title: " << books[mid].title << endl;
            return;
        }
        else if (books[mid].id < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << "Book not found using Binary Search.\n";
}
int main() {
    Book books[] = {
        {101, "C Programming"},
        {102, "Data Structures"},
        {103, "Computer Networks"},
        {104, "Operating Systems"},
        {105, "Database Management"}
    };
    int n = 5, choice, key;
    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Display All Books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter Book ID to search: ";
                cin >> key;
                linearSearch(books, n, key);
                break;
            case 2:
                cout << "Enter Book ID to search: ";
                cin >> key;
                binarySearch(books, n, key);
                break;
            case 3:
                cout << "\nBook ID\tBook Title\n";
                for (int i = 0; i < n; i++) {
                    cout << books[i].id << "\t"
                         << books[i].title << endl;
                }
                break;
            case 4:
                cout << "Exiting Library Management System.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    return 0;
}
