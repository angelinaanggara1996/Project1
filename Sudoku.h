#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{
public:
		void GiveQuestion();
		void ReadIn();
		void Solve();
private:
		void Check();
		int ans[12][12];
		int Ques[12][12];
		static int myQ[12][12];
		void randomRow(int , int);
		bool row(int i,int j, int k);
		bool col(int i, int j, int k);
		bool cube(int i,int j, int k);
};	
#endif
