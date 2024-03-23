#include <iostream>
using namespace std;

int bunnyEars(int bunnies) {
	if (bunnies == 0) return 0;

	// Recursive case: otherwise, make a recursive call with bunnies-1
	// (towards the base case), and fix up what it returns.
	return 2 + bunnyEars(bunnies - 1);
}

int main(){
    cout<< bunnyEars(100);
}