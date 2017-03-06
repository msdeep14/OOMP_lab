#include <iostream>
#include<bits/stdc++.h>
#define m 3
using namespace std;

template<class type> void input_data(type mat[m][3] )
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cin>>mat[i][j];
	}
}
template<class type>void transpose(type mat[m][3])
{
 int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			cout<<mat[j][i]<<" \n"[j == 2];
}

template<class x>void addition(x mat1[m][3], x mat2[m][3])
{
 int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			cout<<mat1[i][j]+mat2[i][j]<<" \n"[j == 2];
}

template<class x>void subtraction(x mat1[m][3], x mat2[m][3])
{
 int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			cout<<mat1[i][j]-mat2[i][j]<<" \n"[j == 2];
}

template<class x> void determinant(x mat[m][3])
{
	int val = 0;
	val += mat[0][0]*(mat[1][1]*mat[2][2] - mat[2][1]*mat[1][2]) - mat[0][1]*(mat[1][0]*mat[2][2] - mat[2][0]*mat[1][2])+
			mat[0][2]*(mat[1][0]*mat[2][1] - mat[2][0]*mat[1][1]);
	cout<<val<<endl;
}
template<class x>void multiplication(x mat1[m][3], x mat2[m][3])
{
 int i,j,k;
 double val;
	for(i=0;i<3;i++)
	{
		k =0;
	  while(k < 3)
	  {
		  val = 0;
		  for(j=0;j<3;j++)
			val += mat1[i][j]*mat2[j][k];
		cout<<val<<" ";
		k++;
	  }
	cout<<endl;
	}

}



int main()
{

	int mat1[3][3];
	int mat2[3][3];
	float mat3[3][3];
	float mat4[3][3];
	int chh;
	cout<<"enter type of matrix \n1.int\n2.float\n";
	cin>>chh;
	if(chh==1)
	{
		cout<<"Enter matrix 1 "<<endl;
	input_data(mat1);

	cout<<"Enter matrix 2 "<<endl;
	input_data(mat2);
	
	int ch,choice;

	do
	{
		cout<<"Enter choice :: "<<endl;
		cout<<" \n1.transpose matrix\n2.addition  \n3.subtraction \n4.multiplication \n5.determinant of matrix 1 \n6.exit ";

		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"Transpose matrix 1 :: "<<endl;
			transpose(mat1);
			cout<<endl;
			cout<<"Transpose matrix 2:: "<<endl;
			transpose(mat2);
			cout<<endl;
			break;
		
		case 2:
			cout<<"\nAddition :: "<<endl;
			addition(mat1, mat2);
			break;
		case 3:
			cout<<"\nSubtraction :: "<<endl;
			subtraction(mat1,mat2);
			break;
		case 4:
			cout<<"\nMultiplication :: "<<endl;
			multiplication(mat1,mat2);
			break;
		case 5:
			cout<<"\nDeterminant matrix 1 :: "<<endl;
			determinant(mat1);
			cout<<endl;
			cout<<"\nDeterminant matrix2:: "<<endl;
			determinant(mat2);
			cout<<endl;
			break;
		case 6:
			exit(0);
			break;
		
		}
	}while(ch != 6);
	}
	else if(chh==2)
	{
		cout<<"Enter matrix 1 "<<endl;
	input_data(mat3);

	cout<<"Enter matrix 2 "<<endl;
	input_data(mat4);
	
	int ch,choice;

	do
	{
		cout<<"Enter choice :: "<<endl;
		cout<<" \n1.transpose matrix\n2.addition  \n3.subtraction \n4.multiplication \n5.determinant of matrix 1 \n6.exit ";

		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"Transpose matrix 1 :: "<<endl;
			transpose(mat3);
			cout<<endl;
			cout<<"Transpose matrix 2:: "<<endl;
			transpose(mat4);
			cout<<endl;
			break;
		
		case 2:
			cout<<"\nAddition :: "<<endl;
			addition(mat3, mat4);
			break;
		case 3:
			cout<<"\nSubtraction :: "<<endl;
			subtraction(mat3,mat4);
			break;
		case 4:
			cout<<"\nMultiplication :: "<<endl;
			multiplication(mat3,mat4);
			break;
		case 5:
			cout<<"\nDeterminant matrix 1 :: "<<endl;
			determinant(mat3);
			cout<<endl;
			cout<<"\nDeterminant matrix2:: "<<endl;
			determinant(mat4);
			cout<<endl;
			break;
		case 6:
			exit(0);
			break;
		
		}
	}while(ch != 6);

	}

	return 0;
}
