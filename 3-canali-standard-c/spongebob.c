/* Inclusione librerie standard */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

/* Definizione della funzione main */
int main(void)
{
	int i = 0;
	int random = 1;
	char stringa[128];

	scanf("%[^\n]s", stringa); /* leggo stringa fino alla prima riga */

	srand(time(NULL));

	while(stringa[i] != '\0')
    {
		if(stringa[i] == ' ')
		{
			printf("%c", ' ');
		}else{
		    random = rand() % 2; /* genero casualmente un numero tra 0 e 1 */
		    if(islower(stringa[i]))
		    {
		        if(random == 0)
                {
                    printf("%c", toupper(stringa[i]));
		        }else{
                    printf("%c", stringa[i]);
		        }
		    }else{
		        if(random == 0)
                {
                    printf("%c", tolower(stringa[i]));
		        }else{
                    printf("%c", stringa[i]);
		        }
            }
		}
		i++;
	}
	return 0;
}