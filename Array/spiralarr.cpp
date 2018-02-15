#include<iostream>

using namespace std;
void spiral(int a[][4], int mm, int nn) {
	int l=(nn+1)/2;
	// int mm=m,nn=n;
	int i=0,j=0;
	while(l--){
		int j0=j,i0=i;
		for(j=j;j<nn;j++)
			cout<<a[i][j]<<" ";
		j--;
		// cout<<"\n";
		for(i=i+1;i<mm;i++)
			cout<<a[i][j]<<" ";
		i--;
		// cout<<"\n";
		for(j=j-1;j>=j0;j--)
			cout<<a[i][j]<<" ";
		j++;
		// cout<<"\n";
		for(i=i-1;i>i0;i--)
			cout<<a[i][j]<<" ";
		i++;
		// cout<<"\n";
		j++;nn--;mm--;
		
		
		
		// l--;
	}
}

int main(){
	int a[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	for(int i=0;i<4;i++ ) {
		for(int j=0;j<4;j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	spiral(a,4,4);
}