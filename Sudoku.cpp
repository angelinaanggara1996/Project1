#include "Sudoku.h"
#include<fstream>
#include <cstdlib>
#include <ctime>
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
bool sol=1;
int zero=0;
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

void Sudoku::Check()
{
	
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
	else cout<<2<<"\n";
}
bool Sudoku::row(int i, int j, int k)
{
	for (int a=0;a<12;++a)
	{
		if(Ques[i][a]==k)return 0;
	}
	return 1;
}
bool Sudoku::col(int i,int j, int k)
{
	for(int a=0;a<12;++a)
	{
		if(Ques[a][j]==k) return 0;
	}
	return 1;
}
bool Sudoku::cube(int i,int j, int k)
{
	
}
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
void Sudoku::ReadIn()
{
	for(int i=0; i<12;++i){
		for(int j=0; j<12; ++j){
			cin>>Ques[i][j];
			int tmpl=Ques[i][j];
			if(tmpl==-1) continue;
			
		}
	}
}
void Sudoku::Solve()
{
	int tmp=0;
	while(zero && sol)
	{
		sol=0;
		for(int i=0; i<12; ++i){
			for(int j=0; j<12; ++j){
				if(Ques[i][j]!=0) continue;
				for(int n=1 ;n<10;++n){
					if(row(i,j,n) && col(i,j,n) && cube(i,j,n)){
						if(tmp==0) tmp=n;
						else {
							tmp=0;
							break;
						}
					}
				}
				if(tmp!=0){
					Ques[i][j]=tmp;
					sol=1;
					--zero;
				}
			}
		}
	}
	int x=0;
	for(int i=0; i<12;++i){
		for(int j=0; j<12;++j){
			if(!x){
				ans[i][j]==Ques[i][j];
			}
		}
	}
	for(int i=0;i<12;++i){
		for(int j=0;j<12;++j){
			if(Ques[i][j]!=ans[i][j])
			{
				zero=2;
				break;
			}
		}
	}
	Check();
}
