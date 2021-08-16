#ifndef SDDS_TOOLS_H__
#define SDDS_TOOLS_H__
#include "Word.h"

namespace sdds 
{

	void toLowerCaseAndAlphabeticCopy(char des[], const char source[]);

	void print(const Word* w, bool gotoNextLine);

	void report(const Word words[], int noOfWords, int longestWord);

	void swap(Word* p1, Word* p2);

	void sort(Word words[], int cnt);
}
#endif