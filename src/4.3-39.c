#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "fwlist.h"

int main()
{
	SetConsoleCP (65001);
	SetConsoleOutputCP (65001);

	uint32_t in		= 0;
	bool flag		= false;
	uint8_t	val1	= 0;			//Для хронения значения из первого списка
	uint8_t	val2	= 0;			//Для хронения значения из второго списка
	uint8_t rez		= 0;			//Результат сложения
	uint32_t count	= 0;			//Счетчик циклов

	s_mas *mas1 = NULL;				//Первый список
	s_mas *mas2 = NULL;				//Второй список

	scanf("%d", &in);

	push(&mas1, 0);
	push(&mas2, 1);


	for (uint32_t i = 2; i<=in; i++)
	{
		flag = (i%2) == 0;

		if(flag)
		{
			while (1)
			{
				if (getN(mas1, count, &val1))
					break;
				getN(mas2, count, &val2);

				rez=val1+val2;
				pushN(mas1, count, (uint8_t)rez%10);		//Кладем сумму в элемент
				if (((uint8_t)rez/10)!=0)					//Результат больше 10
				{
					if(sumN(mas1, (count+1), (uint8_t)rez/10))	//Есть еще элементы? Если да, то плюсуем к нему значение
					{
						pushBack(mas1, (uint8_t)rez/10);
						pushBack(mas2, 0);
						if ((uint8_t)rez/10 < 9)				//Последнее записанное число меньше 10? Если да, то расчет этого числа закончен
							break;
					}
				}
				count++;
			}
		}
		else
		{
			while (1)
			{
				if (getN(mas1, count, &val1))
					break;
				getN(mas2, count, &val2);

				rez=val1+val2;
				pushN(mas2, count, (uint8_t)rez%10);		//Кладем сумму в элемент
				if (((uint8_t)rez/10)!=0)					//Результат больше 10
				{
					if(sumN(mas2, (count+1), (uint8_t)rez/10))	//Есть еще элементы? Если да, то плюсуем к нему значение
					{
						pushBack(mas2, (uint8_t)rez/10);
						pushBack(mas1, 0);
						if ((uint8_t)rez/10 < 9)				//Последнее записанное число меньше 10? Если да, то расчет этого числа закончен
							break;
					}
				}
				count++;
			}
		}
		count=0;
	}

	if (flag || in==0)
	{
		while (popBack(&mas1, &val1) == 0)
			printf("%d", val1);
	}
	else
	{
		while (popBack(&mas2, &val2) == 0)
			printf("%d", val2);
	}
	printf("\n");
	system("pause");

	return 0;
}