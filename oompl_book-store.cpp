//book store oompl
//mandeep singh @msdeep14
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int key=0;
class book;

class process
{
	public:
	void sort(book a[],int key);
	void inquiry();
	int binary_search(book a[], char val[], int key);
	void display(int key);
	void update();
};

class book
{
	char author[20];
	char title[20];
	int price;
	char publisher[20];
	int stock_position;
	public:
	void store();
	book();
	friend void process :: sort(book a[],int key);
	friend void process :: inquiry();
	friend int process :: binary_search(book a[],char val[], int key);
	friend void process :: display(int key);
	friend void process :: update();
}a[1000];


book :: book()
{
	strcpy(author,"Mandeep");
	strcpy(title,"Zindagi");
	price=999;
	strcpy(publisher,"Heyy Publishers");
	stock_position=0;
}

void process :: update()
{
	char tt[20],at[20];
	int sp;
	cout<<"\nEnter the title of the book::\n";
	cin>>tt;
	cout<<"Enter the author of the book::\n";
	cin>>at;
	int x=binary_search(a,tt,key);
	cout<<"\nEnter the new stock position of the book::\n";
	cin>>sp;
	a[x].stock_position+=sp;
}

void process :: display(int key)
{
	int i;
	for(i=0;i<key;i++)
	{	
		cout<<i+1<<".";
		cout<<"\nTITLE IS           :: "<<a[i].title;
		cout<<"\nAUTHOR NAME IS     :: "<<a[i].author;
		cout<<"\nPRICE IS           :: "<<a[i].price;
		cout<<"\nPUBLISHER IS       :: "<<a[i].publisher;
		cout<<"\nSTOCK POSITION	IS :: "<<a[i].stock_position;
		cout<<"\n______________________________________________\n";
	}
}

int process :: binary_search(book a[], char val[],int key)
{
	int x,y;
    int mid;
    
    x = 0; 
    y = key-1;
    
    while(x <= y)
    {
        mid = (x+y)/2;
        
        if(strcmp(val,a[mid].title)==0)
        {
            return mid;
        }
        else if(strcmp(val,a[mid].title)<0)
        {
            y = mid-1;
        }
        else if(strcmp(val,a[mid].title)>0)
        {
            x = mid +1;
        }
    }
    
    return -1; 
}

void process :: sort(book a[],int key)
{
	int i, j;
    book current;
    for(i = 1; i< key; i++)
    {
        strcpy(current.author,a[i].author);
		strcpy(current.title,a[i].title);
		current.price=a[i].price;
		strcpy(current.publisher,a[i].publisher);
		current.stock_position=a[i].stock_position;
        for(j = i-1; j>=0; j--)
        {
            if(strcmp(current.title,a[j].title)<0)
			{   
				strcpy(a[j+1].author,a[j].author);
				strcpy(a[j+1].title,a[j].title);
				a[j+1].price = a[j].price;
				strcpy(a[j+1].publisher,a[j].publisher);
				a[j+1].stock_position = a[j].stock_position;
			}
            else
                break;
        }
        strcpy(a[j+1].author,current.author); 
		strcpy(a[j+1].title,current.title);
		a[j+1].price=current.price;
        strcpy(a[j+1].publisher,current.publisher);
        a[j+1].stock_position=current.stock_position;
    }
}

void process :: inquiry()
{
	int cp,ch,chh;
	char at[20],tt[20];
	cout<<"Enter title of the book:: \n";
	cin>>tt;
	cout<<"Enter author name:: \n";
	cin>>at;
	int x=binary_search(a,tt,key);
	int i=x;
	if(x==-1)
	{
		cout<<"\nSORRY!!!\nRequested book is not available.\n";
	}
	else if(a[x].stock_position<=0)
	{
		cout<<"\nSorry!!!\nThis book is out of stock\n\n";
	}
	else
	{
		cout<<"\nThe book you want to purchase is :: \n\n";
		cout<<"\nTITLE IS           :: "<<a[i].title;
		cout<<"\nAUTHOR NAME IS     :: "<<a[i].author;
		cout<<"\nPRICE IS           :: "<<a[i].price;
		cout<<"\nPUBLISHER IS       :: "<<a[i].publisher;
		cout<<"\nSTOCK POSITION	IS  :: "<<a[i].stock_position;
		cout<<"\n\nHow much copies of the book you require??"<<endl;
		cin>>cp;
		if(cp<=a[i].stock_position)
		{
			cout<<"Thanks for purchasing!!!\n";
			cout<<"Your total cost is Rs."<<(cp*a[i].price)<<"\n\n";
			a[i].stock_position-=cp;
			cout<<"Would you wish buy some other books\nEnter 1 to continue!!!\n";
			
			cin>>chh;
			if(chh==1)
			{
				inquiry();
			}
		}
		else 
		{
			cout<<"SORRY!!!\n";
			cout<<"Required no. of copies are not available\n\n";
			cout<<"Total no. of copies for this book available are "<<a[i].stock_position<<"\n\n";
			cout<<"Would you wish to buy less no. of copies??\nEnter 1 to contiue!!!\n";
			cin>>ch;
			if(ch==1)
			{
				//inquiry();
				cout<<"Enter the no. of copies:: \n";
				cin>>cp;
				if(cp<=a[i].stock_position)
				{
					cout<<"Thanks for purchasing!!!\n";
			cout<<"Your total cost is Rs."<<(cp*a[i].price)<<"\n\n";
			a[i].stock_position-=cp;
			cout<<"Would you wish buy some other books\nEnter 1 to continue!!!\n";
			
			cin>>chh;
			if(chh==1)
			{
				inquiry();
			}
				}
			}
		}
	}
}

void book :: store()
{
	ofstream f;
	f.open("file.txt",ios:: app);
	//a=new book();
	
	cout<<"Enter author name:\n";
	cin>>a[key].author;
	cout<<"Enter title of the book::\n";
	cin>>a[key].title;
	cout<<"Enter the price of the book::\n";
	cin>>a[key].price;
	cout<<"Enter the name of publisher of the book:: \n";
	cin>>a[key].publisher;
	cout<<"Enter stock position of the book:: \n";
	cin>>a[key].stock_position;
	
	f<<a[key].author<<" ";
	f<<a[key].title<<" ";
	f<<a[key].price<<" ";
	f<<a[key].publisher<<" ";
	f<<a[key].stock_position<<" ";
	f<<"\n";
	
	f.close();
	
	key++;
}

int main()
{
	book b;
	process p;
	int chhh;
	cout<<"Enter 1 to update the stock::\n";
	cin>>chhh;
	while(chhh==1)
	{
		b.store();
		cout<<"Enter 1 to store more books::\n";
		cin>>chhh;
	}
	p.sort(a,key);
	int flag;
	int ch,hh;
	do
	{
		cout<<"\nEnter choice::\n1.purchase\n2.display book list\n3.update the stock\n4.exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				p.inquiry();
				break;
			case 2:
				p.display(key);
				break;
			case 3:
				cout<<"\nDo you want to update\n1.existing stock of books\n2.Add a new book to stock\n";
				cin>>hh;
				if(hh==1)
				{
					p.update();
				}
				else 
					b.store();
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<"You had entered the wrong choice!!!\n\n";
				break;
		}
		cout<<"Do you wish to continue???\nEnter 1 to continue!!!\n";
		cin>>flag;
	}while(flag==1);
	
	return 0;
}