/*  C++ code to generate all possible subsequences.
    Time Complexity O(n * 2^n) */
/*
All Non-empty Subsequences
H
E
H E
L
H L
E L
H E L
L
H L
E L
H E L
L L
H L L
E L L
H E L L
O
H O
E O
H E O
L O
H L O
E L O
H E L O
L O
H L O
E L O
H E L O
L L O
H L L O
E L L O
H E L L O

***************************ERROR WHILE RUNNING************************************

*/
	
	
	
#include<bits/stdc++.h>
using namespace std;
 
void printSubsequences(string s, int n)
{
    /* Number of subsequences is (2**n -1)*/
    unsigned int opsize = pow(2, n);
 
    /* Run from counter 000..1 to 111..1*/
    for (int counter = 1; counter < opsize; counter++)
    {
        for (int j = 0; j < n; j++)
        {
            /* Check if jth bit in the counter is set
                If set then print jth element from arr[] */
            if (counter & (1<<j))
                cout << s[j] << " ";
        }
        cout << endl;
    }
}
 
// Driver program
int main()
{
    // int arr[] = {1, 2, 3, 4};
	string s="HELLO";
    // int n = sizeof(arr)/sizeof(arr[0]);
	int n=sizeof(s)-1;
    cout << "All Non-empty Subsequences\n";
    printSubsequences(s, n);
    return 0;
}