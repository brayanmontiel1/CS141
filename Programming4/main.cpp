#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
using namespace std;

/*
 * References:
 * https://www.geeksforgeeks.org/sort-algorithms-the-c-standard-template-library-stl/
 * https://www.cplusplus.com/
 * https://www.dropbox.com/sh/sbswo94twlek3s2/AABZlrFyq8yjGIvVAwILqPiia/slides/uer.pdf&subfolder_nav_tracking=1
 */

int LUS(vector<int> const &arr1) { //returns max of a and b
    int count = 1;      //will be overwritten
    vector<int> arr2(arr1.size());       //for lis
    vector<int> arr3(arr1.size());       //for lds
    arr2[0] =1;             //init arr2
    arr3[arr1.size()-1] = 1; //init arr3

    //have to do two passes going, getting longest increasing sub and longest decreasing sub to add together
    //LIS
    for (int i = 1; i < arr1.size(); i++){
        for (int j = 0; j < i; j++) {
            if (arr2[i] < arr2[j] && arr1[i] > arr1[j])   //if current position is greater add
                arr2[i] = arr2[j];           //update pos i
        }
        arr2[i]+=1;
    }

    //LDS
    for (int i = arr1.size()-2; i >= 0; i--){
        for (int j = arr1.size()-1; j > i ; j--) {
            if (arr3[i] < arr3[j] && arr1[i] > arr1[j])   //if current position is less than add
                arr3[i] = arr3[j];           //update pos i
        }
        arr3[i] +=1;
    }

    //get the maximum of both LDS + LIS
    for (int i = 0; i < arr1.size(); i++){   //find the maximum of arr[2]arr[3]
        count = max(count,(arr2[i] + arr3[i]));
    }
    // returns the length of the LUS
    return count-1;
}


int main() {
    int n = 0;
    cin >> n; //entry number
    int input;
    vector<int> arr1; // numbers inputed by program

    //get values
    for (int i =0; i<n; i++)
    {
        cin >> input;
        arr1.push_back(input);
    }

    cout << LUS(arr1);
    return 0;
}






//------------A. merge the candies------------------------------------------------------------------------
/*
int LDS(vector<int> const &arr1) { //returns max of a and b
    int count = INT_MIN;    //will be overwritten
    vector<int> arr2(arr1.size());       //will hold our subsequent value counts for each pos. at arr
    arr2[0] = 1; //initialize first to 1 for init comparison

    //go through array and compare how i compares curr position compares to rest of the array.
    for (int i = 1; i < arr1.size(); i++){
        for (int j = 0; j < i; j++) {
            if (arr1[i] < arr1[j] && arr2[i] < arr2[j])   //if current position is smaller then swap
                arr2[i] = arr2[j];
        }
        arr2[i] +=1;     //increase by one
    }

    for (int i = 0; i < arr2.size(); i++){   //find the maximum of arr
        count = max(count,arr2.at(i));
    }
    // returns the length of the LDS
    return count;
}


int main() {
    int n = 0;
    cin >> n; //entry number
    int input;
    vector<int> arr1; // numbers inputed by program

    //get values
    for (int i =0; i<n; i++)
    {
        cin >> input;
        arr1.push_back(input);
    }

    cout << LDS(arr1);
    return 0;
}

------------B. ------------------------------------------------------------------------
 int LUS(vector<int> const &arr1) { //returns max of a and b
    int count;    //will be overwritten
    vector<int> arr2(arr1.size());       //for lis
    vector<int> arr3(arr1.size());       //for lds

    //init arr2 for longest increasing sub
    for (int i = 1; i < arr1.size(); i++){
        arr2[i] = 1;
        arr3[i] = 1;
    }


    //have to do two passes going, getting longest increasing sub and longest decreasing sub to add together
    //LIS
    for (int i = 1; i < arr1.size(); i++){
        for (int j = 0; j < i; j++) {
            if (arr2[i] < arr2[j]+1 && arr1[i] > arr1[j])   //if current position is greater add
                arr2[i] = arr2[j] +1;           //update pos i
        }
    }

    //LDS
    for (int i = arr1.size()-2; i >= 0; i--){
        for (int j = arr1.size()-1; j > 1 ; j--) {
            if (arr3[i] < arr3[j]+1 && arr1[i] > arr1[j])   //if current position is less than add
                arr3[i] = arr3[j] +1;           //update pos i
        }
    }

    count = arr2[0] + arr3[0] -1;;    //will be overwritten

    for (int i = 1; i < arr1.size(); i++){   //find the maximum of arr
        count = max(count,(arr2[i] + arr3[i] -1));
    }
    // returns the length of the LDS
    return count;
}


int main() {
    int n = 0;
    cin >> n; //entry number
    int input;
    vector<int> arr1; // numbers inputed by program

    //get values
    for (int i =0; i<n; i++)
    {
        cin >> input;
        arr1.push_back(input);
    }

    cout << LUS(arr1);
    return 0;
}
 */