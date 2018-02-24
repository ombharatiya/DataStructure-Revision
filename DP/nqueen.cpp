// N-Queen Problem

// Copyright OM Bharatiya

#include<iostream>

#define n 10
using namespace std;


int a[n][n];
// int n=4;


void printArr() {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) 
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}

bool isSafe(int i, int j) {
	
	for(int k=0;k<i;k++) {
		if(a[k][j]==1)
			return false;
	}
	
	for(int k=i, l=j; k>=0, l<n; k--,l++)
		if(a[k][l]==1) return false;
	
	for(int k=i, l=j; k>=0, l>=0; k--,l--)
		if(a[k][l]==1) return false;
	
	return true;
}


bool placeQ(int r) {
	if(r>=n) return true;
	for(int i=0;i<n;i++) {
		if(isSafe(r,i)) {
			a[r][i]=1;
			if(placeQ(r+1))
				return true;
			a[r][i]=0;
		}
	}
	return false;
}



int main() {
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=0;
		
	printArr();
	cout<<"\n";
	if(placeQ(0))
		printArr();
	else
		cout<<"\nNOT POSSIBLE";
	
	return 0;
}