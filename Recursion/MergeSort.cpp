/**
 * Merge Sort
 * 
 * Time: O(N log N)
 * Space aux : O(N)
 * 
*/

#include <iostream>
using namespace std; 

void print(int arr[], int n) {

    for (int i = 0; i < n; i++)
        cout << arr[i] << " "; 
    cout << endl; 
}

void merge(int arr[], int low, int mid, int high) {
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp[100]; //for merging
    int i = low, j = mid + 1, k = 0; 

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i]; 
            i++;
        }
        else {
            temp[k] = arr[j]; 
            j++;
        }
        k++;
    }

    //if elements in the left array left
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    //if elements in the right array left
    while (j <= high) {
        temp[k++] = arr[j++];
    }

    //copy temp to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i-low]; 
    }
}

void mergeSort(int arr[], int low, int high) {

    //Base case
    if (high == low) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}
int main() 
{

    int n = 9; 
    int arr[] = {3, 1, 2, 4, 1, 5, 2, 6, 4};
    mergeSort(arr, 0,n-1);
    print(arr, n);
    return 0;
}