#include <stdio.h>

int main(void)
{
	q1();
	q2();
	q3();
	q4();
	q5();

	return 0;
}



int q1(void)
{
	int num1 = 0, num2 = 0, nummultiple = 0;

	printf("����1\n");

	printf("���� ������ �ΰ� �Է��Ͻÿ�.\n\n");

	scanf_s("%d %d", &num1, &num2);				//scanf_s�Լ��� ���� �Է��� �� �ִ�.

	nummultiple = num1 * num2;					//�� ���� ���Ѵ�.

	printf("�� : %d\n\n\n\n", nummultiple);

	return 0;
}


int q2(void)
{
	int num1 = 0, num2 = 0, num3 = 0, numanswer = 0;

	printf("����2\n");

	printf("A*B+C \n �� ����Ŀ� ���� ���� ���ʴ�� �����ÿ�.");

	printf("\nA : ");
	scanf_s("%d", &num1);								//A�Է�

	printf("B : ");
	scanf_s("%d", &num2);								//B�Է�

	printf("C : ");	
	scanf_s("%d", &num3);								//C�Է�

	numanswer = ( num1 * num2 ) + num3;						//����

	printf("�� : %d\n\n\n\n", numanswer);				//���� ����Ʈ�Ѵ�.

	return 0;
}


int q3(void)
{
	int num1 = 0, num2 = 0;

	printf("����3\n");

	printf("������ ���� �Է��Ͻÿ�.\n");

	scanf_s("%d", &num1);								//������ ���� �Է��Ѵ�.

	num2 = num1 * num1;									//������ ���ش�.

	printf("%d�� ���� : %d\n\n\n\n", num1, num2);		//���� ����Ʈ�Ѵ�.
	
	return 0;
}


int q4(void)
{
	int num1 = 0, num2 = 0;										//���� �� ��
	int dans1 = 0, dans2 = 0;									//dans1=��, dans2=������

	printf("����4\n");

	printf("���� ���ڸ� ���� �ǰ���?\n");
	scanf_s("%d", &num1);

	printf("���� ���ڷ� ���� �ǰ���?\n");
	scanf_s("%d", &num2);


	dans1 = num1 / num2;									//��
	dans2 = num1 % num2;									//������

	printf("\n�� : %d\n", dans1);							//�� ���
	printf("������ : %d\n\n\n\n", dans2);				//������ ���

	return 0;
}


int q5(void)
{
	int num1 = 0, num2 = 0, num3 = 0, numanswer = 0;

	printf("����5\n");

	printf("( A - B ) * ( B + C ) * ( C %% A )\n�� �Ŀ� ���� ���� �Է��Ͻÿ�.\n");

	printf("A : ");
	scanf_s("%d", &num1);

	printf("B : ");
	scanf_s("%d", &num2);

	printf("C : ");
	scanf_s("%d", &num3);
	
	numanswer = (num1 - num2) * (num2 + num3) * (num3 % num1);

	printf("�� : %d\n\n\n\n", numanswer);


	return 0;
}