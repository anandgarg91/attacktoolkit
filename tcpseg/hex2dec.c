#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	char hex[17];
	long long decimal, decimal1, decimal2, place;
	int i =0, val, len;
int a[10];
decimal =0 ;
place =1;

printf("enter anh hex number:");
for(int j=0;j<2;j++)
{
printf("enter number");
scanf("%s",hex);
len= strlen(hex);
len--;

for(i=0; hex[i]!='\0';i++)
{
	if(hex[i]>='0' && hex[i]<='9')
		{
			val = hex[i] -48;		
		}
	else if (hex[i]>='a' && hex[i]<='f')
		{
			val = hex[i] - 97 + 10;			
		}
	else if(hex[i]>='A' && hex[i]<='F')
		{
			val = hex[i] -65 +10;
		}
	
	decimal += val * pow(16, len);
	len--;
}
if(j==0)
{decimal1 = decimal;
decimal=0;
}
if(j==1)
decimal2= decimal;
}
printf("Hexadecimal number = %s\n", hex);
printf("Decimal number = %lld", decimal1-decimal2);

return 0;
}
