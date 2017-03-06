//arithmetic operations on complex no.
//mandeep singh @msdeep14
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
class complex;


class complex
{
	float real;
	float imaginary;
	public:
	complex();
	complex(int a,int b);
	complex operator +(complex &r);
	complex operator -(complex &r);
	complex operator *(complex &r);
	complex operator /(complex &r);
	complex operator ~();
	int operator ==(complex &r);
	friend istream & operator >>(istream &in, complex &r);
	friend ostream & operator <<(ostream &o, complex &r);
};

complex :: complex()
{
	real=1;
	imaginary=1;
}

complex :: complex(int a, int b)
{
	real=a;
	imaginary=b;
}

int complex :: operator ==(complex &r)
{
	if(r.real==real && r.imaginary==imaginary)
		return 1;
	else
		return 0;
}
complex complex :: operator ~()
		{
	complex temp;
	temp.real=real;
	temp.imaginary= imaginary - 2*imaginary;
	return temp;
		}


complex complex :: operator +(complex &r)
{
	complex temp;
	temp.real=real + r.real;
	temp.imaginary=imaginary + r.imaginary;
	return temp;
}

complex complex :: operator -(complex &r)
{
	complex temp;
	temp.real=real - r.real;
	temp.imaginary=imaginary - r.imaginary;
	return temp;
}

complex complex :: operator *(complex &r)
{
	complex temp;
	temp.real=real*r.real - imaginary*r.imaginary;
	temp.imaginary=real*r.imaginary + imaginary*r.real;
	return temp;
}

complex complex :: operator /(complex  &r)
{
	complex temp;
	temp.real=(real*r.real + imaginary*r.imaginary)/(r.real*r.real + r.imaginary*r.imaginary);
	temp.imaginary=(imaginary*r.real - real*r.imaginary)/(r.real*r.real + r.imaginary*r.imaginary);
	return temp;
}

istream& operator >>(istream &in, complex &r)
{
    cout<<"\n enter a and b of complex no.(a+ib) ";
    in>>r.real>>r.imaginary;
    return in;
}

ostream& operator <<(ostream &o, complex &ans)
{
		if(ans.imaginary>=0)
			{
				cout<<ans.real<<" + i"<<ans.imaginary<<endl;
			}
			else
			{
				cout<<ans.real<<" - i"<<(-ans.imaginary)<<endl;
			}
		return o;
}

void  switch_case()
{
	int choice,x;
	complex ans;
	complex c1,c2;
	cin>>c1>>c2;
	int flag=1;
	while(flag==1)
	{
	cout<<"\n1.ADD\n2.SUBTRACT\n3.EQUALITY\n4.MULTIPLY\n5.DIVIDE\n6.complementary\n";
	cout<<"Enter choice:: \n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			ans=c1+c2;
			cout<<ans;
			cout<<endl;
			break;
		case 2:
			ans=c1-c2;
			cout<<ans;
			cout<<endl;
			break;
		case 3:
			if(c1==c2)
			{
				cout<<"two complex no.s are equal\n\n";
			}
			else
			{
				cout<<"two complex no.s are unequal\n\n";
			}
			break;
		case 4:
			ans=c1*c2;
			cout<<ans;
			cout<<endl;
			break;
		case 5:
			ans=c1/c2;
			cout<<ans;
			cout<<endl;
			break;
		case 6:
			ans=~c1;
			cout<<ans<<endl;
			ans=~c2;
			cout<<ans<<endl;
			break;

		default:
			cout<<"YOu had entered the wrong chice!!!\n\n";
			break;
	}
		cout<<"\nEnter 1 to continue!!!\n";
		cin>>flag;
	}
}

int main()
{

	complex c1;
	complex c2(2,2);
	switch_case();
	return 0;
}

