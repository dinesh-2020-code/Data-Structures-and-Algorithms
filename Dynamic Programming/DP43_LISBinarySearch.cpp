/**
 * 
 * Longest Increasing Subsequence using Binary Search
 * Time Complexity of Previous Solutions: O(N * N), Aux space: O (N)
 * if N <= 10^5, the previous solution was giving TLE. 
 * 
 * Intuition: 
 * arr = {1, 7, 8, 4, 5, 6, -1, 9}
 * Output: 5 {1, 4, 5, 6, 9}
 * 
 * arr = {1, 4, 5, 4, 2, 8}
 * Output: 4 {1, 4, 5, 8}
 * 
 * We will traverse the array and try to form subsequences as follows:
 * arr = {1, 7, 8, 4, 5, 6, -1, 9}
 * sub1= {1, 7, 8, 9} len 4
 * sub2= {1, 4, 5, 6, 9}  len 5
 * sub3= {-1, 9}  len 2
 * 
 * We won't be generating subsequences as we are reqd to return length of LIS.
 * We will rewrite the element at single array itself.
 * arr1 = {1, 7, 8}
 * arr1 = {1, 4, 8}  ==> after '4' came
 * arr1 = {1, 4, 5}  ==> after '5' came
 * arr1 = {1, 4, 5, 6} => after '6' came
 * arr1 = {-1, 4, 5, 6} => after '-1' came
 * arr1 = {-1, 4, 5, 6, 9} => after '9' came
 * At the end return the length of the final arr1 (arr1 is not an LIS)
 * we are overriding current element in the same array with the 
 * element right after the element greater than curr_element
 * 
 * We will find the pos using binary search (lower_bound method in c++)
 * lower_bound(x): Returns the iterator to the element that is >= x.
 * 
 * 
*/

#include <iostream>
#include <vector>

using namespace std;


int lengthOfLIS(vector<int> &arr) {
    /**
     * This functions find the length of the Longest Increasing Subsequence
     * @param: arr contains the elements
     * Returns: an integer, the length of the Longest Increasing Subsequence
    */
    int n = arr.size();
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > temp.back()) {
            temp.push_back(arr[i]);
            len++;
        }
        else {
            //perform binary search
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];

        }
    }
    return len;
    /**
     * Time Complexity: O(N log N)
     * Aux Space: O(N)
    */
}


int main() {

    vector<int> arr = {1, 7, 8, 4, 5, 6, -1, 9};
    cout << "Length of LIS is: " << lengthOfLIS(arr) << endl;
    return 0;
}
