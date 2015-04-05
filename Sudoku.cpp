#include "Sudoku.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
 int Question[12][12]={{4, 2, 6, 8, 7, 3, 9, 5, 1, -1, -1, -1},
						{0, 0, 3, 9, 5, 0, 6, 0, 4, -1, -1, -1},
						{9, 0, 1, 6, 2, 4, 8, 0, 0, -1, -1, -1},
						{-1, -1, -1, 1, 3, 2, 0, 8, 7, 9, 5, 6},
						{-1, -1, -1, 0, 8, 0, 1, 9, 0, 4, 2, 0},
						{-1, -1, -1, 4, 9, 6, 2, 3, 0, 8, 7, 1},
						{1, 0, 0, 0, 4, 0, -1, -1, -1, 6, 9, 5},
						{0, 0, 4, 0, 6, 0, -1, -1, -1, 1, 3, 7},
						{6, 9, 5, 0, 1, 7, -1, -1, -1, 2, 8, 4},
						{3, 1, 2, -1, -1, -1, 7, 4, 0, 5, 0, 9},
						{7, 4, 8, -1, -1, -1, 0, 6, 9, 3, 0, 2},
						{0, 6, 0, -1, -1, -1, 3, 1, 0, 7, 0, 8}};
void Sudoku::GiveQuestion()
{
	for(int i=0;i<12;++i){
		for(int j=0;j<12;++j){
			cout<<Question[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Sudoku::ReadQ()
{
	for(int i=0;i<12;++i)
		for(int j=0;j<12;++j)
			ans[i][j]=Question[i][j];
}

void Sudoku::Check()
{
	if (!solvable) cout<<0<<"\n";
	else if (!exactly){
		cout<<1<<"\n";
		for(int i=0;i<12;++i)
		{
			for(int j=0;j<12;++j)
				cout<<ans[i][j];
			cout<<"\n";
		}
	}
	else cout<<2<<"\n";
}
void Sudoku::ReadIn()
{
		
}
void Sudoku::Solve()
{
	if(solvable){
		solvable=false;
	}
	Check();
}
