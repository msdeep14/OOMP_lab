#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
list<int> ::iterator itr;
 list <int > l;
 list<int> l1;
istream & clearStream(istream &in)
{
    if(in.fail())
    {
        in.clear();
        in.ignore(1000,'\n');
    }
    return in;
}
class container
{
   
public:
    void list_empty();
    void list_insert();
    void list_display();
    void list_merge();
    void list_reverse();
    void list_sort();
    void max_list();
    void min_list();
    void count_list();
    void clear_list();
    void find_list();
	void  unique1();
	//void sort1();
};



void container :: find_list()
{
    cout<<"ENter value to search ::";
    int c;
    cin>>c;
    itr = find(l.begin(),l.end(),c);
    if(itr != l.end())
        cout<<"found";
    else
        cout<<"not found";
}
void container :: unique1()
{
    l.unique();
}


void container :: clear_list()
{
    l.clear();
}
void container ::count_list()
{
    int c = 0;
    itr = l.begin();
    while(itr++ != l.end())
        c++;
    cout<<c;

}
void container :: max_list()
{
    itr = max_element(l.begin(),l.end());
    cout<<*itr;
}
void container ::min_list()
{
    itr = min_element(l.begin(),l.end());
    cout<<*itr;
}

void container :: list_insert()
{
    int val;
    int ch;
    cout<<"Enter value to insert in list ";
    cin>>val;
    cout<<"1.at front 2.at back :: ";
    cin>>ch>>clearStream;
    if(ch == 1)
        l.push_front(val);
    else if(ch == 2)
        l.push_back(val);

}
void container :: list_empty()
{
    int val =l.empty();
    if( val == 1)
        cout<<"list is empty "<<endl;
    else if (val == 0)
        cout<<"list is not empty "<<endl;
}
void container :: list_merge()
{
    
    int val,s,i;
    cout<<"Enter size of new list you want to merge in list 1 :: ";
    cin>>s;
    for(i=0;i<s;i++)
    {
        cin>>val;
        l1.push_back(val);
    }
    l.merge(l1);
}

void container :: list_reverse()
{
    reverse(l.begin(),l.end());
}

void container :: list_sort()
{
    l.sort();
}

void container :: list_display()
{

    for(itr = l.begin();itr != l.end();itr++)
        cout<<*itr<<" ";

}
void min()
{
	itr=min_element(l.begin(),l.end());
	cout<<"min elment is:: "<<*itr;
}
void menu()
{
    cout<<"1.insert \n2.empty \n3.merge \n4.reverse \n5.sort \n6.display \n 7.find maximum \n8.find minimum \n9.size of list"
    "\n10.clear\n11.find\n12.unique\n13.exit15.freqency count 16.swap17.resize 18.assign"<<endl;
}
/*
void sort()
{
	itr=sort(l.begin(),l.end());
}
*/
void coun()
{
	int x;
	cout<<"ener frequency for nu.";
	cin>>x;
	cout<<count(l.begin(),l.end(),x)<<endl;
}

int main()
{
    container mylist;
    int ch;
	int size=0;
    do
    {
        menu();
        cin>>ch>>clearStream;
        switch(ch)
        {
       case 1:
            mylist.list_insert();
            cout<<endl;
            break;
       case 2:
           mylist.list_empty();
           cout<<endl;
           break;
       case 3:
            mylist.list_merge();
            cout<<endl;
            break;
       case 4:
           mylist.list_reverse();
           cout<<endl;
           break;
       case 5:
            mylist.list_sort();
            cout<<endl;
            break;

       case 6:
            mylist.list_display();
            cout<<endl;
            break;
       case 7:
           mylist.max_list();
           break;
       case 8:
            mylist.min_list();
            break;
       case 9:
            mylist.count_list();
            break;
       case 10:
            mylist.clear_list();
            break;
       case 11:
            mylist.find_list();
            break;
		case 12:
			mylist.unique1();
			break;
		case 14:
			//mylist.sort1();
			//sort();
			break;
       case 15:
			coun();
			break;
       case 13:
            break;
		case 16:
		l.swap(l1);
		break;
		case 17:
		cout<<"enter new size:";
		cin>>size;
		l.resize(size);
		break;
		case 18:
			cout<<"enter new value to assign";
			cin>>size;
			l.assign(10,size);
			break;
        }
    cout<<endl;
    }while(ch != 13);

}
