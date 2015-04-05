#ifndef SUDOKU_H
#define SUDOKU_H
#include<iostream>
using namespace std;

class Sudoku
{
public:
		void GiveQuestion();
		void ReadQ();
		void Check();
		void ReadIn();
		void Solve();
		static const int sudokuSize=144;
		int ans[12][12];
		bool solvable;
		bool exactly;
};	
#endif
