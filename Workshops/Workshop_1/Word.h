#ifndef SDDS_WORD_H__
#define SDDS_WORD_H__

namespace sdds 
{

	const int MAX_WORD_LEN = 21;
	const int MAX_NO_OF_WORDS = 500;

	struct Word {
		char letters[MAX_WORD_LEN];
		int count;
	};

	int searchWords(const Word words[], int num, const char word[]);

	void addWord(Word words[], int* index, const char newWord[]);

	void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);

	void wordStats(bool logOn);

	void programTitle();

	void title();

	void endList();
}

#endif