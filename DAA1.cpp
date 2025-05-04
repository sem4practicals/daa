#include<iostream>
using namespace std;
int comp=0;
int insort(int arr[], int n){
	for(int i=1;i<n;i++){
		int key=arr[i];
		int j=i-1;
		while(j>0 and arr[j]>key){
			comp++;
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
void disp(int arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n=5;
	int arr[5]={3,1,5,8,2};
	disp(arr,n);
	insort(arr,n);
	disp(arr,n);
}
