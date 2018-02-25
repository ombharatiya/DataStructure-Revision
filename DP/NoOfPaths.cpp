// Copyright OM Bharatiya
// No of path possible to go to the (N-1,N-1) block of a matrix starting from (0,0)
#include<iostream>
#define N 4
using namespace std;

int noOfPath(int m, int n) {
	if(m==0 && n==0) return 0;
	else if(m==0 || n==0) return 1;
	else return ( noOfPath(m-1,n) + noOfPath(m,n-1) );
}


void noOfPathsMain() {
	cout<<"No Of Paths: "<<noOfPath(N-1,N-1);
}

int main() {
	noOfPathsMain();
	
	return 0;
}