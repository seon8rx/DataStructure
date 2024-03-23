#include <iostream>
using namespace std;
int sumDigits(int n) {
	if(n==0) return 0;
	return sumDigits(n/10)+n%10;
}
int main(){
    cout << sumDigits(123456789);
}