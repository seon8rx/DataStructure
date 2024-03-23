#include <iostream>
using namespace std;

long long unsigned factorial(int n){
    cout << "n = " << n << endl;
    if (n==1 || n==0) return n;
    auto result = n * factorial(n-1);
    cout << "n = " << n << "\tn!= " << result << endl;
    return result;
}

int main(){
    factorial(5);
}