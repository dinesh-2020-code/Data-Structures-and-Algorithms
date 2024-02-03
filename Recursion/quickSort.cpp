/**
 * 
 *  Quick Sort -> Divide and conquer algorithm
*/

#include <iostream>
using namespace std; 


void print(int arr[], int n) {
    //This function prints the array elements
    for (int i = 0; i < n; i++)
        cout << arr[i] << " "; 
    cout << endl; 
}


int findPartition(int arr[], int low, int high) {
    //partition function which determines the correct position of the pivot element. 
    // here pivot element will be selected as last element of array i.e., arr[high]

    int pivot = high;
    int i = low - 1; // this index determines that till index 'i' element is less than or equal to pivot element 
    int j = low;

    while (j < high) {
        if (arr[j] < arr[pivot]) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i + 1], arr[pivot]); // positioning the pivot element at current position
    return i + 1;

}

void quickSort(int arr[], int low, int high) {

    //base case  is if low >= high then stop

    if (low < high) {

        int pi = findPartition(arr, low, high);  // partition index which denotes the correct position of the pivot element.
        quickSort(arr, low, pi - 1);  // recursively find the pivot in left half 
        quickSort(arr, pi + 1, high); // recursively find the pivot in right half
    }
}

int main() 
{
    int arr[]={10,7,8,9,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    print(arr, n);
    return 0; 
}