#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int key;
    cout<<"Enter key: ";
    cin>>key;
    int left = 0;
    int right = n-1;

    while (left <= right){
        int m = left+(right - left)/2;

        if (arr[m] == key){
            cout<<"Element found at index: "<<m<<endl;
            return 0;
        }
        else if (arr[m] > key){
            right = m-1;
        }
        else{
            left = m+1;
        }
    }
    return 0;
}