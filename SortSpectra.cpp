#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string RESET = "\033[0m";

const int SLEEP_DURATION_MS = 500;


void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void visualizeArray(const vector<int>& arr) {
    cout << RED << "Sorting, please wait!!!" << RESET << endl;
    for (int num : arr) {
        cout << GREEN << string(num, '#') << " " << RESET;
    }
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(SLEEP_DURATION_MS));
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                visualizeArray(arr);
            }
        }
        if (!swapped)
            break;
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
    visualizeArray(arr);
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        visualizeArray(arr);
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
        visualizeArray(arr);
    }
}
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        visualizeArray(arr);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void getUserInput(vector<int>& arr) {
    cout << GREEN << "Welcome to Sorting Spectra!!" << RESET << endl;
    int size;
    cout << "Please enter the number of elements: ";
    cin >> size;
    arr.resize(size);

    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}
void runSortAlgorithm(vector<int>& arr) {
    while (true) {
        int choice;
        vector<int> tempArr = arr;
    
        cout << "\n" << YELLOW << "Choose Sorting Algorithm:" << RESET << endl;
        cout << "-------------------------------------------------------\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Selection Sort\n";
        cout << "4. Insertion Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Heap Sort\n";
        cout << "7. Counting Sort\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
    
        switch (choice) {
            case 1:
                bubbleSort(tempArr);
                break;
            case 2:
                mergeSort(tempArr, 0, tempArr.size() - 1);
                break;
            case 3:
                selectionSort(tempArr);
                break;
            case 4:
                insertionSort(tempArr);
                break;
            case 5:
                quickSort(tempArr, 0, tempArr.size() - 1);
                break;
            case 6:
                heapSort(tempArr);
                break;
            case 7:
                countingSort(tempArr);
                break;
            case 0:
                cout << GREEN << "Thank you for visiting!" << RESET << endl;
                return;
            default:
                cout << RED << "Invalid choice! Please try again." << RESET << endl;
                continue;
        }
    
        cout << BLUE << "Sorted Array: " << RESET;
        printArray(tempArr);
    
        char cont;
        cout << "Do you want to sort another array? (y/n): ";
        cin >> cont;
        if (cont == 'n' || cont == 'N') {
            cout << GREEN << "Thank you for visiting!" << RESET << endl;
            return;
        }
        getUserInput(arr);
    }
}


int main() {
    vector<int> arr;
    getUserInput(arr);

    cout << BLUE << "Original Array: " << RESET;
    printArray(arr);

    runSortAlgorithm(arr);

    return 0;
}
