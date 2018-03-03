#include<iostream>
#include<string.h>
// #define N 4
using namespace std;


bool isSet(char c[]) {
	int f=0,cn=sizeof(c)/sizeof(char);
	for(int i=0;i<cn;i++) {
		if(c[i]=='1') f++;
	}
	if(f==cn) return true;
	else return false;
}
	
	
string flipp(int k, string s) {
	int flip=0;
	char c[s.length()+1];
	int clen=sizeof(c)/sizeof(char);
	strcpy(c,s.c_str());
	for(int i=0;i<clen;i++) {
		if(!isSet(c)) {
			if(c[i]=='0') {
				flip++;
				for(int j=i;j<k+i && i+k<=clen ;j++) {
					if(c[j]=='0') c[j]='1';
					else c[j]='0';
				}
			}
		}
	}
	if(isSet(c)) return to_string(flip);
	else return "IMPOSSIBLE";
}

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++) {
		int k;string s;
		cin>>k>>s;
		cout<<flipp(k,s);
		// cout<<"\n"<<k<<"--"<<s;
	}
}