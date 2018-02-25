// Substrings of a string problem
// Copyright OM Bharatiya

/*
abc

a
b
c
ab
bc
ac
abc
*/

#include<iostream>
#include<bits/stdc++.h>
// #define N 4
using namespace std;


void substringOfString(string s, int n) {
	
	int t=(int)(pow(2,n)-1);
	
	for(int i=0;i<t;i++) {
		for(int j=0;j<n;j++) {
			cout<<s[j];
		}
		cout<<"\n";
	}
}


int main() {
	string s = "abcd";
	substringOfString(s,s.length());
	return 0;
}