#include "Sudoku.h"
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
//GiveQuestion
void Sudoku::GiveQuestion()
{
	int tmp=0,a,b;
	int z=25;
	srand(time(NULL));
	a=rand()%3+1;	
	b=rand()%3+1;
	switch(a)
	{
	case 1: {
				randomRow(0,1);
				randomRow(2,3);
				break;
			}
	case 2: {
				randomRow(0,2);
				randomRow(1,3);
				break;
			}
	case 3: {
				randomRow(0,3);
				randomRow(1,2);
				break;
			}
	}
	switch(b)
	{
	case 1: {
			randomCol(0,1);
			randomCol(2,3);
			break;
			}
	case 2: {
			randomCol(0,2);
			randomCol(1,3);
			break;
			}
	case 3: {
			randomCol(0,3);
			randomCol(1,2);
			}
	}
	while(tmp<z)
	{
		int a=rand()%12;
		int b=rand()%12;
		if(myQ[a][b]==0 || myQ[a][b]==-1) continue;
		else
		{
			myQ[a][b]=0;
			++tmp;
		}
	}
	for(int i=0;i<12;++i)
	{
		for(int j=0;j<12;++j)
		{
			cout<<myQ[i][j]<<" ";
		}
		cout<<endl;
	}
}

//randoming the give question row
void Sudoku::randomRow(int a, int b)
{
	for(int i=a*3,x=0,y=b*3;x<3; ++i,++x,++y)
	{
		for(int j=0;j<12;++j)
		{
			int tmp=myQ[i][j];
			myQ[i][j]=myQ[y][j];
			myQ[y][j]=tmp;
		}
	}
}
//randoming the column(column exchange)
void Sudoku::randomCol(int a,int b)
{
	for(int j=a*3,x=0,y=b*3;x<3;++j,++x,++y)
	{
		for(int i=0;i<12;++i)
		{
			int tmp=myQ[i][j];
			myQ[i][j]=myQ[i][y];
			myQ[i][y]=tmp;
		}
	}
}
//trying to row and column exchange
/*void Sudoku::Rand(int n1)
{
	for(int i=n1*3, a=n1*3+1,m=n1*3+2; n1<4;++n1)
		for(int j=0,b=3, n=6,x=0;x<3;++j,++b,++n)
		{
			int tmp=myQ[i][j];
			myQ[i][j]=myQ[a][b];
			myQ[a][b]=myQ[m][n];
			myQ[m][n]=tmp;
		}
}*/
//read other people question
void Sudoku::ReadIn()
{
    begin[0] = 0;
    int i,j;
    for(i=0;i<12;i++)
	{
        for(j=0;j<12;j++)
		{
        	Ques[i][j] = 0;
        	ans[i][j] = 0;
        }
    }
    for(i=0;i<12;i++)
	{
        for(j=0;j<12;j++)
        	cin>>Ques[i][j];
    }
}
//checking row is from 1-9 or not
int Sudoku::row(int rw,int r)
{
    int j;
    for(j=0;j<12;j++)
	{
        if(Ques[r][j] == rw)
        return 0;
    }
    return 1;
}
//check column is 1-9 or not
int Sudoku::column(int col,int c)
{
    int i;
    for(i=0;i<12;i++)
	{
        if(Ques[i][c] == col)
        return 0;
    }
    return 1;
}
//checking if in the 3x3 cube is from 1 to 9 or not
int Sudoku::cube(int square,int s,int ss)
{
    int x=s-(s%3),y=ss-(ss%3);
    for(int i = 0; i < 3; i++)
	{
        for (int j = 0; j < 3; j++)
            if(Ques[x+i][y+j] == square)
            	return 0;
    }
    return 1;
}
//solving the sudoku
void Sudoku::SolveSudoku()
{
    int i,j;
    int num = 0;
    for(i=0;i<12;i++)
	{
        for(j=0;j<12;j++)
		{
            if (Ques[i][j] != 0)
                num++;
        }
    }
    if(num == 144)
	{
        begin[0]++;
        if(begin[0] == 2)
		{
        	cout<<2<<endl; // if there is more than 1 solution
            return;
        }
        for(i=0;i<12;i++)
		{
            for(j=0;j<12;j++)
            	ans[i][j]=Ques[i][j];
        }
        return;
    }

    int insert;

    for(i=11;i>=0;i--)
	{
        for(j=11;j>=0;j--)
		{
			if(Ques[i][j]==(-1)) continue;
            if(Ques[i][j] == 0)
			{
                for(insert=1;insert<=9;insert++)
				{
                	if(row(insert,i) == 1 && column(insert,j) == 1 && cube(insert,i,j) == 1)
					{
                    	Ques[i][j]=insert;
                        SolveSudoku(); //recursive
                        Ques[i][j] = 0;
                    }
                }
                return;
            }
        }
    }
}
//print out the answer
void Sudoku::print()
{
    int i,j;
    for(i=0;i<12;i++)
	{
        for(j=0;j<12;j++)
     	   cout<<ans[i][j]<<" ";
		cout<<endl;
    }
}

void Sudoku::Solve()
{
	SolveSudoku();
	if(begin[0] == 0)
    	cout<<"0"<<endl;
	else if(begin[0] == 1)
	{
    	cout<<"1"<<endl;
   		print();
	}
}
