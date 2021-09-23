#ifndef FWLIST_H
#define FWLIST_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Элемент списка
 * value	- значение элемента
 * next		- указатель на следующий элемент
 */
struct _s_mas
{
	uint8_t value;				///>Значение элемента
	struct _s_mas *next;		///>Указатель на следуюбщий элемент
};
typedef struct _s_mas s_mas;

//---------------------------------------------------//
//----------------------Функции----------------------//
//---------------------------------------------------//

/**
 * @brief Добавить следующий элемент в список
 *
 * @param head	[out]	- указатель на новый добавленный элемент
 * @param data	[in]	- значение нового элемента
 */
void push (s_mas **head, const uint8_t data);

/**
 * @brief Удаляет первый элемент и возвращает его значение
 *
 * @param head	[out]	- указатель на предыдущий элемент или NULL
 * @param val	[out]	- значение удаленного элемента
 * @return uint8_t	- успешность исполнения
 * [0] - успешно
 * [1] - не успешно
 */
uint8_t pop (s_mas **head, uint8_t *val);

/**
 * @brief Отдает значение n-ого элемента
 *
 * @param head	[in]	- указатель на список
 * @param n		[in]	- нужный элемент
 * @param val	[out]	- значение нужного элемента (если есть)
 * @return uint8_t	- успешность исполнения
 * [0] - успешно
 * [1] - не успешно
 */
uint8_t getN (s_mas *head, const uint32_t n, uint8_t *val);

/**
 * @brief Записывает значение в n-ый элемент
 *
 * @param head	[in]	- указатель на список
 * @param n		[in]	- нужный элемент
 * @param val	[in]	- новое значение элемента
 * @return uint8_t	- успешность исполнения
 * [0] - успешно
 * [1] - не успешно
 */
uint8_t pushN (s_mas *head, const uint32_t n, const uint8_t val);

/**
 * @brief Прибавляет значение к n-ому элементу
 *
 * @param head	[in]	- указатель на список
 * @param n		[in]	- нужный элемент
 * @param val	[in]	- значение, которое будет прибавлено
 * @return uint8_t	- успешность исполнения
 * [0] - успешно
 * [1] - не успешно
 */
uint8_t sumN (s_mas *head, const uint32_t n, const uint8_t val);

/**
 * @brief Вписывает элемент в конец списка
 *
 * @param head 	[in]	- указатель на список
 * @param data 	[in]	- значение нового элемента
 */
void pushBack (s_mas *head, const uint8_t data);

/**
 * @brief Удаляет последний элемент и возвразает его значение
 *
 * @param head	[in]	- указатель на указатель списка. Устанавливается в NULL если это был последний элемент
 * @param val	[out]	- значение удаленного элемента
 * @return uint8_t	- успешность исполнения
 * [0] - успешно
 * [1] - не успешно
 */
uint8_t popBack (s_mas **head, uint8_t *val);

#endif