#include <iostream>
using namespace std;

int funnyEars(int funnies) {
	if(funnies==0) return 0;
	if(funnies%2==0) return funnyEars(funnies-1)+3;
	else return funnyEars(funnies-1)+2;
}

int main(){
    cout<<funnyEars(14);
}