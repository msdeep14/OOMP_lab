//oomp string operations
//mandeep singh @msdeep14
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
class strings
{
	string s;
	public:
	strings();
	int operator ==(strings &r);
	int operator =(strings &r);
	string operator +(strings &r);
	int operator [](int i);

	friend ostream &  operator <<(ostream &o, strings &r);
	friend ostream &  operator >>(ostream &o, strings &r);
	friend istream &  operator >>(istream &in, strings &r);
	friend void find_palindrome(strings s1);
	friend void find_substring(strings s1,strings s2);
};

strings :: strings()
{
	s="Hello";
}

int strings :: operator[](int i)
{
	return sizeof(s)-1;
}

ostream &  operator >>(ostream &o, strings &r)
{
	reverse(r.s.begin(),r.s.end());
	return o;
}

string strings :: operator +(strings &r)
{
	string sx;
	sx=s+r.s;
	return sx;
}

int strings :: operator ==(strings &r)
{
	if(s==r.s)
		return 1;
	else
		return 0;
}

int strings :: operator =(strings &r)
{
	s=r.s;
}

istream &  operator >>(istream &in, strings &r)
{
	cin>>r.s;
	return in;
}

ostream &  operator <<(ostream &o, strings &r)
{
	o<<r.s;
	return o;
}

void find_palindrome(strings s1)
{
	int flag=0;
	string temp;
	temp=s1.s;
	int len;
	strings s;
	len=s1[0];
	cout<<"size:"<<len<<endl;
	reverse(temp.begin(),temp.end());
	for(int i=0;i<len;i++)
	{
		if(temp[i]!=s1.s[i])
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		cout<<s1.s<<" is not palindrome\n";
	}
	else
	{
		cout<<s1.s<<" is palindrome\n";
	}
}
/*
void find_substring(strings s1,strings s2)
{
	string sx;
	cout<<"enter the substring you want to search in given two strings :: \n";
	cin>>sx;
	for(int i=0;i<sizeof(s1.s);i++)
	{
		for()
	}
}
*/
void switch_case()
{
	strings s1;
	strings s2;
	string sx;
	strings temp;
	cout<<"enter string 1::\n";
	cin>>s1;
	cout<<"enter string 2:: \n";
	cin>>s2;
	int ch, flag=1;
	while(flag)
	{
		cout<<"enter option::\n1.== equality\n2.= string copy\n3.+ concatenate\n4.<< display string\n5.>> to reverse a string\n6.palindrome\n7.find occurrence of sub string\n\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				if(s1==s2)
				{
					cout<<"given strings are equal\n";
				}
				else
				{
					cout<<"given strings are unequal\n";
				}
				break;
			case 2:
				temp=s1;
				s1=s2;
				cout<<"1st string is::  "<<s1<<endl;
				cout<<"2nd string is::  "<<s2<<endl;
				s1=temp;
				break;
			case 3:
				sx=s1+s2;
				cout<<sx<<endl;
				break;
			case 4:
				cout<<"1st string is::  "<<s1<<endl;
				cout<<"2nd string is::  "<<s2<<endl;
				break;
			case 5:
				temp=s1;
				cout>>s1;
				cout<<"Reversed 1st string is:: "<<s1<<endl;
				s1=temp;
				temp=s2;
				cout>>s2;
				cout<<"Reversed 2nd string is:: "<<s2<<endl;
				s2=temp;
				break;
			case 6:
				find_palindrome(s1);
				find_palindrome(s2);
				break;
			case 7:
				//find_substring(s1,s2);
				break;
		}
		cout<<"\nenter 1 to continue\n";
		cin>>flag;
	}
}

int main()
{
	switch_case();
	return 0;
}
