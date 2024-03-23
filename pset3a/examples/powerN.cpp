#include <iostream>
using namespace std;
long long unsigned powerN(int base, int n) {
	if(n==0) return 1;
	return powerN(base, n-1) * base;
}
int main(){
    cout<<powerN(2,10);
}