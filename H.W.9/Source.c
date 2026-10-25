#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_CTYPE, "RUS");

	char user_char;
	int h, b, a, KD, c, offset;
	float angle;
	int user_answer;

	do
	{
		printf("Введите символ из которого будет состоять фигура: ");
		scanf(" %c", &user_char);
		printf("Введите высоту: ");
		scanf("%d", &h);
		printf("Введите сторону b: ");
		scanf("%d", &b);
		printf("Введите угол: ");
		scanf("%f", &angle);
		printf("\n");

		angle = angle * (M_PI / 180);

		KD = round(h / tan(angle));

		a = b + KD;

		c = b;

		offset = round((a - b) / (float)(h - 1));

		for (int temp1 = 1; temp1 <= h; temp1++) {

			for (int temp2 = 1; temp2 <= a; temp2++) {

				if (((temp1 == 1) && temp2 <= b) || (temp1 == h)) printf("%c", user_char);
				else
					if (temp2 <= c) printf("%c", user_char);
					else printf(" ");

			}

			c += offset;	
				
			printf("\n");
		}

		printf("\n");
		printf("Продолжить? (Да - любое число, нет - 0): ");
		scanf("%d", &user_answer);
	} 
	while (user_answer != 0);
	
	return 0;
}