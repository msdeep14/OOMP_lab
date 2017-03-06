#include<iostream>
#include<cstring>
using namespace std;

class student
{
	protected :
		string name;
		string subject[3];
	public :
		void input();
		
};

class personal : public virtual student
{
	protected :
		int height,weight;
		char gender;
		personal()
		{
			height =0;
			weight = 0;
			gender = ' ';
		}
		void input();

};

class academic : public virtual student
{
	protected :
		float marks[3];
	public :
	academic()
	{
		marks[0] = marks[1] = marks[2] = 0 ;
	}
	void input();
};

class include : public personal, public academic
{
	public :
		int roll;
		include()
		{
			roll = 0;
		}
		void input();
		void output();
		void del()
		{
			this -> roll = 0;
		}
};

void include :: output()
{
	cout<<"\n Name : "<<student :: name;
	cout<<"\n Height : "<<personal :: height;
	cout<<"\n Weight : "<<personal :: weight;
	cout<<"\n Gender : "<<personal :: gender;
	cout<<"\n Marks in "<<student ::subject[0]<<" is "<<academic :: marks[0];
	cout<<"\n Marks in "<<student ::subject[1]<<" is "<<academic :: marks[1];
	cout<<"\n Marks in "<<student ::subject[2]<<" is "<<academic :: marks[2];
}

void include :: input()
{
	student :: input();
	personal :: input();
	academic :: input();
}

void academic :: input()
{
	int i;
	cout<<"Enter marks\n"<<endl;
	for(i=0; i < 3; i++)
	{
		cout<<"Enter marks "<<subject[i]<<" : ";
		cin>>marks[i];
	}
}


void personal :: input()
{
	cout<<"Enter height : ";
	cin>>height;
	cout<<"Enter weight : ";
	cin>>weight;
	cout<<"Enter gender : ";
	cin>>gender;
}

void student :: input()
{
	cout<<"Enter name : ";
	cin>>name;
	cout<<"Enter subject name\n\n";
	for(int i = 0; i< 3; i++)
	{
		cout<<i+1<<". ";
		cin>>subject[i];
	}
}

int main()
{
	include obj[10];
	int choice,r;
	while(1)
	{
		cout<<"1. Enter details\n2.Delete\n3.Display\n4.Exit\n";
		cin>>choice;
		
		if(choice == 1)
		{
			cout<<"Enter roll number : ";
			cin>>r;
			obj[r].roll = r;
			obj[r].input();
		}
		else if( choice == 2)
		{
			cout<<"Enter roll number to be serched: ";
			cin>>r;
			obj[r].del();
			cout<<"details of  roll no  "<<r<<"are deleted\n";
		}
		else if(choice == 3)
		{
		 cout<<"Enter roll number : ";
			cin>>r;
			if(obj[r].roll != 0)
				obj[r].output();
			else
				cout<<"NO record of particualr roll no  exist"<<endl;
		}
		else if(choice == 4)
		{
			break;
		}
		else
		{
			cout<<"Wrong input";
		}
	}
}
