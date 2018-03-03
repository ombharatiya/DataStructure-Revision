// Sorting for a database


#include<iostream>
#include<cstring>
// #define N 4
using namespace std;


typedef struct student{
	int r;
	char n[15];
	char g;
}Stud;

void printStruct(Stud a[]) {
	for(int i=0;i<4;i++) {
		cout<<a[i].r<<"  "<<a[i].n<<"  "<<a[i].g<<endl;
	}
}

void copyStruct(Stud &a, Stud &b){
	a.r=b.r;
	strcpy(a.n,b.n);
	a.g=b.g;
}

// bool compare(int a, int b) {
	// // To Compare if(a>b)
		
	// return (a>b?true:false);
// }
// bool compare(char a, char b) {
	// // To Compare if(a>b)
		
	// return (a>b?true:false);
// }
// bool compare(char a[], char b[]) {
	// // To Compare if(a>b)
		
	// return ((strcmp(a,b)>1)?true:false);
// }

bool compareR(Stud &a, Stud &b) {
	// To Compare if(a>b)
		
	return (a.r>b.r?true:false);
}
bool compareG(Stud &a, Stud &b) {
	// To Compare if(a>b)
		
	return (a.g>b.g?true:false);
}
bool compareN(Stud &a, Stud &b) {
	// To Compare if(a>b)
		
	return ((strcmp(a.n,b.n)>0)?true:false);
}

Stud* sort(Stud arr[], int n, bool (*compare)(Stud&, Stud&)) {
	int i, j;
	// int keyR;
	// char keyC[15];
	// char keyG;
	Stud key;
	
   for (i = 1; i < n; i++) {
       // keyR = arr[i].r;
	   // strcpy(keyC, arr[i].n);
	   // keyG = arr[i].g;
	   copyStruct(key, arr[i]);
       j = i-1;
 
		/* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position 
		*/
		
       while (j >= 0 && compare(arr[j], key)) {
           // arr[j+1].r = arr[j].r;
		   // strcpy(arr[j+1].n,arr[j].n);
		   // arr[j+1].g=arr[j].g;
		   
		   copyStruct(arr[j+1],arr[j]);
           j = j-1;
       }
       // arr[j+1].r = keyR;
	   // strcpy(arr[j+1].n, keyC);
	   // arr[j+1].g = keyG;
	   
	   copyStruct(arr[j+1], key);
   }
   
   return arr;
}

int main() {
	Stud a[4];
	
	a[0].r=2;
	strcpy(a[0].n,"Ram");
	a[0].g='b';
	
	a[1].r=5;
	strcpy(a[1].n,"Shyam");
	a[1].g='d';
	
	a[2].r=3;
	strcpy(a[2].n,"Hari");
	a[2].g='a';
	
	a[3].r=9;
	strcpy(a[3].n,"Mohan");
	a[3].g='a';
	
	
	cout<<"\nGiven Database of Students:\n";
	printStruct(a);
	
	cout<<endl;
	
	
	cout<<"\nSorting According to Roll No:\n";
	printStruct(sort(a, 4, &compareR));
	cout<<endl;
	
	cout<<"\nSorting According to Name:\n";
	printStruct(sort(a, 4, &compareN));
	cout<<endl;
	
	cout<<"\nSorting According to Grade:\n";
	printStruct(sort(a, 4, &compareG));
}