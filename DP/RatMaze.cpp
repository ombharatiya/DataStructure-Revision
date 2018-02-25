// The Rat Maze Problem
// Copyright OM Bharatiya

#include<iostream>
#define N 4
using namespace std;
int a[N][N]{
		{1, 0, 0, 0}, 
		{1, 1, 0, 1}, 
		{0, 1, 0, 0}, 
		{1, 1, 1, 1}};

int n=N;
int dest_i=N-1,dest_j=N-1;

void printArr() {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) 
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}

bool isSafe(int i, int j){
	return (a[i][j]==1 && i>=0 && i<N && j>=0 && j<N);
}

bool ratMaze(int ii, int jj, int moves) {
	if(ii==dest_i && jj==dest_j) return true;
	
	for(int k=0;k<2;k++) {
		int i=ii,j=jj;
		if(k==0) 
			j=jj+1;
		else
			i=ii+1;
		
		if(isSafe(i,j)==true) {
			a[i][j]=moves+1;
			if(ratMaze(i,j,moves+1)==true)
				return true;
			else
				a[i][j]=1;
		}
	}
	return false;
	
}


void ratM() {
	printArr();
	cout<<"\n";
	a[0][0]=1;
	if(ratMaze(0,0,1)==true) 
		printArr();
	else
		cout<<"\nRAT MAZE DO NOT SOLVED";
}


int main() {
	ratM();
	
	return 0;
}