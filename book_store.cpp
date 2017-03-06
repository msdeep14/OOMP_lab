//book store oompl
//mandeep singh @msdeep14
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int key=0;
class book;

class process
{
	public:
	void sort(book a[],int key);
	void inquiry(book a[]);
	int binary_search(book a[], char val[], int key);
	void display(book a[], int key);
	void update(book a[]);
	void store(book a[]);
	void openInputFile(ifstream &inFile, string inFileName,book arr[], int SIZE);
	void search(book arr[],int key);
};

class book
{
	char author[20];
	char title[20];
	int price;
	char publisher[20];
	int stock_position;
	public:
	
	book();
	friend class process;
};


book :: book()
{
	strcpy(author,"Mandeep");
	strcpy(title,"Zindagi");
	price=999;
	strcpy(publisher,"Heyy Publishers");
	stock_position=0;
}


void process :: search(book a[],int key)
{
	char tt[20];
	cout<<"Enter title of the book to be searched\n";
	cin>>tt;
	int x=binary_search(a,tt,key);
	int i=x;
	int ch,cp;
	if(x==-1)
	{
		cout<<"\nSorry!!!\nBook not available in stock!!!"<<endl;
	}
	else 
	{
		cout<<"\nBook available in stock!\n";
		cout<<"\n Book details are::\n";
		cout<<"\nTITLE IS           :: "<<a[i].title;
		cout<<"\nAUTHOR NAME IS     :: "<<a[i].author;
		cout<<"\nPRICE IS           :: "<<a[i].price;
		cout<<"\nPUBLISHER IS       :: "<<a[i].publisher;
		cout<<"\nSTOCK POSITION	IS :: "<<a[i].stock_position;
		cout<<"\n\nWould you like to purchase this book??\nEnter 1 to continue.\n";
		cin>>ch;
		if(ch==1)
		{
			cout<<"\n\nHow much copies of the book you require??"<<endl;
			cin>>cp;
			if(cp<=a[i].stock_position)
			{
			cout<<"Thanks for purchasing!!!\n";
			cout<<"Your total cost is Rs."<<(cp*a[i].price)<<"\n\n";
			a[i].stock_position-=cp;
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
				}
			}
	}
	}
}
}

void process :: update(book a[])
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

void process :: display(book a[],int key)
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

void process :: inquiry(book a[])
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
				inquiry(a);
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
				inquiry(a);
			}
				}
			}
		}
	}
}

void process :: store(book a[])
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
	
	f<<"\n"<<a[key].author<<" ";
	f<<a[key].title<<" ";
	f<<a[key].price<<" ";
	f<<a[key].publisher<<" ";
	f<<a[key].stock_position<<" ";
	f.close();
}

void process :: openInputFile(ifstream &inFile, string inFileName,book arr[], int SIZE)
{
    inFile.open(inFileName.c_str());
    if (!inFile)
    {
        cout << "Error to open file." << endl;
        cout << endl;
        return;
    }
	else
	{
		for(int count = 0; count < SIZE; count++)
    {
        inFile >> arr[count].author >> arr[count].title >> arr[count].price >> arr[count].publisher >> arr[count].stock_position; 
    }
	
	inFile.close();
	
	}
}

int main()
{
	int chhh,ch,hh,flag;
	book b;
	process p;
	int SIZE=1;
	char tt[20];
	FILE *infile=fopen("file.txt","r");
	int c;
	while(EOF!=(c=getc(infile)))
	{
		if('\n'==c)
			SIZE++;
	}
	
	ifstream inFile; 
    string inFileName = "file.txt"; 
	book *arr;
	arr=new book[1000];
	p.openInputFile(inFile, inFileName.c_str(),arr,SIZE);
	
	key=SIZE;
	p.sort(arr,key);
	do
	{
		cout<<"\nEnter choice::\n1.purchase\n2.display book list\n3.update the stock\n4.search for a book\n5.exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				p.inquiry(arr);
				break;
			case 2:
				p.display(arr,key);
				break;
			case 3:
				cout<<"\nDo you want to update\n1.existing stock of books\n2.Add a new book to stock\n";
				cin>>hh;
				if(hh==1)
				{
					p.update(arr);
				}
				else 
				{
					p.store(arr);
					SIZE++;
					key++;
					p.sort(arr,key);
				}
				break;
			case 4:
				p.search(arr,key);
				break;
			case 5:
				exit(0);
				break;
			default:
				cout<<"You had entered the wrong choice!!!\n\n";
				break;
		}
		cout<<"Do you wish to continue???\nEnter 1 to continue!!!\n";
		cin>>flag;
	}while(flag==1);
	delete arr;
	return 0;
}