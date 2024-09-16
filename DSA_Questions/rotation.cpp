#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

vector<int> rotate_array( vector<int> arr,int n){

    int size = arr.size();

    for(int i=0;i<n;i++){

        int last = arr[size-1];

        for(int j=size-1;j>0;j--){
            arr[j] = arr[j-1];
        }
        arr[0] = last;

    }
    return arr;
}

int main() {

    vector<int> arr = {1,2,3,4,5};
   // now we are going to rotate the array.
    int n = 4;
    vector<int> answer = rotate_array(arr,5);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }

    cout << endl;
    return 0;
}


