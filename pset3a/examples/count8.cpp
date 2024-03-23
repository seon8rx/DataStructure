#include <iostream>
using namespace std;
int count8(int n) {
	if(n==0) return 0;
	if(n%10==8) return count8(n/10) + 1;
	else return count8(n/10);
}
int main(){
    cout << count8(888586198);
}