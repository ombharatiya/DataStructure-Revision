import java.io.*;
import java.util.*;
// Print all no.s whose 1st and last digits are 1 in binary representation

class BinFirstLast{
	public static void main(String args[]) {
		for(int i=0;i<=20;i++) {
			String str = Integer.toBinaryString(i);
			if(str.charAt(0)=='1' && str.charAt(str.length()-1)=='1') {
				System.out.println(i);
			}
		}
		
	}
}

/*
>> java BinFirstLast
1
3
5
7
9
11
13
15
17
19
*/