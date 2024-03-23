#include <iostream>
#include <sstream>
using namespace std;

long long unsigned fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return fibonacci(n-1) + n;
    
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int i;
    string str;
    getline(cin, str);
    try{
            i = stoi(str);
        }
        catch(invalid_argument& e){
            cerr << e.what() << " error occurred. Retry~" << endl;
        }
    cout << fibonacci(i) << endl;
}