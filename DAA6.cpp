#include <iostream>
using namespace std;

int* countSort(int* arr, int n) {
    int m = arr[0];
    for(int i=1; i<n; i++) if(arr[i]>m) m=arr[i];
    int* count = new int[m+1]();
    for(int i=0; i<n; i++) count[arr[i]]++;
    for(int i=1; i<=m; i++) count[i]+=count[i-1];
    int* output = new int[n];
    for(int i=n-1; i>=0; i--) output[--count[arr[i]]]=arr[i];
    delete[] count;
    return output;
}
int main() {
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int* arr=new int[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    int* sorted=countSort(arr,n);
    cout<<"Sorted: ";
    for(int i=0;i<n;i++) cout<<sorted[i]<<" ";
    delete[] arr;
    delete[] sorted;
    return 0;
}
