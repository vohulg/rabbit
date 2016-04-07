// Rabbit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <errno.h>
#include <vector>

using namespace std;

bool openFile(string fname)
{

	FILE* file;

	errno_t retVal;
	retVal  = fopen_s( &file, fname.c_str(), "r");

	if (retVal != 0)
	{
		printf("file not open \n");
		return false;
	}

	char buf[10] = {0};
	char oneChar[1] = { 0 };
	int indexBuf = 0;
	
	// get first digit - count of all digits
	size_t readCount =  fread_s(oneChar, sizeof oneChar, 1,1, file);

	while (*oneChar != '\n')
	{
		buf[indexBuf] = *oneChar;
		indexBuf++;
		fread_s(oneChar, sizeof oneChar, 1, 1, file);
	}

	buf[indexBuf] = '\0';
	int countDigit = 0;
	sscanf_s(buf, "%d", &countDigit);

	// create buffer for keeping of digits
	int* digitsArray = new int(countDigit);

	// get last digits	

	readCount = fread_s(oneChar, sizeof oneChar, 1, 1, file);
	int insideDigitIndex = 0;
	int outsideDigitIndex = 0;
	int tempInt = 0;
	while (readCount != 0)
	{
		while (*oneChar != ' ' && readCount != 0)
		{
			buf[insideDigitIndex] = *oneChar;
			insideDigitIndex++;
			readCount = fread_s(oneChar, sizeof oneChar, 1, 1, file);

		}

		buf[insideDigitIndex] = '\0';
		sscanf_s(buf, "%d", &tempInt );
		digitsArray[outsideDigitIndex] = tempInt;
		outsideDigitIndex++;
		insideDigitIndex = 0;
		readCount = fread_s(oneChar, sizeof oneChar, 1, 1, file);
		
	}


	/*
	for (int i = 0; i < countDigit; i++)
	{
		int x = *digitsArray;
		int g = 10;
		printf("%d", g);
		digitsArray++;
		
	}
	*/

	
	





	return true;

}

int main()
{
	string inputFile = "C:\\vc-proj\\OlimpTasks\\Debug\\input.txt";
	openFile(inputFile);

	return 0;
}

