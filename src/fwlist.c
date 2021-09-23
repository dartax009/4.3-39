#include "fwlist.h"

void push (s_mas **head, const uint8_t data)
{
	s_mas *tmp = (s_mas *) malloc(sizeof(s_mas));

	tmp->value	= data;
	tmp->next	= (*head);
	(*head)		= tmp;

	return;
}

uint8_t pop (s_mas **head, uint8_t *val)
{
	s_mas *tmp = NULL;

	if((*head) == NULL)
		return 1;

	tmp = (*head);
	*val = tmp->value;
	(*head) = (*head)->next;
	free(tmp);

	return 0;
}

uint8_t getN (s_mas *head, const uint32_t n, uint8_t *val)
{
	for (uint32_t i=0; i<n; i++)
	{
		head = head->next;
		if (head == NULL)
			return 1;
	}
	*val = head->value;

	return 0;
}

uint8_t pushN (s_mas *head, const uint32_t n, const uint8_t val)
{
	for(uint32_t i=0; i<n; i++)
	{
		head = head->next;
		if (head == NULL)
			return 1;
	}
	head->value = val;

	return 0;
}

uint8_t sumN (s_mas *head, const uint32_t n, const uint8_t val)
{
	for(uint32_t i=0; i<n; i++)
	{
		head = head->next;
		if (head == NULL)
			return 1;
	}
	head->value += val;

	return 0;
}

s_mas *findLast (s_mas *head)
{
	if (head== NULL)
		return NULL;

	while (head->next != NULL)
		head = head->next;

	return head;
}

void pushBack (s_mas *head, const uint8_t data)
{
	s_mas *last = findLast(head);
	s_mas *tmp = (s_mas *) malloc(sizeof(s_mas));

	tmp->value	= data;
	tmp->next	= NULL;
	last->next = tmp;
}

uint8_t popBack (s_mas **head, uint8_t *val)
{
	s_mas *tmp = NULL;

	if((*head) == NULL)
		return 1;

	if ((*head)->next == NULL)
	{
		*val = (*head)->value;
		free(*head);
		*head = NULL;
		return 0;
	}

	tmp = (*head);

	while (tmp->next->next)
		tmp = tmp->next;

	*val = tmp->next->value;
	free(tmp->next);
	tmp->next = NULL;
	return 0;
}