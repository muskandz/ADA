#include <iostream>
using namespace std;

int binarySeach(int a[], int l, int r, int k){
    if (l<=r){
        int mid = l+(r-l)/2;
        if (a[mid]==k){
            return mid;
        }
        else if (a[mid]>k){
            return binarySeach(a, l, mid-1, k);
        }
        else{
            return binarySeach(a, mid+1, r, k);
        }
    }
        return -1;
}

int main(){
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter key to search in the array: ";
    cin>>key;
    int result = binarySeach(arr, 0, n-1, key);
    if (result==-1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at index "<<result;
    }
    return 0;
}