#include <iostream>
#include <vector>
#include <queue>
//#include <bits/stdc++.h>

using namespace std;

/*
 * References:
 * https://www.cplusplus.com/
 * https://www.dropbox.com/sh/sbswo94twlek3s2/AABZlrFyq8yjGIvVAwILqPiia/slides/uer.pdf&subfolder_nav_tracking=1
 */
int findCheapestPrice(vector<vector<int> >& arr1, int n, int m, int s, int t){
    vector<int> arr2(n, INT_MAX);    //distance of the first city to all other cities
    arr2[s] = 0;        //initialize beginning city s to 0

    for (int i = 0; i <= m; i++) { //iterate thru loop m times.
        vector<int> temp(arr2);     //initiate temp vector with arr2
        for (auto city : arr1) {
            if (arr2[city[0]] != INT_MAX) { //if time at 0 is not MAX
                temp[city[1]]= min(temp[city[1]],arr2[city[0]] + city[2]); //get the min from temp at city 1 compared to city 0 and 2
            }
        }
        arr2 = temp; //update arr2
    }

    // Return arr2 at last city to get shortest time.
    return arr2[t];
}


int main() {
    ios_base::sync_with_stdio(false);
    int n = 0,m = 0, s = 0,t = 0;
    for (int i =0; i<1; i++){
        cin >> n; //cities (nodes)
        cin >> m; //roads (edges)
    }
    for (int i =0; i<1; i++){
        cin >> s; //cities (nodes)
        cin >> t; //roads (edges)
    }

    int input;
    vector<vector<int>> arr1; // array of cities and time traveled
    //get values
    for (int i =0; i<m; i++){
        vector<int> myvector;
        for (int j =0; j<3; j++) {
            cin >> input;
            myvector.push_back(input);
        }
        arr1.push_back(myvector);
    }

    cout << findCheapestPrice(arr1,n, m, s, t);

    return 0;
}


/*
int findCheapestPrice(vector<vector<int> >& arr1, int n, int m, int s, int t){
    vector<int> arr2(n, INT_MAX);    //distance of the first city to all other cities
    arr2[s] = 0;        //initialize beginning city s to 0

    for (int i = 0; i <= m; i++) { //iterate thru loop m times.
        vector<int> temp(arr2);     //initiate temp vector with arr2
        for (auto city : arr1) {
            if (arr2[city[0]] != INT_MAX) { //if time at 0 is not MAX
                temp[city[1]]= min(temp[city[1]],arr2[city[0]] + city[2]); //get the min from temp at city 1 compared to city 0 and 2
            }
        }
        arr2 = temp; //update arr2
    }

    // Return arr2 at last city to get shortest time.
    return arr2[t];
}


int main() {
    ios_base::sync_with_stdio(false);
    int n = 0,m = 0, s = 0,t = 0;
    for (int i =0; i<1; i++){
        cin >> n; //cities (nodes)
        cin >> m; //roads (edges)
    }
    for (int i =0; i<1; i++){
        cin >> s; //cities (nodes)
        cin >> t; //roads (edges)
    }

    int input;
    vector<vector<int>> arr1; // array of cities and time traveled
    //get values
    for (int i =0; i<m; i++){
        vector<int> myvector;
        for (int j =0; j<3; j++) {
            cin >> input;
            myvector.push_back(input);
        }
        arr1.push_back(myvector);
    }

    cout << findCheapestPrice(arr1,n, m, s, t);

    return 0;
}
*/
