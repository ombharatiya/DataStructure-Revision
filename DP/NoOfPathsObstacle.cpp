// Copyright OM Bharatiya

#include<iostream>
#define N 4
using namespace std;
int a[N][N]{
		{0, 0, 0, 0}, 
		{0, 1, 0, 1}, 
		{0, 1, 0, 0}, 
		{0, 0, 0, 0}};

// int a[N][N]{
		// {0, 0, 0}, 
		// {0, 0, 0}, 
		// {0, 0, 0}};

// int n=N;

int noOfPath(int m, int n) {
	int x,y;
	if(a[m][n]==1) return 0;
	if(m==0 && n==0) return 0;
	else if(m==0 || n==0) return 1;
	else{
		if(a[m-1][n]==1) x=0;
		else x= noOfPath(m-1,n);
		if(a[m][n-1]==1) y=0;
		else y= noOfPath(m,n-1);
	}
		return (x+y);
}


void noOfPathsMain() {
	cout<<"No Of Paths: "<<noOfPath(N-1,N-1);
}

int main() {
	noOfPathsMain();
	
	return 0;
}