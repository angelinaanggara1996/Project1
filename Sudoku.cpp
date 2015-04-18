#include "Sudoku.h"
#include<fstream>
#include <cstdlib>
#include <ctime>
#include<cstring>
#include <iostream>
using namespace std;
int Sudoku::myQ[12][12]={{4, 2, 6, 8, 7, 3, 9, 5, 1, -1, -1, -1},
				 		 {8, 7, 3, 9, 5, 1, 6, 2, 4, -1, -1, -1},
				 		 {9, 5, 1, 6, 2, 4, 8, 7, 3, -1, -1, -1},
						 {-1, -1, -1, 1, 3, 2, 4, 8, 7, 9, 5, 6},
						 {-1, -1, -1, 7, 8, 5, 1, 9, 6, 4, 2, 3},
						 {-1, -1, -1, 4, 9, 6, 2, 3, 5, 8, 7, 1},
						 {1, 3, 7, 2, 4, 8, -1, -1, -1, 6, 9, 5},
						 {2, 8, 4, 5, 6, 9, -1, -1, -1, 1, 3, 7},
						 {6, 9, 5, 3, 1, 7, -1, -1, -1, 2, 8, 4},
					 	 {3, 1, 2, -1, -1, -1, 7, 4, 8, 5, 6, 9},
						 {7, 4, 8, -1, -1, -1, 5, 6, 9, 3, 1, 2},
						 {5, 6, 9, -1, -1, -1, 3, 1, 2, 7, 4, 8}};
//GiveQuestion
void Sudoku::GiveQuestion()
{
	int tmp=0;
	int z=25;
	srand(time(NULL));
	int x=rand()%1;
	int y=rand()%1+2;
	randomRow(x,y);
	while(tmp<z){
		int a=rand()%12;
		int b=rand()%12;
		if(myQ[a][b]==0 || myQ[a][b]==-1) continue;
		else 
			myQ[a][b]=0;
			++tmp; 
	}
	for(int i=0;i<12;++i){
		for(int j=0;j<12;++j){
			cout<<myQ[i][j]<<" ";
		}
		cout<<endl;
	}
}

//randoming the give question row
void Sudoku::randomRow(int a, int b)
{
	for(int i=a*3,x=0,y=b*3;x<3; ++i,++x,++y){
		for(int j=0;j<12;++j){
			int tmp=myQ[i][j];
			myQ[i][j]=myQ[y][j];
			myQ[y][j]=tmp;
		}
	}
}
void Sudoku::Random()
{
	int i,j,k,a,a1,a2,s1[12],s2[12],ap[144];
	srand(time(NULL));
	a=rand()%5; //choose the order random
	ifstream in("Q.txt",ios::in);
	ofstream out("file.out",ios::out);
	if(a==0)
		for(int i=0;i<144;++i)
				in>>ap[i];
	if(a==1)
		for(int i=143;i>=0;--i)
				in>>ap[i];
	if(a==2)
		for(int i=0;i<12;++i)//from the left to the right
				for(j=i;j<144;j+=12)
					in>>ap[j];
	if(a==3)
		for(int i=11;i>=0;--i)//from up to down,left to right
				for(j=i;j<144;j=j+12)
					in>>ap[j];
	if(a==4)
		for(int i=11;i<144;i=i+12)
				for(j=i;j>=(i-11);j--)
					in>>ap[j];
	for (k=0;k<4;++k)
	{
		for(int i=0;i<12;++i)
			s1[i]=-1;
		for(int i=0;i<12;++i)
			s2[i]=-1;
		a1=rand()%9+1;
		do
		{
			a2=rand()%9+1;
		}while(a1==a2);
		int j=0;
		for(int i=0;i<144;++i)
		{	
				if(ap[i]==a1)
				{
					s1[j]=i;
					j++;
				}
		}
		for(int i=0;i<144;++i)
		{
				if(ap[i]==a2)
				{
					s2[j]=i;
					j++;
				}
		}
		for(int i=0;i<12;i++)
				if(s1[i]!=(-1)) ap[s1[i]]=a2;
		for(int i=0;i<12;++i)
				if(s2[i]!=(-1)) ap[s2[i]]=a1;
	}
	for(int i=0;i<144;i++)
	{
			out<<ap[i]<<" ";
		if(i%12==11)
			out<<endl;
	}
}
//Check whether it is solvable or not
/*void Sudoku::Check()
{
	if (!sol) cout<<0<<endl;
	else if (!ex){
		cout<<1<<endl;
		for(int i=0;i<12;++i)
		{
			for(int j=0;j<12;++j)
				cout<<Ques[i][j]<<" ";
			cout<<endl;
		}
	}
	else 
		cout<<2<<"\n";
}*/
//checking the row number is from 1 to 9
bool Sudoku::row(int i, int j, int k)
{
	for (int a=0;a<12;++a)
	{
		if(Ques[i][a]==k)return false;
	}
	return true;
}
//checking the column number is from 1 to 9 or not
bool Sudoku::col(int i,int j, int k)
{
	for(int a=0;a<12;++a)
	{
		if(Ques[a][j]==k) return false;
	}
	return true;
}
//checking the 3X3 cube is having the number 1 to 9 or not
bool Sudoku::cube(int i,int j, int k)
{
	int m=i-(i%3), n=j-(j%3);
	for (int h=0;h<3;++h)
	{
		for(int g=0;g<3;++g)
		{
			if(Ques[m+h][n+g]==k) return false;
		}
	}
	return true;
}
//read other people question
void Sudoku::ReadIn()
{
	/*for(int i=0; i<12;++i){
		for(int j=0; j<12; ++j){
			cin>>Ques[i][j];			
		}
	}*/
	ifstream in("Q.txt",ios::in);
	for(int i=0;i<12;++i){
		for(int j=0;j<12;++j){
			in>>Ques[i][j];
		}
	}
	in.close();
}
//solving the question
void Sudoku::Solve()
{
	bool sol= true;
	int zero=0,x=0,tmp;
	for(int l=0;l<2;l++)
	{
		while(zero && sol)
		{
			sol=false;
			for(int i=0; i<12; i++){
				for(int j=0; j<12; j++){
					if(Ques[i][j]!=0) continue;
					tmp=0;
					for(int n=1 ;n<10;n++){
						if(row(i,j,n) && col(i,j,n) && cube(i,j,n))
						{
							if(tmp==0) tmp=n;
							else {
								tmp=0;
								break;
							}
						}
						break;
					}
					if(tmp!=0){
						Ques[i][j]=tmp;
						sol=true;
						zero--;
					}
				}
			}
		}
		for(int i=0; i<12;i++){
			for(int j=0; j<12;j++){
				if(!x){
					ans[i][j]==Ques[i][j];
				}
			}
		}
	}
	for(int i=0;i<12;++i){
		for(int j; j<12;++j){
			if(Ques[i][j]!=ans[i][j]){
				zero=2;
				break;
			}
		}
	}	
	if (!sol) cout<<0<<endl;
	else if (!zero){
		cout<<1<<endl;
		for(int i=0;i<12;++i)
		{
			for(int j=0;j<12;++j)
				cout<<Ques[i][j]<<" ";
			cout<<endl;
		}
	}
	else if(zero==2)
		cout<<2<<"\n";
}
