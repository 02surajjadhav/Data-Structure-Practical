#include <iostream>
using namespace std;
void bubbleSort(int a[], int n, int order) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((order == 1 && a[j] > a[j + 1]) ||
                (order == 2 && a[j] < a[j + 1])) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int a[], int n, int order) {
    for (int i = 0; i < n - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if ((order == 1 && a[j] < a[pos]) ||
                (order == 2 && a[j] > a[pos])) {
                pos = j;
            }
        }
        int temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;
    }
}
void insertionSort(int a[], int n, int order) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 &&
              ((order == 1 && a[j] > key) ||
               (order == 2 && a[j] < key))) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main() {
    int marks[100], n, choice, order;
    cout << "Enter number of students: ";
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Invalid number of students.\n";
        return 0;
    }
    cout << "Enter student marks:\n";
    for (int i = 0; i < n; i++)
        cin >> marks[i];
    do {
        cout << "\n--- Student Marks Sorting ---\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice >= 1 && choice <= 3) {
            int sorted[100];
            for (int i = 0; i < n; i++)
                sorted[i] = marks[i];
            cout << "1. Ascending Order\n";
            cout << "2. Descending Order\n";
            cout << "Enter order: ";
            cin >> order;
            if (order != 1 && order != 2) {
                cout << "Invalid order!\n";
                continue;
            }
            switch (choice) {
                case 1:
                    bubbleSort(sorted, n, order);
                    break;
                case 2:
                    selectionSort(sorted, n, order);
                    break;
                case 3:
                    insertionSort(sorted, n, order);
                    break;
            }
            cout << "Sorted Marks: ";
            display(sorted, n);
        }
        else if (choice == 4) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    return 0;
}
