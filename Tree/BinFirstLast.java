import java.io.*;
import java.util.*;


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