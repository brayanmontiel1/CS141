#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

/*
 * References:
 * https://www.geeksforgeeks.org/sort-algorithms-the-c-standard-template-library-stl/
 * https://www.cplusplus.com/
 * https://www.dropbox.com/sh/sbswo94twlek3s2/AABZlrFyq8yjGIvVAwILqPiia/slides/uer.pdf&subfolder_nav_tracking=1
 */


int main() {
    int n, count = 0;
    cin >> n; //amount of departments
    int arr[n];
    for (int i = 0; i < n; i++)  //get faculty votes per department
        cin >> arr[i];

    int asize = sizeof(arr) / sizeof(arr[0]);

    // sort the array
    sort(arr, arr + asize);
    //perhaps faster way is to start from lowest amount of votes needed departments/2 +1
    int mid = (n/2)+1;

    for(int i=0; i<mid;i++){
        int votes = arr[i]; //votes at i
        count+=(votes/2)+1;
    }

    //print votes
    cout << count ;
    return 0;
}






//------------Exercise 1------------------------------------------------------------------------
/*
//helper method
void mergeSort(int *arr, int left, int mid, int right, int &counter) {
    int sizeLeft = mid-left+1;
    int sizeRight = right-mid;
    int lefty[sizeLeft];
    int righty[sizeRight];

    //add the right/left array values
    for(int j = 0; j < sizeRight; j++)
        righty[j] = arr[mid+1+j];

    for(int i = 0; i < sizeLeft; i++)
        lefty[i] = arr[left+i];

    //start to merge
    int l = 0, r = 0, k = left;
    while(l < sizeLeft && r < sizeRight) {
        if(lefty[l] >= righty[r]) {
            arr[k] = lefty[l];
            l++;
        }else{
            arr[k] = righty[r];
            r++;
        }
        k++;
    }
    //add rest of array
    while(r<sizeRight) {
        arr[k] = righty[r];
        r++;
        k++;
    }

    while(l<sizeLeft) {
        arr[k] = lefty[l];
        l++;
        k++;
    }
    //update candies/counter (running count)
    counter = arr[left] - arr[right] + counter;
}

void merge(int *arr, int beg, int end, int &counter) { //pass counter as a reference to count
    if (beg < end) {
        int mid = beg + (end - beg) / 2;
        merge(arr, beg, mid, counter); //first half
        merge(arr, mid + 1, end, counter); //second half
        mergeSort(arr, beg, mid, end, counter); //helper method
    }
}

int main() {
   int count = 0; //amount of candies
   int n;
   cin >> n; //amount of student scores
   int arr[n];
   for (int i = 0; i < n; i++)  //get scores
        cin >> arr[i];

   merge(arr, 0, n - 1, count); //call operation
   cout << count << endl;
   return 0;
}
 */