// The Knight Tour Problem
// Copyright OM Bharatiya

#include<iostream>
#define N 8
using namespace std;
int a[N][N];
int n=N;

int x[]={2,1,-1,-2,-2,-1,1,2};
int y[]={1,2,2,1,-1,-2,-2,-1};

void printArr() {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) 
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}

bool isSafe(int i, int j) {
	return (i>=0 && i<N && j>=0 && j<N && a[i][j]==-1);
}

bool isKnightTour(int i, int j, int moves){
	int ii,jj;
	if(moves==N*N) return true;
	for(int k=0;k<8;k++) {
		ii=i+x[k];
		jj=j+y[k];
		if(isSafe(ii,jj)==true) {
			a[ii][jj]=moves+1;
			if(isKnightTour(ii,jj,moves+1)==true)
				return true;
			else a[ii][jj]=-1;
		}
	}
	return false;
}

void knightT() {
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=-1;
		
	printArr();
	
	int i=0,j=0,moves=1;
	cout<<"\n";
	a[i][j]=1;
	
	// if(isKnightTour(0,0,1)==true)
	if(isKnightTour(i,j,moves))
		printArr();
	else
		cout<<"\nNOT POSSIBLE";
	
}

int main() {
	knightT();
	return 0;
}
