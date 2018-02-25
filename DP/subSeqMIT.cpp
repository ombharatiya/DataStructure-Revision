// Printing All subsequences of a string
// output for abc:
// string = ,c,b,bc,a,ac,ab,abc


#include <iostream>
#include <string>

using namespace std;

string subsequencesAfter(string partialSubsequence, string word)
{
	if(word.empty())
	{
	return partialSubsequence;
	}

	return subsequencesAfter(partialSubsequence, word.substr(1))
	+ ","
	+ subsequencesAfter(partialSubsequence + word[0], word.substr(1));
}

string subsequence(string word)
{
	return subsequencesAfter("", word);
}

int main()
{
	string word = "abc";
	cout<<"string = "<<subsequence(word); 
	return 0;
}