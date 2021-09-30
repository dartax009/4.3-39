#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <fwlist/fwlist.h>

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
	uint8_t el[2]={0,1};			//Вспомогательный массив

	printf("Какое число хотим?");
	scanf("%d", &in);

	if (in == 0 || in == 1)
	{
		printf("Вот такое вот число: %d\n", el[in]);
		goto _END;
	}

	push(&mas, el, sizeof(el));

	for (uint32_t i = 2; i<=in; i++)
	{
		flag = (i%2) != 0;
		val1 = mas;
		while (1)
		{
			rez = ((uint8_t *)val1->value)[0] + ((uint8_t *)val1->value)[1];
			((uint8_t *)val1->value)[flag] = (uint8_t)rez%10;
			if (rez>9)
			{
				val2 = val1->next;
				if(val2 == NULL)
				{
					el[flag] = (uint8_t)rez/10;
					pushBack(&val1, el, sizeof(el));
					break;
				}
				((uint8_t *)val2->value)[flag] += (uint8_t)rez/10;
			}
			val1 = findN(val1, 1);
			if (val1 == NULL)
				break;
		}
		el[flag] = 0;
	}

	printf("Вот такое вот число:\n");
	while (popBack(&mas, el, sizeof(el)) == 0)
		printf("%d", el[flag]);

	_END:
	printf("\n");
	system("pause");

	return 0;
}