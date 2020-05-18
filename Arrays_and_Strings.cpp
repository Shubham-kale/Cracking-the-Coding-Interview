/*
Chapter-1. Arrays and Strings

Each of the problems is implemented as a function
*/
#include<iostream>
#include<string>
#include<cstdlib>
#include<map>
using namespace std;


//1.1 isUnique : Implement an algorithm to determine if a string has all unique characters.

bool isUnique(string s)
{
	const char *str  = s.c_str(); //converting the string to C-style character array
	/*
	// Method -1 
	for(int i=0;i<s.size();i++)
	{
		for(int j=i+1;j<s.size();j++)  // A brute force approach with time complexity of O(n^2)
		{                              // where 'n' is length of the string passed.
			if(str[i] == str[j] )
			{
				return false;
			}
		}
	}
	return true;
	*/
	
	//Method - 2
	map<char,int> record;
	for(int i=0;i<s.size();i++)
	{
	    // A map approach with time complexity of O(n)
		// where 'n' is length of the string passed.
			if( record.find(str[i]) == record.end() )
			{
			      record.insert(make_pair(str[i],1));
			}
			else
			{
			    return false;
			}
	}
	return true;
	
	//Method - 3 : we can also use stl's set to do this
	
}


// 1.2 checkPermutation : Given two strings, write a method to decide if one is a permutation of the other.

bool checkPermutation(string s1, string s2)
{
   const char *str1 = s1.c_str();
   const char *str2 = s2.c_str();
   //Method - 1 : Brute force approch taking O(n^2) time
   /*
   if(s1.size() == s2.size())
   {
   	 char c1,c2;
	 int i1,i2;
   	 for(int i=0;i<s1.size(); i++)
   	 {
   	 	c1 = str1[i];
   	 	i1 = 0;
   	 	i2 = 0;
        for(int j=0;j<s1.size();j++)
		{
	       if(c1 == str1[j])
		   {
		      i1++; 	
		   }	   		   	
		}	
		for(int j=0;j<s2.size();j++)
		{
	       if(c1 == str2[j])
		   {
		      i2++; 	
		   }	   		   	
		}
		if(i1==i2)
		{
			continue;
		}
		else
		{
			return false;
		}
   	 }
   }
   return true;	
   */
   //Method - 2 : using map, takes O(n) time
   map<char,int> record1;
   map<char,int> record2;
   if(s1.size() == s2.size())
   {
	   for(int i=0;i<s1.size();i++)
	   {
	   	  auto ptr = record1.find(str1[i]);
	   	  if( ptr == record1.end())
	   	  {
	   	     	record1.insert(make_pair(str1[i],1));
		  }
		  else
		  {
	     		(ptr->second)++;
		  }
	   }
	   for(int i=0;i<s2.size();i++)
	   {
	   	  auto ptr = record2.find(str2[i]);
	   	  if( ptr == record2.end())
	   	  {
	   	        record2.insert(make_pair(str2[i],1));
		  }
		  else
		  {
	         	(ptr->second)++;		
		  }
	   }
	   if(record1.size() == record2.size())
       {
       	  for(auto j= record1.begin();j != record1.end();j++)
       	  {
       	     	if(record2[j->first] == j->second)
       	     	  continue;
       	     	else
				  return false;  
		  }
		  return true;
       }
   }
   return false;
} 

//1.3 URLify : Write a method to replace all spaces in a string with '%20'. You may assume that the string
//has sufficient space at the end to hold the additional characters, and that you are given the "true"
//length of the string.

string URLify(string s, int length)
{
	string ans = "";
	string code  = "%20";
	const char *c = s.c_str();
	for(int i=0;i<length;i++)    //takes O(length) time
	{
		if(c[i] == ' ')
		{
			ans+= code;
		}
		else
		{
			ans+= c[i];
		}
	}
	return ans;
}


/*
1.4 Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rearrangement of letters.
*/
bool palindromePermutation(string s)
{
	const char *arr = s.c_str();
	map<char,int> record;
	bool flag = false;
	int len=0;
	for(int i=0;i<s.size();i++)
	{
		char ch;
	    if(arr[i] != ' ')
		{ 	
			if(isupper(arr[i]))
			  ch=tolower(arr[i]);
			auto val = record.find(ch);
			if( val == record.end() )
			{
				  record.insert(make_pair(ch,1));
				  len++;
			}
			else
			{
			   (val->second)++;
			   len++;	
			}
		}
	}
	if( len % 2 == 0)
	{
		for(auto ptr = record.begin();ptr!=record.end();ptr++)
		{
			if((ptr->second)%2 == 0)
			{
				flag=true;
				continue;
			}
			else
			{
				flag=false;
				break;
			}
		}
	}
	else
	{
		int odd_count = 0;
		for(auto ptr = record.begin();ptr!=record.end();ptr++)
		{
			if((ptr->second)%2 == 0)
			{
				continue;
			}
			else
			{
				odd_count++;
			}
		}
		if(odd_count == 1)
		  flag = true;
	}
	return flag;
}

/*
1.5 One Away: There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away.
*/
bool oneAway(string s1, string s2)
{
	int edits_required=0;
	int l1 = s1.size();
	int l2 = s2.size();
	bool flag = false;
	if( ( l1 == l2 ) || (abs(l1-l2) == 1) )  //this approch takes O(n) time,
	{                                        // where 'n' is length of the shorter string
		int lesser=0;
		int s_str = 1;
		map<char,int> record1;
		map<char,int> record2;
		for(int k=0;k<l1;k++)
		{
			auto ptr = record1.find(s1[k]);
			if( ptr == record1.end())
			{
				record1.insert(make_pair(s1[k],1));
			}
			else
			{
				(ptr->second)++;
			}
		}
		for(int k=0;k<l2;k++)
		{
			auto ptr = record2.find(s1[k]);
			if( ptr == record2.end())
			{
				record2.insert(make_pair(s1[k],1));
			}
			else
			{
				(ptr->second)++;
			}
		}
		edits_required = abs(l1-l2);
		if(edits_required > 1)
		   return flag;
		if(l1<l2)
		  lesser = l1;
		else
		{
			 s_str = 2;
			 lesser = l2;
		}
		      
		for(int i=0;i<lesser;i++)
		{
			if(s_str == 1)
			{
				if(record2.find(s1[i]) != record2.end())
				 continue;
				else
				{
				    ++edits_required;
					if(edits_required > 1)
			         	return flag;	
				} 
			}
			else
			{
				if(record1.find(s2[i]) != record1.end())
				 continue;
				else
				{
				    ++edits_required;
					if(edits_required > 1)
			         	return flag;	
				} 
				
			}
		}
		flag = true;
	}
	return flag;
}

/*
1.6 String Compression: Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the
"compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a - z).
*/
string stringCompression(string s)
{
	string ans="";
	map<char,int> record;
	for(int i=0;i<s.length();i++)
	{
		auto ptr = record.find(s[i]);
		if(ptr == record.end())
		{
			record.insert(make_pair(s[i],1));
		}
		else
		{
		    (ptr->second)++;	
	    }
	}
	char ch_before = ' ';
	char ch_after = ' ';
	for(int i=0;i<s.length();i++)
	{
		ch_after = s[i];
		if(ch_before != ch_after)
		{
			ans = ans + ch_after;
			char temp[1];
			itoa((record.find(ch_after)->second), temp, 10);
			ans+= temp;
		}
		ch_before = ch_after;
	}
	return ans;
}

/*
1.7 Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

Sample Output :-

Enter the dimension of image N ===>
3
Enter the image array of dimensions3 X 3
Enter element arr[1][1] :       7
Enter element arr[1][2] :       8
Enter element arr[1][3] :       9
Enter element arr[2][1] :       4
Enter element arr[2][2] :       5
Enter element arr[2][3] :       6
Enter element arr[3][1] :       1
Enter element arr[3][2] :       2
Enter element arr[3][3] :       3
90 degree rotated image is :-
1 4 7
2 5 8
3 6 9

*/
void rotateMatrix(int n)
{
	int arr[n][n];
	int arrT[n][n];
	cout<<"Enter the image array of dimensions"<<n<<" X "<<n<<endl;
	for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
	    {
		  	cout<<"Enter element arr["<<i+1<<"]["<<j+1<<"] : \t";
		  	cin>>arr[i][j];
	    }
	for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
		{
			arrT[j][i]=arr[i][j];
		} 
	for(int i=0;i<n;i++)
	  for(int j=0,jr=n-1;j<n && jr>=0;j++,jr--)
		{
			arr[i][jr]=arrT[i][j];
		}   
	cout<<"90 degree rotated image is :-"<<endl;
	for(int i=0;i<n;i++)
	 {
	  for(int j=0;j<n;j++)
	    {
		  	cout<<arr[i][j]<<" ";
	    }
	    cout<<"\n";
	}
}

/*
1.8 Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column are set to 0.

Sample Output:-
Enter dimensions of matrix i.e M x N :- 3 3
Enter the matrix of dimensions 3 X 3
Enter element arr[1][1] :       1
Enter element arr[1][2] :       2
Enter element arr[1][3] :       3
Enter element arr[2][1] :       4
Enter element arr[2][2] :       0
Enter element arr[2][3] :       6
Enter element arr[3][1] :       7
Enter element arr[3][2] :       8
Enter element arr[3][3] :       9

Zero Matrix is :-
1 0 3
0 0 0
7 0 9
*/
void zeroMatrix()
{
	int m,n;
	cout<<"Enter dimensions of matrix i.e M x N :-\t";
	cin>>m>>n;
	int arr[m][n];
	map<int,int> record;
	cout<<"Enter the matrix of dimensions "<<m<<" X "<<n<<endl;
	for(int i=0;i<m;i++)
	  for(int j=0;j<n;j++)
	    {
		  	cout<<"Enter element arr["<<i+1<<"]["<<j+1<<"] : \t";
		  	cin>>arr[i][j];
		  	if(arr[i][j] == 0)
		  	{
		  	   record.insert(make_pair(i,j));	
			}
	    }
	
	for(auto ptr = record.begin(); ptr != record.end() ; ptr++)
	 {	
	  for(int k=0;k<n;k++)
	    {  	
	       	 arr[ptr->first][k] = 0;
	       	 arr[k][ptr->second] = 0;
	    }
	 }
	cout<<"\nZero Matrix is :-\n";  
	for(int i=0;i<n;i++)
	 {
	  for(int j=0;j<n;j++)
	    {
		  	cout<<arr[i][j]<<" ";
	    }
	    cout<<"\n";
	}   
}
/*
1.9 String Rotation:Assume you have a method isSubstringwhich checks if one word is a substring
of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one
call to isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat").
*/
bool areStringsEqual(string s1, string s2)
{
	bool flag=false;
	if(s1.length() == s2.length())
	{
		for(int i=0;i<s1.length();i++)
		{
			if(s1[i] == s2[i])
			  flag=true;
			else
			{
			  flag=false;
			  break;
		    }
		}
	}
	return flag;
}
// boat ====> tboa     //string is rotated one step towards right
string rotateStringRight(string s)
{
	string rs = s;
	rs[0] = s[s.length() - 1];
	for(int i=1;i<s.length();i++)
	{
		rs[i] = s[i-1];
	}
	return rs;
}

bool isSubstring(string s1, string s2)
{
   bool result = false;
   if(s1.length() > s2.length())
   {
   	for(int k=0;k<s1.length()-s2.length();k++)
   	{
   	    	for(int i=0;i<s2.length();i++)
   	    	{
   	    	   if(s1[k+i] == s2[i])
				  {
				    result=true;
					continue;  	
				  }
			   else
			      {
			   	    result  = false;
			   	    break;
			      }	  	
			}
			if(result)
			  break;
	 }
   }
   else
   {
   	for(int k=0;k<s2.length()-s1.length();k++)
   	{
   	    	for(int i=0;i<s1.length();i++)
   	    	{
   	    	   if(s2[k+i] == s1[i])
				  {
				    result=true;
					continue;  	
				  }
			   else
			      {
			   	    result  = false;
			   	    break;
			      }	  	
			}
			if(result)
			  break;
	 }
   }
   return result;	
}

bool stringRotation(string s1, string s2)
{
   /*	
   bool ans=false;
   //Method-1 : brute-force approach with Time complexity O(n^2), where 'n' is length of the string
   
   if(s1.length() == s2.length())
   {
   	 for(int k=0;k<s1.length();k++)
   	 {	
   	   if(areStringsEqual(s1,s2))
		  {
		     ans=true;
			 break;	
		  }
		s2 = rotateStringRight(s2);	
	 }
   }
   return ans;
   */
   
   /*
   Method - 2 : Assuming we have a method "isSubstring", we can directly check 
   if one sting is rotation of other by concatenating the other string with itself
   and checking if the original string is substring of this newly formed string.
   In this case the time complexity depends upon the way the method "isSubstring"
   is implemented.
   
   */
   if(s1.length() == s2.length())
   {
     s2=s2+s2;
     return isSubstring(s1,s2);  //also takes O(n^2) time as per the implementation above
   }
   return false;	
}

int main()
{
	int n;
	cout<< isUnique("shubham") << endl;
	cout<< checkPermutation("shubham","samprada") << endl;
	cout<< URLify("Mr John Smith   ",13) << endl;
	cout<< palindromePermutation("Tact Coa") << endl;
	cout<< oneAway("pale","bake") <<endl;
	cout<< stringCompression("aabcccccddd") << endl;
	cout<< "Enter the dimension of image N ===> " <<endl;
	cin>>n;
    rotateMatrix(n);
    zeroMatrix();
    cout<< stringRotation("waterbottle","rebottlewat") << endl;
	return 0;
}
