#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "includ/fwlist/fwlist.h"

int main()
{
	SetConsoleCP (65001);
	SetConsoleOutputCP (65001);

	uint32_t in		= 0;
	bool flag		= false;		//Для определения положения
	s_mas *val1		= NULL;			//Для хранения значения из списка
	s_mas *val2		= NULL;			//Для хранения значения из списка
	uint8_t rez		= 0;			//Результат сложения
	s_mas *mas		= NULL;			//Список
	s_element el	= {0};			//Вспомогательная переменная

	printf("Какое число хотим?");
	scanf("%d", &in);

	if (in == 0)
	{
		printf("Вот такое вот число: 0");
		goto _END;
	}
	if (in == 1)
	{
		printf("Вот такое вот число: 1");
		goto _END;
	}

	{
		uint8_t i[2]={0,1};
		push(&mas, i);
	}

	for (uint32_t i = 2; i<=in; i++)
	{
		flag = (i%2) != 0;
		val1 = mas;
		while (1)
		{
			rez = val1->value.data[0] + val1->value.data[1];
			val1->value.data[flag] = (uint8_t)rez%10;
			if (rez>9)
			{
				val2 = val1->next;
				if(val2 == NULL)
				{
					el.data[flag] = (uint8_t)rez/10;
					pushBack(&val1, &el);
					break;
				}
				val2->value.data[flag] += (uint8_t)rez/10;
			}
			val1 = findN(val1, 1);
			if (val1 == NULL)
				break;
		}
		el.data[flag] = 0;
	}

	// flag = (in%2) != 0;
	printf("Вот такое вот число:\n");
	while (popBack(&mas, &el) == 0)
		printf("%d", el.data[flag]);

	_END:
	printf("\n");
	system("pause");

	return 0;
}