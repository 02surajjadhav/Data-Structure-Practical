#include <iostream>
using namespace std;
void merge(int arr[], int low, int mid, int high, int order) {
    int temp[100];
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if ((order == 1 && arr[i] <= arr[j]) ||
            (order == 2 && arr[i] >= arr[j])) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];
    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}
void mergeSort(int arr[], int low, int high, int order) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid, order);
        mergeSort(arr, mid + 1, high, order);
        merge(arr, low, mid, high, order);
    }
}
int partition(int arr[], int low, int high, int order) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if ((order == 1 && arr[j] <= pivot) ||
            (order == 2 && arr[j] >= pivot)) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
void quickSort(int arr[], int low, int high, int order) {
    if (low < high) {
        int p = partition(arr, low, high, order);
        quickSort(arr, low, p - 1, order);
        quickSort(arr, p + 1, high, order);
    }
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int salary[100], temp[100];
    int n, choice, order;
    cout << "Enter number of employees: ";
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Invalid number of employees.\n";
        return 0;
    }
    cout << "Enter employee salaries:\n";
    for (int i = 0; i < n; i++)
        cin >> salary[i];
    do {
        cout << "\n--- Employee Salary Sorting ---\n";
        cout << "1. Merge Sort\n";
        cout << "2. Quick Sort\n";
        cout << "3. Display Original Salaries\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
            case 2:
                cout << "1. Ascending Order\n";
                cout << "2. Descending Order\n";
                cout << "Enter order: ";
                cin >> order;
                if (order != 1 && order != 2) {
                    cout << "Invalid order!\n";
                    break;
                }
                for (int i = 0; i < n; i++)
                    temp[i] = salary[i];
                if (choice == 1)
                    mergeSort(temp, 0, n - 1, order);
                else
                    quickSort(temp, 0, n - 1, order);
                cout << "Sorted Salaries: ";
                display(temp, n);
                break;
            case 3:
                cout << "Original Salaries: ";
                display(salary, n);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    return 0;
}
