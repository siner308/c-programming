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

	printf("문제1\n");

	printf("곱할 정수를 두개 입력하시오.\n\n");

	scanf_s("%d %d", &num1, &num2);				//scanf_s함수로 수를 입력할 수 있다.

	nummultiple = num1 * num2;					//두 수를 곱한다.

	printf("값 : %d\n\n\n\n", nummultiple);

	return 0;
}


int q2(void)
{
	int num1 = 0, num2 = 0, num3 = 0, numanswer = 0;

	printf("문제2\n");

	printf("A*B+C \n 위 관계식에 넣을 수를 차례대로 넣으시오.");

	printf("\nA : ");
	scanf_s("%d", &num1);								//A입력

	printf("B : ");
	scanf_s("%d", &num2);								//B입력

	printf("C : ");	
	scanf_s("%d", &num3);								//C입력

	numanswer = ( num1 * num2 ) + num3;						//계산식

	printf("값 : %d\n\n\n\n", numanswer);				//값을 프린트한다.

	return 0;
}


int q3(void)
{
	int num1 = 0, num2 = 0;

	printf("문제3\n");

	printf("제곱할 수를 입력하시오.\n");

	scanf_s("%d", &num1);								//제곱할 수를 입력한다.

	num2 = num1 * num1;									//제곱을 해준다.

	printf("%d의 제곱 : %d\n\n\n\n", num1, num2);		//값을 프린트한다.
	
	return 0;
}


int q4(void)
{
	int num1 = 0, num2 = 0;										//나눌 두 수
	int dans1 = 0, dans2 = 0;									//dans1=몫, dans2=나머지

	printf("문제4\n");

	printf("무슨 숫자를 나눌 건가요?\n");
	scanf_s("%d", &num1);

	printf("무슨 숫자로 나눌 건가요?\n");
	scanf_s("%d", &num2);


	dans1 = num1 / num2;									//몫
	dans2 = num1 % num2;									//나머지

	printf("\n몫 : %d\n", dans1);							//몫 출력
	printf("나머지 : %d\n\n\n\n", dans2);				//나머지 출력

	return 0;
}


int q5(void)
{
	int num1 = 0, num2 = 0, num3 = 0, numanswer = 0;

	printf("문제5\n");

	printf("( A - B ) * ( B + C ) * ( C %% A )\n의 식에 넣을 값을 입력하시오.\n");

	printf("A : ");
	scanf_s("%d", &num1);

	printf("B : ");
	scanf_s("%d", &num2);

	printf("C : ");
	scanf_s("%d", &num3);
	
	numanswer = (num1 - num2) * (num2 + num3) * (num3 % num1);

	printf("값 : %d\n\n\n\n", numanswer);


	return 0;
}