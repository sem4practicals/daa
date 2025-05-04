#include <iostream>
using namespace std;

int comps = 0;

void heapify(int arr[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = l+1;
    if (l < n) { comps++; if (arr[l] > arr[largest]) largest = l; }
    if (r < n) { comps++; if (arr[r] > arr[largest]) largest = r; }
    if (largest != i) {swap(arr[i], arr[largest]); heapify(arr, n, largest);}
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {swap(arr[0], arr[i]); heapify(arr, i, 0);}
}

int main(){
    int n; cout << "Enter number of elements: "; cin >> n;
    int arr[n]; cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    heapSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\nTotal comparisons: " << comps;
    return 0;
}
