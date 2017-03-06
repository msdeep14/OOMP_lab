//vector
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
template <class t> class vector
{
	t data[1000];
	int size;
	public:
	void create();
	void display();
	void modify();
	void multiply();
	void push_back();
	void pop_back();
	void delete1();
	void delete_specific();
	void shift_pos();
	void search();
	void top();
};

template <class t> void vector<t> :: shift_pos()
{
	int ind;
	t val;
	cout<<"enter post ot shfit\n";
	cin>>ind;
	cout<<"enter new val of pos\n";
	cin>>val;
	//t temp=data[ind];

	for(int i= size-1;i>=ind;i--)
	{
		data[i+1]=data[i];
	}
		data[ind]=val;
	//data[ind+1]=temp;
	size++;
}

template <class t> void vector<t> :: delete_specific()
{
	int ind;
	cout<<"enter the index no of element to be deleted:: "<<endl;
	cin>>ind;
	for(int i=ind;i<size;i++)
	{
		data[i]=data[i+1];
	}
	size--;
}

template <class t> void vector<t> :: push_back()
{
	t val;
	cout<<"enter the value to be pushed:: \n";
	cin>>val;
	data[size++]=val;
}

template <class t> void vector <t> :: pop_back()
{
	cout<<"popped element is :: "<<data[size-1];
	size--;
}

template <class t > void vector<t> :: top()
{
	cout<<"topmost value of formed vector is:: \n";
	cout<<data[size-1];
}

template <class t> void vector <t>:: delete1()
{
	size=0;
}

template <class t>void vector <t> :: search()
{
	t val;
	int flag=0;
	cout<<"enter value to be searched :: \n";
	cin>>val;
	for(int i=0;i<size;i++)
	{
		if(val==data[i])
		{
			flag=1;
			cout<<"value found at index "<<i<<endl;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"value not found!!!\n";
	}
}


template <class t> void vector <t>:: multiply()
{
	t val;
	cout<<"enter the scalar value to be multiplied with:: "<<endl;
	cin>>val;
	for(int i=0;i<size;i++)
	{
		data[i]=val*data[i];
	}
}

template <class t> void vector <t>:: modify()
{
	int ind;
	t val;
	cout<<"enter index no. to be modified\n";
	cin>>ind;
	cout<<"prev val on this index is :: "<<data[ind]<<endl;
	cout<<"enter the new value\n";
	cin>>val;
	data[ind]=val;
}

template <class t> void vector<t> :: display()
{
	cout<<"( ";
	for(int i=0;i<size;i++)
	{
		cout<<data[i]<<", ";
	}
	cout<<")\n";
}

template<class t> void vector<t> :: create()
{
	cout<<"enter size of vector to be created::\n";
	cin>>size;
	cout<<"enter data for given size of vector\n";
	for(int i=0;i<size;i++)
	{
		cin>>data[i];
	}
}

template <class t> void menu(t a)
{
	vector <t> v;
		int ch;
	int flag=1;
	while(flag==1)
	{
		cout<<"enter choice::\n1.create\n2.display\n3.modify value\n4.multiply by aa scalar value\n5.push_back\n6.pop_back\n7.delete1\n8.search\n9.top\n10.delete specific\n11.shift_pos\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			v.create();
			break;
		case 2:
			v.display();
			break;
		case 3:
			v.modify();
			break;
		case 4:
			v.multiply();
			break;
		case 5:
			v.push_back();
			break;
		case 6:
			v.pop_back();
			break;
		case 7:
			v.delete1();
			break;
		case 8:
			v.search();
			break;
		case 9:
			v.top();
			break;
		case 10:
			v.delete_specific();
			break;
		case 11:
			v.shift_pos();
			break;
	}
		cout<<"enter 1 to continue\n";
		cin>>flag;
	}
}

int main()
{
	
    int ch;
    
    do
    {
        cout<<"\n 1. vect0r of int ";
        cout<<"\n 2. vector of char ";
        cout<<"\n 3. vecotr of double ";
        cout<<"\n 4. exit";
        cout<<"\n Enter Choice ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                int q;
                menu(q);
                break;
            case 2:
                char w;
                menu(w);
                break;
            case 3:
                double e;
                menu(e);
                break;
            case 4:
                break;
            default :
                cout<<"\n wrong choice";
                break;
        }
       
    }while(ch != 4);

	
		

	return 0;
}