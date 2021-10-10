#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <fwlist/fwlist.h>

// #define SUPER_SPID						//Режим ускорения расчета, но высокой потери точности

#ifdef	SUPER_SPID
	#define COUNT_VICTIM		10			//Регулировка потери точности
	#define NUMBER_OF_VICTIMS	2			//При ускоренном режиме, жертвует указанное кол-во знаков не давая подняться больше COUNT_VICTIM
#else
	#define COUNT_VICTIM		1000			//Регулировка потери точности
#endif

/*Удаления не используемых элементов из памяти. Не значительно снижает скорость, но позволяет не раздуваться программе*/
#define MEMORY_MONITORING

int main()
{
	SetConsoleCP (65001);
	SetConsoleOutputCP (65001);

	uint32_t in		= 0;
	bool flag		= false;		//Для определения положения
	s_mas *val1		= NULL;			//Для хранения значения из списка
	s_mas *val2		= NULL;			//Для хранения значения из списка
	uint8_t rez		= 0;			//Результат сложения
	uint64_t degree	= 0;			//Степень
	s_mas *mas		= NULL;			//Список
	uint8_t el[2]={0,1};			//Вспомогательный массив
	uint16_t count	= 0;			//Подситывет кол-во итераций и жертвует точностью

	printf("Какое число хотим? ");
	scanf("%d", &in);

	if (in == 0 || in == 1)
	{
		printf("Вот такое вот число: %d\n", el[in]);
		goto _END;
	}

	push(&mas, el, sizeof(el));

	uint64_t start = clock();

	for (uint32_t i = 2; i<=in; i++)
	{
		flag = (i%2) != 0;

		if (count == COUNT_VICTIM)			//Каждые COUNT_VICTIM кругов убираем элементы из расчета
		{
			#ifdef SUPER_SPID				//Если включен режим большой скорости, то не даем подняться выше COUNT_VICTIM
				count -= NUMBER_OF_VICTIMS;
				for (uint64_t j = 0; j < NUMBER_OF_VICTIMS; j++)
				{
					if (mas->next == NULL)
					{
						printf("Надо проверить настройки. COUNT_VICTIM < NUMBER_OF_VICTIMS\n");
						goto _END;
					}
					#ifdef MEMORY_MONITORING
						pop(&mas, el, 0);
					#else
						mas = mas->next;
					#endif
					degree++;
				}
			#else							//Убираем один элемент
				count = 0;
				#ifdef MEMORY_MONITORING
					pop(&mas, el, 0);
				#else
					mas = mas->next;
				#endif
				degree++;
			#endif
		}
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
					count++;
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

	start = (clock() - start) / CLOCKS_PER_SEC;

	printf("Вот такое вот число:\n");
	while (popBack(&mas, el, sizeof(el)) == 0)
		printf("%d", el[flag]);

	if (degree != 0)
		printf("*10^%llu", degree);

	printf("\n\nВремени потрачено на расчет: %llu", start);

	_END:
	printf("\n");
	system("pause");

	return 0;
}