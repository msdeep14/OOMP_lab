//database
//mandeep singh @msdeep14
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
//#include<string>
using namespace std;
int key=0;
class database;

class process
{
	public:
	void sort(database a[],int key);
	int binary_search(database a[], char val[], int key);
	static void display(database a[], int key);
	void update(database a[]);
	void store(database a[]);
	void openInputFile(ifstream &inFile, string inFileName,database arr[], int SIZE);
	void search(database arr[],int key);
	void end_display()
	{
		cout<<"\n\n\t\tGOOD BYE!!!\n\n";
		cout<<"\t   A msdeep14 CREATION\n\n";
		exit(0);
	}
};

class database
{
	char name[20];
	char dob[12];
	char blood_group[6];
	int height;
	int weight;
	char contact_address[40];
	char telephone_no[12];
	char insurance_policy_no[12];
	char driving_licence_no[12];
	char uid[15];
	public:

	database();
	~database();
	friend class process;

};


database :: database()
{
	strcpy(name,"Mandeep");
	strcpy(dob,"14/08/1995");
	strcpy(blood_group,"B+ve");
	height=176;
	weight=72;
	strcpy(contact_address,"sikar");
	strcpy(telephone_no,"7769942097");
	strcpy(insurance_policy_no,"1234567898");
	strcpy(driving_licence_no,"9876543210");
	strcpy(uid,"654323456756");

}

database :: ~database()
{
	//destroy created object of class database;
}


void process :: search(database a[],int key)
{
	char tt[20], at[20];
	cout<<"Enter name of person to be searched\n";
	cin>>tt;
	cout<<"Enter uid no. of "<<tt<<"\n";
	cin>>at;
	int x=binary_search(a,at,key);
	int i=x;
	int ch,cp;
	if(x==-1)
	{
		cout<<"\nSorry!!!\nperson with given uid is not available in database!!!"<<endl;
	}
	else
	{
		cout<<"\n database details are::\n";
		cout<<"\nName IS                   :: "<<a[i].name;
		cout<<"\nDate of Birth IS          :: "<<a[i].dob;
		cout<<"\nUID no. is                :: "<<a[i].uid;
		cout<<"\nContact Address IS        :: "<<a[i].contact_address;
		cout<<"\nTelephone no. IS          :: "<<a[i].telephone_no;
		cout<<"\nBlood Group IS            :: "<<a[i].blood_group;
		cout<<"\nheight is                 :: "<<a[i].height;
		cout<<"\nweight is                 :: "<<a[i].weight;
		cout<<"\nInsurance policy no. is   :: "<<a[i].insurance_policy_no;
		cout<<"\nDriving Licence no. is    :: "<<a[i].driving_licence_no;

}
}

void process :: update(database a[])
{
	char tt[20],at[20];
	int sp=1,x;
	int flag=1;
	cout<<"\nEnter the name of person::\n";
	cin>>tt;
	while(flag)
	{
		cout<<"Enter the 12 digit uid of person::\n";
		cin>>at;
		if(strlen(at)==12)
		{
			flag=0;
			x=binary_search(a,at,key);
			if(x!=-1)
			{
				cout<<"\nEnter his new contact address:: \n";
				cin>>a[x].contact_address;
				while(sp)
				{
					cout<<"Enter his 10 digit new telephone no. :: "<<endl;
					cin>>a[x].telephone_no;
					if(strlen(a[x].telephone_no)==10)
					{
						sp=0;
					}
					else
					{
						cout<<"Please enter the correct 10 digit telephone_no\n\n";
					}
				}
				cout<<"Enter his new height in cm :: "<<endl;
				cin>>a[x].height;
				cout<<"Enter his new weight in kg :: "<<endl;
				cin>>a[x].weight;
				while(sp==0)
				{
					cout<<"Enter his new 10 digit insurance_policy_no :: "<<endl;
					cin>>a[x].insurance_policy_no;
					if(strlen(a[x].insurance_policy_no)==10)
					{
						sp=1;
					}
					else
					{
						cout<<"Please enter the correct 10 ditit insurance_policy_no\n\n";
					}
				}
				while(sp)
				{	
					cout<<"Enter his new 10 digit driving_licence_no :: "<<endl;
					cin>>a[x].driving_licence_no;
					if(strlen(a[x].driving_licence_no)==10)
					{
						sp=0;
					}
					else
					{
						cout<<"Please enter the correct 10 digit driving_licence_no\n\n";
					}
				}
				cout<<"\n Database of "<<a[x].name<<" is updated!!!\n\n";
				cout<<"New details of database are :: \n\n";
				cout<<"\nName                     :: "<<a[x].name;
				cout<<"\nDate of Birth            :: "<<a[x].dob;
				cout<<"\nUID no.                  :: "<<a[x].uid;
				cout<<"\nContact Address          :: "<<a[x].contact_address;
				cout<<"\nTelephone no.            :: "<<a[x].telephone_no;
				cout<<"\nBlood Group              :: "<<a[x].blood_group;
				cout<<"\nHEIGHT                   :: "<<a[x].height;
				cout<<"\nWEIGHT                   :: "<<a[x].weight;
				cout<<"\nInsurance policy no.     :: "<<a[x].insurance_policy_no;
				cout<<"\nDriving Licence no.      :: "<<a[x].driving_licence_no<<"\n\n";
				
				//////
				ofstream f;
				f.open("database_file.txt",ios:: trunc);
				
				for(int k=0;k<key;k++)
				{
					f<<a[k].name<<" ";
					f<<a[k].dob<<" ";
					f<<a[k].uid<<" ";
					f<<a[k].contact_address<<" ";
					f<<a[k].telephone_no<<" ";
					f<<a[k].blood_group<<" ";
					f<<a[k].height<<" ";
					f<<a[k].weight<<" ";
					f<<a[k].insurance_policy_no<<" ";
					f<<a[k].driving_licence_no<<" ";
					f<<"\n";
				}
				
				f.close();
			}
			else
			{
				cout<<"Entered UID no. doesnt exit in the database!!!\n\n";
			}
		}
		else
		{
			cout<<"\n\nPlease enter the correct 12 digit UID no.\n";
		}
	}

	
}

void process :: display(database a[],int key)
{
	int i;
	for(i=0;i<key;i++)
	{
		cout<<i+1<<".";
		cout<<"\nName                     :: "<<a[i].name;
		cout<<"\nDate of Birth            :: "<<a[i].dob;
		cout<<"\nUID no.                  :: "<<a[i].uid;
		cout<<"\nContact Address          :: "<<a[i].contact_address;
		cout<<"\nTelephone no.            :: "<<a[i].telephone_no;
		cout<<"\nBlood Group              :: "<<a[i].blood_group;
		cout<<"\nHEIGHT                   :: "<<a[i].height;
		cout<<"\nWEIGHT                   :: "<<a[i].weight;
		cout<<"\nInsurance policy no.     :: "<<a[i].insurance_policy_no;
		cout<<"\nDriving Licence no.      :: "<<a[i].driving_licence_no;
		cout<<"\n______________________________________________\n";
	}
}

int process :: binary_search(database a[], char val[],int key)
{
	int x,y;
    int mid;

    x = 0;
    y = key-1;

    while(x <= y)
    {
        mid = (x+y)/2;

        if(strcmp(val,a[mid].uid)==0)
        {
            return mid;
        }
        else if(strcmp(val,a[mid].uid)<0)
        {
            y = mid-1;
        }
        else if(strcmp(val,a[mid].uid)>0)
        {
            x = mid +1;
        }
    }

    return -1;
}

void process :: sort(database a[],int key)
{
	int i, j;
    database current;
    for(i = 1; i< key; i++)
    {
		current=a[i];
        for(j = i-1; j>=0; j--)
        {
            if(strcmp(current.uid,a[j].uid)<0)
			{
				a[j+1]=a[j];
			}
            else
                break;
        }
		a[j+1]=current;
    }
}

void process :: store(database a[])
{
	ofstream f;
	f.open("database_file.txt",ios:: app);
	int flag=1;
	
	cout<<"Enter name of person:\n";
	cin>>a[key].name;
	while(flag)
	{
		cout<<"Enter dob of person in format dd/mm/yyyy:\n";
		cin>>a[key].dob;
		if(strlen(a[key].dob)==10)
		{
			flag=0;
		}
		else
		{
			cout<<"Please enter the DOB in correct format :: dd/mm/yyyy\n\n";
		}
	}
	while(flag==0)
	{
		cout<<"Enter the 12 digit uid no. of the person::\n";
		cin>>a[key].uid;
		if(strlen(a[key].uid)==12)
		{
			flag=1;
		}
		else
		{
			cout<<"Please enter correct 12 digit UID no.\n\n";
		}
	}
		
	cout<<"Enter contact_address of the person:: \n";
	cin>>a[key].contact_address;
	while(flag)
	{
		cout<<"Enter 10 digit telephone_no of the person:: \n";
		cin>>a[key].telephone_no;
		if(strlen(a[key].telephone_no)==10)
		{
			flag=0;
		}
		else
		{
			cout<<"Please enter the correct 10 digit telephone_no\n\n";
		}
	}
	cout<<"Enter the blood_group no. of the person::\n";
	cin>>a[key].blood_group;
	cout<<"Enter the height of the person in cm::\n";
	cin>>a[key].height;
	cout<<"Enter the weight of the person in kg::\n";
	cin>>a[key].weight;
	while(flag==0)
	{
		cout<<"Enter the 10 digit insurance_policy_no of the person::\n";
		cin>>a[key].insurance_policy_no;
		if(strlen(a[key].insurance_policy_no)==10)
		{
			flag=1;
		}
		else
		{
			cout<<"Please enter correct 10 digit insurance_policy_no\n\n";
		}
	}	
	while(flag)
	{
		cout<<"Enter the 10 digit driving_licence_no of the person::\n";
		cin>>a[key].driving_licence_no;
		if(strlen(a[key].driving_licence_no)==10)
		{
			flag=0;
		}
		else
		{
			cout<<"Please enter the correct 10 digit driving_licence_no\n\n";
		}
	}
	f<<"\n"<<a[key].name<<" ";
	f<<a[key].dob<<" ";
	f<<a[key].uid<<" ";
	f<<a[key].contact_address<<" ";
	f<<a[key].telephone_no<<" ";
	f<<a[key].blood_group<<" ";
	f<<a[key].height<<" ";
	f<<a[key].weight<<" ";
	f<<a[key].insurance_policy_no<<" ";
	f<<a[key].driving_licence_no<<" ";
	f.close();
}

void process :: openInputFile(ifstream &inFile, string inFileName,database arr[], int SIZE)
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
        inFile >> arr[count].name >> arr[count].dob >> arr[count].uid >> arr[count].contact_address >> arr[count].telephone_no >> arr[count].blood_group >> arr[count].height >> arr[count].weight >> arr[count].insurance_policy_no >> arr[count].driving_licence_no;
    }

	inFile.close();

	}
}

int main()
{
	int chhh,ch,hh,flag;
	database b;
	process p;
	int SIZE=1;
	char tt[20];
	FILE *infile=fopen("database_file.txt","r");
	int c;
	
	while(EOF!=(c=getc(infile)))
	{
		if('\n'==c)
			SIZE++;
	}
	
	ifstream inFile;
    string inFileName = "database_file.txt";
	database *arr;
	arr=new database[1000];
	p.openInputFile(inFile, inFileName.c_str(),arr,SIZE);

	key=SIZE;
	p.sort(arr,key);
	do
	{
		cout<<"\nEnter choice::\n1.display database\n2.update the database\n3.search for a person\n4.exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				process::display(arr,key);
				break;
			case 2:
				cout<<"\nDo you want to update\n1.existing database of a person\n2.Add a new person to database\n";
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
			case 3:
				p.search(arr,key);
				break;
			case 4:
				p.end_display();
				break;
			default:
				cout<<"You had entered the wrong choice!!!\n\n";
				break;
		}
		cout<<"\n\nDo you wish to continue???\nEnter 1 to continue!!!\n";
		cin>>flag;
		if(flag!=1)
		{
			p.end_display();
		}
	}while(flag==1);
	delete arr;
	return 0;
}
