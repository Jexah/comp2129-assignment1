#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void resetArr(int, char *);

void resetArr(int length, char *source)
{
	for(int i = 0; i < length; ++i)
	{
		source[i] = 0;
	}
}

int main(int argc, char **argv)
{
	int a = atoi(*(argv+1));
	int b = atoi(*(argv+2));
	int c = atoi(*(argv+3));
	int d = atoi(*(argv+4));

	char charsIn[100];

	while(NULL != fgets(charsIn, sizeof(charsIn), stdin))
	{
		int locations[4];
		int currentChar = 0;
		for(int i = 0; i < 4; ++i)
		{
			char temp[100];
			resetArr(100, temp);
			for(int j = 0;; ++j)
			{
				if(!isdigit(charsIn[currentChar]) && charsIn[currentChar] != '-')
				{
					currentChar++;
					break;
				}
				temp[j] = charsIn[currentChar];
				currentChar++;
			}
			locations[i] = atoi(temp);
		}

		int x1 = a * (locations[0]) + b * (locations[1]);
		int y1 = c * (locations[0]) + d * (locations[1]);
		int x2 = a * (locations[2]) + b * (locations[3]);
		int y2 = c * (locations[2]) + d * (locations[3]);

		printf("%d\n", abs(x1 - x2) + abs(y1 - y2));
	}

	return 0;
}
