#include <stdio.h>


//02-1 [예제 변경해보기]


int q1_1(void) //문제1_1
{
	printf("홍길동 \n""홍 길 동 \n" "홍  길  동\n\n\n\n"); //\n은 줄을 넘겨준다. 2번문제와의 간격조절을 위해 여러번 사용.

	return 0;
}



int q1_2(void) //문제1_2
{
	printf("이름 : 동해랑\n");
	printf("주소 : 세라시 일하라구 랑해동 인그갓겜아파트 101동 202호\n");
	printf("전화번호 : 123-4567-8901\n\n\n\n");

	return 0;
}



int q2_1(void) //문제2_1
{
	printf("제 이름은 홍길동입니다.\n");
	printf("제 나이는 %d살이고요.\n", 20); //%d라고 쓴 위치로 뒤에 적은 숫자를 반영한다.
	printf("제가 사는 곳의 번지수는 %d-%d입니다.\n\n\n\n", 123, 456);

	return 0;
}



int q2_2(void) //문제2_2
{
	printf("%d*%d=%d\n", 4, 5, 20);
	printf("%d*%d=%d\n\n\n\n", 7, 9, 63);

	return 0;
}


int main(void)
{
	q1_1(); //1_1번문제 실행
	q1_2(); //1_2번문제 실행
	q2_1(); //2_1번문제 실행
	q2_2(); //2_2번문제 실행
}

