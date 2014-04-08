#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct domain{
	int size;
	int *value;
}Domain;

int isOddNumber(int value); //Ȧ������ ����
int isPrimeNumber(int value); //�Ҽ����� ����
int isGreaterThan10(int value); //10�̻�

int universal(Domain* domain,int (*prove) (int));
int existential(Domain* domain,int (*prove) (int));

int main(int argc, char* argv[]){
	Domain* d=0x00L;
	int i=0;

	d=(Domain *)malloc(sizeof(Domain));
	d->size = 5;
	d->value=(int *)malloc(sizeof(int)*(d->size));

	/*Test1 - odd number
	d->value[0]=10;
	d->value[1]=12;
	d->value[2]=15;
	*/

	/*Test2 - prime number
	d->value[0]=4;
	d->value[1]=6;
	d->value[2]=7;
	d->value[3]=8;
	d->value[4]=9;
	d->value[5]=11;
	*/

	/*isGreaterThan10*/
	d->value[0]=10;
	d->value[1]=11;
	d->value[2]=12;
	d->value[3]=13;
	d->value[4]=14;
	


	printf("P(x) = x>10\n");
	//printf("P(x) = x is odd integer.\n");
	//printf("P(x) = x is prime number.\n");
	printf("Domain is {10,11,12,13,14}.\n");


	//Invoke the function "existential"
	printf("For Some x, P(x) is %s\n",existential(d,isGreaterThan10) ? "true." : "false.");

	//Universal the function "universal"
	printf("For All x, P(x) is %s\n", universal(d,isGreaterThan10) ? "true." : "false.");

	free(d->value);
	free(d);
}

int isOddNumber(int value)
{
	if(value%2==0)
	{
		return FALSE;
	}
	return TRUE;
}
int isPrimeNumber(int value)
{
	int i=1;
	for(i=1;i<value;++i) //�Ҽ��Ǵ�
	{
		if(value%i==0)
			return FALSE;
	}
	return TRUE;
}
int isGreaterThan10(int value) //10�̻�
{
	return value>10;
}
int universal(Domain* domain,int(*prove) (int value))
{
	int i=0;
	for(i=0;i<domain->size;i++)
	{
		if(!(*prove)(domain->value[i])) //���� �ϳ��� �ٸ��� false
		{
			return FALSE;
		}
	}
	return TRUE; //������ ���� true
}
int existential(Domain* domain,int(*prove) (int value))
{
	int i=0;
	for(i=0;i<domain->size;i++)
	{
		if((*prove)(domain->value[i])) //�ϳ��� ������ true
		{
			return TRUE;
		}
	}
	return FALSE; //�������� ���� false
}
