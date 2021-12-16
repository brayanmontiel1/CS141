#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
using namespace std;

/*
 * References:
 * https://www.geeksforgeeks.org/sort-algorithms-the-c-standard-template-library-stl/
 * https://www.cplusplus.com/
 * https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
 * https://www.dropbox.com/sh/sbswo94twlek3s2/AABZlrFyq8yjGIvVAwILqPiia/slides/uer.pdf&subfolder_nav_tracking=1
 */

int max(int a, int b){ //returns max of a and b
    if(a > b)
        return a;
    else
        return b;
}

int kp(int weight, int n, int wt[], int val[]) { //passing in max weight,amount n, weight, and values

    vector<vector<int>> arr(n + 1, vector<int>(weight + 1)); //will be returning sol
    for(int i = 0; i <= n; i++) // Build table arr[][]
    {
        for(int k = 0; k <= weight; k++)
        {
            if (i == 0 || k == 0)
                arr[i][k] = 0;
            else if (wt[i - 1] <= k)
                arr[i][k] = max(val[i - 1] + arr[i - 1][k - wt[i - 1]],arr[i - 1][k]); //returns max val of [prev row at i-1 ]vs value of prev row i left over values k]
            else
                arr[i][k] = arr[i - 1][k];
        }
    }
    return arr[n][weight];
}


int main() {
    int weight, n = 0;
    cin >> weight; //weight budget
    cin >> n; //entry number
    int input;
    int wt[n]; // weight
    int val[n]; // value

    //get values
    for (int i =0; i<n; i++)
    {
            cin >> input;
            wt[i] = input;
            cin >> input;
            val[i] = input ;
    }

    cout << kp(weight, n, wt, val) ;
    return 0;
}






//------------A. merge the candies------------------------------------------------------------------------
/*

int main() {
    int n, count = 0;
    cin >> n; //amount of entries
    vector<int> arr;
    int input;
    for (int i = 0; i < n; i++){//candies
        cin >> input;
        arr.push_back(input);
    }



    int sum = 0;
    while(n>1){
        sort(arr.begin(), arr.end()); //always sort to make sure smallest two bags are first in array
        count = 0;
        int num1 = arr.at(0);
        count += num1; //count first bag
        int num2 = arr.at(1);
        count += num2; //count second bag
        arr.at(1) = count;
        arr.erase(arr.begin()); //erase first in vector
        count += (num1 + num2); //merging 1st and second bag
        sum += count;
        n--; //resize
    }
    cout << sum ;
    return 0;
}
------------B. ------------------------------------------------------------------------
 *
 */