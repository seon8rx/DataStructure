#include <iostream>
using namespace std;

int triangle(int rows) {
	if(rows==0) return 0;
	return triangle(rows-1)+rows;
}

int main(){
    cout<<triangle(10);
}