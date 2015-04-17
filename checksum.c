#include <stdio.h>

#define MAX_LEN 100
#define NUMBER_LEN 10

void resetArr(int, char *);

void resetArr(int len, char *reset)
{
	for(int i = 0; i < len; ++i)
	{
		reset[i] = 0;
	}
}

int main(void)
{
	char charsIn[MAX_LEN];
	char numbers[NUMBER_LEN];

	int skip;

	while(NULL != fgets(charsIn, sizeof(charsIn), stdin))
	{
		resetArr(NUMBER_LEN, numbers);
		skip = 0;
		for(int i = 0; i < NUMBER_LEN; ++i)
		{
			if(charsIn[i] < '0' || charsIn[i] > '9')
			{
				skip = 1;
				break;
			}
			numbers[i] = charsIn[i] - '0';
		}
		if(!skip)
		{
			int total = 0;
			for(int i = 0; i < NUMBER_LEN - 1; ++i)
			{
				total += numbers[i];
			}
			if(numbers[NUMBER_LEN - 1] == total % 10)
			{
				printf("%s", charsIn);
			}
		}
	}

	return 0;
}
