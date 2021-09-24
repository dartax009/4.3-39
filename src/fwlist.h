/**
 * @file fwlist.h
 * @author dartax009 (Pedrato)
 * @brief Библиотечка для работы с односвязными списками.
 * В структуру "Элемент списка" (s_element) пишим свои переменные, которые хотим импользовать.
 * @version 1.0
 * @date 2021-09-24
 * Что-то даже работает.
 * @copyright Copyright (c) 2021
 * Ну юзуй, че.
 */

#ifndef FWLIST_H
#define FWLIST_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Элемент списка
 */
typedef struct _s_element
{
	uint8_t data[2];				///>Значение элемента списка
}s_element;

/**
 * @brief Звено списка
 */
struct _s_mas
{
	s_element value;				///>Элемент списка
	struct _s_mas *next;			///>Указатель на следующее звено
};
typedef struct _s_mas s_mas;



//---------------------------------------------------//
//-----------------Прототипы функций-----------------//
//---------------------------------------------------//

/**
 * @brief Добавляет следующий элемент в список
 *
 * @param head	[out]	- указатель на новый добавленный элемент
 * @param val	[in]	- значение нового элемента
 */
void push (s_mas **head, const void *val);

/**
 * @brief Удаляет первый элемент и возвращает его значение
 *
 * @param head	[out]	- указатель на предыдущий элемент или NULL
 * @param val	[out]	- значение удаленного элемента
 * @return uint8_t	- успешность исполнения
 * [0] - успешно
 * [1] - ошибка. передан указатель на NULL
 */
uint8_t pop (s_mas **head, void *val);

/**
 * @brief Возвращает указатель на n-ый элемент списка
 *
 * @param head		[in] - указатель на начало списка
 * @param n			[in] - номер искомого элемента
 * @return s_mas*	- указатель на найденный элемент или NULL если такого элемента нет
 */
s_mas *findN (s_mas *head, const uint64_t n);

/**
 * @brief Записывает значение в n-ый элемент
 *
 * @param head	[in]	- указатель на список
 * @param n		[in]	- нужный элемент
 * @param val	[in]	- новое значение элемента
 * @return uint8_t	- успешность исполнения
 * [0] - успешно
 * [1] - ошибка. такой элемент не найден
 */
uint8_t pushN (s_mas *head, const uint32_t n, const void *val);

/**
 * @brief Возвращает указатель последнего элемента списка
 *
 * @param head	[in]	- указатель на список
 * @return s_mas*	- указатель на найденный элемент или NULL если такого элемента нет
 */
s_mas *findLast (s_mas *head);

/**
 * @brief Вписывает элемент в конец списка
 *
 * @param head 	[in]	- указатель на список. Если передан NULL так же буде являться первым элементом
 * @param val 	[in]	- указатель значения нового элемента
 */
void pushBack (s_mas **head, const void *val);

/**
 * @brief Удаляет последний элемент и возвразает его значение
 *
 * @param head	[in]	- указатель на указатель списка. Устанавливается в NULL если это был последний элемент
 * @param val	[out]	- значение удаленного элемента
 * @return uint8_t	- результат выполнения
 * [0] - успешно
 * [1] - ошибка. передан указатель на NULL
 */
uint8_t popBack (s_mas **head, void *val);

#endif