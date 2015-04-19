#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{
public:
		void GiveQuestion();
		void ReadIn();
		void Solve();
private:
		int ans[12][12];
		int Ques[12][12];
		static int myQ[12][12];
		void randomRow(int , int);
		void randomCol(int , int);
		void Rand(int);
		void SolveSudoku();
		void print();
		int begin[0];
		int row(int, int);
		int column(int, int);
		int cube(int,int,int);
};	
#endif
