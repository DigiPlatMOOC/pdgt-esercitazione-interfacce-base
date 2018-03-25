#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	char c;
	char *input;
	unsigned long len;
	int esito = getline(&input, &len, stdin);
	if(esito != -1)
	{
		while(i < len)
		{
			c = (input[i]);
			printf("%c",toupper(c));
			i++;
		}
	}
	return 0;
}
