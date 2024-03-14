/*
On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this assignment.
서명: 김성규 학번: 22100110
*/

#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
// gets the max value in the list and returns the reference of the max value
// your code here – define getmax() here
int& getmax(vector<int> &vec){
    assert(vec.size() > 0);
    
    // int& max = vec[0];
    // for(int i = 0; i<vec.size(); i++) if(vec[i]>max) max = vec[i];
    // return max;

    size_t idx = 0;
    for(int i=0; i<vec.size(); i++){
        if(vec[i]>vec[idx]) idx = i;
    }

    return vec[idx];
}
// sets the max value in the list to 99
// your code here – define setmax() here
void setmax(vector<int> &ret){
    getmax(ret) = 99;
}
// With a given list, find the max value, then set it to 99 in setmax()
int main(int argc, char *argv[]) {
    vector<int> list1 = {43, 10, 20, 75, 22, 33};
    vector<int> list2 = {33, 13, 45, 19, 39, 22};
    cout << ">list1: ";
    for (auto x: list1) cout << x << " ";
    cout << endl;
    setmax(list1);
    cout << "<list1: ";
    for (auto x: list1) cout << x << " ";
    cout << endl << endl;
    cout << ">list2: ";
    for (auto x: list2) cout << x << " ";
    cout << endl;
    setmax(list2);
    cout << "<list2: ";
    for (auto x: list2) cout << x << " ";
    cout << endl;
    return 0;
}
