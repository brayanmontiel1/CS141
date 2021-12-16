#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
using namespace std;

/*
 * References:
 * https://thispointer.com/c-how-to-find-an-element-in-vector-and-get-its-index/
 * https://www.tutorialspoint.com/how-to-print-out-the-contents-of-a-vector-in-cplusplus
 * https://www.cplusplus.com/
 * https://www.dropbox.com/sh/sbswo94twlek3s2/AAAbS61olo2yR2TguswC5fK1a/discussions/week1?dl=0&preview=stl.cpp&subfolder_nav_tracking=1
 */
int main() {
    //params
    int n; //size of arr
    int input; //cin param
    int m; //amount of queries
    int k; //target place

    cin >> n;
    vector<int> arr(n);
    //add the scores to array
    for(int a=0; a < n; a++){
        cin >> input;
        arr.at(a) = input;
    }

    //sort array
    sort(arr.begin(), arr.end()); // sort the array by incresing order

    cin>>m;      //taking m value (indexes)
    vector<int> items(m);
    int place = 0; //placeholder
    for(int i=0;i<m;i++) //loop thru amount of possible places
    {
        cin>>k;
        for(int j=0; j < n; j++) //loop thru arr
            if(arr.at(j) == k) //is index matches score
                items.at(place)= n - j; //index = size of arr - loop var
        place++; //add to index
    }
    //print out the places score.
    for(int i=0; i < m; i++)
    {
        cout<<items.at(i)<<endl;
    }
    return 0;
}

/* Find the k-th Student
#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
using namespace std;

int main() {
    //params
    int size; //size of arr
    int input; //cin param
    int m; //amount of queries
    int k; //target place

    cin >> size;
    vector<int> sizer(size);
    //add the scores to array
    for(int a=0; a < sizer.size(); a++){
        cin >> input;
        sizer[a] = input;
    }

    //sort array
    sort(sizer.begin(), sizer.end(), greater<>()); // sort the array by decreasing order

    cin >> m; //amount of queries
    vector<int> items; //will use to print out the queries
    for(int i =1; i <= m; i++){ //query for each m
        cin >> k;
        items.push_back(sizer[k-1]);
    }
    //print solution
    for(int i=0; i < items.size(); i++)
        cout << items.at(i) << endl;

    return 0;
}
------------------------------------------------------------------------------------*/