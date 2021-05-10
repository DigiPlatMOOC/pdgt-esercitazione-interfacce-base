#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(void){
	/*char *stringa;*/
	int i = 0;
	char stringa[128];
	
	/*stringa = (char *)malloc(128*sizeof(char));*/
	
	scanf("%s", stringa);
	
	/*printf("%s", *stringa);*/
	
	i=0;
	while(stringa[i] != '\0'){
		if(stringa[i] == ' '){
			printf("%c", ' ');
		}else{
			printf("%c", toupper(stringa[i]));
		}
		i++;
	}
	
	getchar();	/*debug*/

	return 0;
}