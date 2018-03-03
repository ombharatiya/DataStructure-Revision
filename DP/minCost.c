#include<stdio.h>

/*
input for 6x6 matrix
1 2 3 4 5 6
7 8 9 10 1 2
4 2 5 3 6 8
9 6 3 1 7 8
8 3 2 4 2 9
0 6 4 3 6 4

output 38
*/

#define MIN(a,b) (((a)<(b))?(a):(b))
int a[6][6];
int cach[6][6];
int count;
int minCostPath(int m,int n) {
	// printf("(%d,%d) ",m+1,n+1);
	if(m==0 && n==0)
		return a[m][n];
	else if(m==0)
		return a[m][n]+minCostPath(m,n-1);
	else if(n==0)
		return a[m][n]+minCostPath(m-1,n);
	else
		return a[m][n]+MIN(minCostPath(m,n-1),minCostPath(m-1,n));
}
// int minCostPathPrint(int m,int n) {
	// // printf("(%d,%d) ",m+1,n+1);
	// if(m==0 && n==0)
		// return a[m][n];
	// else if(m==0)
		// return a[m][n]+minCostPath(m,n-1);
	// else if(n==0)
		// return a[m][n]+minCostPath(m-1,n);
	// else
		// return a[m][n]+MIN(minCostPath(m,n-1),minCostPath(m-1,n));
// }

int minCostPathDP(int m,int n) {
	count++;
	// printf("(%d,%d) ",m+1,n+1);
	// printf("(%d) ",cach[m][n]);
	
	if(cach[m][n]!=0){
		return cach[m][n];
	}
	if(m==0 && n==0) {
		cach[m][n]=a[m][n];
		// printf("(%d) ",cach[m][n]);
	}
	else if(m==0) {
		cach[m][n]=a[m][n]+minCostPathDP(m,n-1);
		// printf("(%d) ",cach[m][n]);
	}
	else if(n==0) {
		cach[m][n]=a[m][n]+minCostPathDP(m-1,n);
		// printf("(%d) ",cach[m][n]);
	}
	else {
		// printf("(%d) ",cach[m][n]);
		cach[m][n]=a[m][n]+MIN(minCostPathDP(m,n-1),minCostPathDP(m-1,n));
		
	}
	
	// printf("(%d,%d) ",m+1,n+1);
	return cach[m][n];
}
int main() {
	
	int n,i,j;
	// scanf("%d",&n);
	
	// int a[n][n];
	count=0;
	printf("Enter the size: ");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d",&a[i][j]);
			cach[i][j]=0;
		}
	}
	printf("\n");
	// a[6][6]={{1,2,3,4,5,6},{7,8,9,10,3,4},{2,7,3,8,4,7},{4,7,3,0,5,8},{5,9,3,1,3,5},{5,7,4,2,5,10}};
	
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	printf("\n---%d ----%d",minCostPathDP(3,3),count);
	
	return 0;
}

