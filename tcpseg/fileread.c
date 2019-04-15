#include<stdio.h>
#include<stdlib.h>

int main()
{
char ch, file_name[10];
int i;
FILE *fp;

printf("enter name of a file\n");

gets(file_name);

fp= fopen(file_name,"r");

if(fp==NULL)
{
perror("error in opening\n");
exit(EXIT_FAILURE);
}

printf("The content of file:\n",file_name);

while((ch = fgetc(fp)) !=EOF)
{
	
	printf("%02x ",ch);
	if( !(++i % 16)) putc('\n', stdout);
}

fclose(fp);
putc('\n',stdout);
return 0;
}
