//============================================================================
// Name        : cppp.cpp
// Author      : Mandeep Singh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class weather;
class print
{
public:
	 void display_report(weather arr[]);
     void calculate_avg(weather arr[]);
};
class weather
{
	int day_of_month;
	int high_temp;
	int low_temp;
	int amount_rain;
	int amount_snow;

public:
	friend void print :: display_report(weather arr[] );
	friend void print :: calculate_avg(weather arr[]);
	weather enter_data();

	weather();
};



void print :: calculate_avg(weather arr[])
{
		float av_lt=0;
		float av_ht=0;
		float av_ar=0;
		float av_as=0;
		for(int i=0;i<31;i++)
		{
			av_lt+=arr[i].low_temp;
			av_ht+=arr[i].high_temp;
			av_ar+=arr[i].amount_rain;
			av_as+=arr[i].amount_snow;
		}
		cout<<"average:: \n"<<endl;
		cout<<"high_temp\tlow_temp\tamount_rain\tamount_snow\n\n";
		cout<<(av_ht/31)<<"\t\t"<<(av_lt/31)<<"\t\t"<<(av_ar/31)<<"\t\t"<<(av_as/31)<<"\n\n";
}

weather :: weather()
{
	day_of_month=99;
    high_temp=999;
	low_temp=-999;
	amount_rain=0;
    amount_snow=0;
}
void print :: display_report(weather arr[])
{
	int ch;
	int day;
	cout<<"do you want to display\n1.monthly report\n2.daily report\n\n";
	cin>>ch;
	if(ch==1)
	{
	cout<<"report of month is:: "<<endl;
	cout<<"\nday\thigh_temp\tlow_temp\tamount_rain\tamount_snow\n\n";
	for(int i=1;i<=31;i++)
	{
		cout<<i<<"\t"<<arr[i-1].high_temp<<"\t\t"<<arr[i-1].low_temp<<"\t\t"<<arr[i-1].amount_rain<<"\t\t"<<arr[i-1].amount_snow<<"\n\n";
	}
	calculate_avg(arr);
	}
	else if(ch==2)
	{
		cout<<"enter the day of which you want to display report:: \n";
		cin>>day;
		cout<<"\nday\thigh_temp\tlow_temp\tamount_rain\tamount_snow\n\n";
		cout<<day<<"\t"<<arr[day-1].high_temp<<"\t\t"<<arr[day-1].low_temp<<"\t\t"<<arr[day-1].amount_rain<<"\t\t"<<arr[day-1].amount_snow<<"\n\n";
	}

}



weather weather :: enter_data()
{
	int date;
	int ht;
	int lt;
	int ar;
	int as;
	weather w1;
	cout<<"enter high temp:: "<<endl;
	cin>>ht;
	cout<<"enter low temp ::"<<endl;
	cin>>lt;
	cout<<"enter amount of rain :: "<<endl;
	cin>>ar;
	cout<<"enter amount of snow :: "<<endl;
	cin>>as;
	w1.high_temp=ht;
	w1.low_temp=lt;
	w1.amount_rain=ar;
	w1.amount_snow=as;
	return w1;


}


int main() {
	weather arr[31];
	weather w;
	print p;
	int ch,flag;
	int day;
		do
		{
		cout<<"menu:: \n1.enter data\n2.display report"<<endl;
		cout<<"enter choice :: "<<endl;
		cin>>ch;
		if(ch==1)
		{
			cout<<"enter the day";
			cin>>day;
			arr[day-1]=w.enter_data();
		}

		else if(ch==2)
		{
			p.display_report(arr);
		}
		else
		{
			cout<<"You had entered the wrong choice!!"<<endl;
		}
		cout<<"do you wish to continue?? \nenter 1 to contiue//"<<endl;
		cin>>flag;

		}while(flag==1);



	return 0;
}

