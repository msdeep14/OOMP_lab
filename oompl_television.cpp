//oompl television
#include<iostream>
#include<exception>
#include<stdexcept>
#include<limits>
using namespace std;
class exceptionn : public exception 
{
	public:
	const char *what() const throw(){};
};

class television
{
	int model_no;
	double screen_size;
	double price;
	public:
	television();
	friend istream & operator >>(istream &in , television &r);
	friend ostream &operator <<(ostream &out, television &r);
	void replace_zero();
};

television :: television()
{
	model_no=0;
	screen_size=0.0;
	price=0.0;
}



istream & operator >>(istream &in , television &r)
{
	exceptionn e;
	cout<<"enter model no."<<endl;
	cin>>r.model_no;
	if(r.model_no>9999) throw invalid_argument("model no cannot be greater than 9999\n");
	cout<<"enter screen size:"<<endl;
	cin>>r.screen_size;
	if(r.screen_size<12 || r.screen_size>70) throw invalid_argument("screen size cant be less than 12 && greater than 12\n");
	cout<<"enter price:";
	cin>>r.price;
	if(r.price<0 || r.price>5000) throw invalid_argument("price cant be negative && greater than $5000\n");
	return in;
}

ostream &operator <<(ostream &out , television &r)
{
	cout<<"model no.      "<<r.model_no<<endl;
	cout<<"screen_size    "<<r.screen_size<<endl;
	cout<<"price          "<<r.price<<endl;
	return out;
}

void television :: replace_zero()
{
	model_no=0;
	price=0.0;
	screen_size=0.0;
}

int main()
{
	television t;
	try
	{
		cin>>t;
	}
	catch(invalid_argument &r)
	{
		cout<<r.what()<<endl;
	}
	cout<<t;
	return 0;
}