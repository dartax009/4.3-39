#include "fwlist.h"

void push (s_mas **head, const void *val)
{
	s_mas *tmp = (s_mas *) malloc(sizeof(s_mas));

	memcpy(&tmp->value, val, sizeof(s_element));

	tmp->next		= (*head);
	(*head)			= tmp;

	return;
}

uint8_t pop (s_mas **head, void *val)
{
	s_mas *tmp = NULL;

	if((*head) == NULL)
		return 1;

	tmp = (*head);
	memcpy(val, &tmp->value, sizeof(s_element));
	(*head) = (*head)->next;
	free(tmp);

	return 0;
}

s_mas *findN (s_mas *head, const uint64_t n)
{
	for (uint64_t i=0; i<n; i++)
	{
		head = head->next;
		if (head == NULL)
			return NULL;
	}
	return head;
}

uint8_t pushN (s_mas *head, const uint32_t n, const void *val)
{
	head = findN(head, n);
	if (head == NULL)
		return 1;
	else
		memcpy(&head->value, val, n);

	return 0;
}

s_mas *findLast (s_mas *head)
{
	if (head==NULL)
		return NULL;

	while (head->next != NULL)
		head = head->next;

	return head;
}

void pushBack (s_mas **head, const void *val)
{
	s_mas *last = findLast((*head));

	s_mas *tmp = (s_mas *) malloc(sizeof(s_mas));

	memcpy(&tmp->value, val, sizeof(s_element));
	tmp->next = NULL;

	if (last == NULL)
		(*head) = tmp;
	else
		(*head)->next = tmp;

	return;
}

uint8_t popBack (s_mas **head, void *val)
{
	s_mas *tmp = NULL;

	if((*head) == NULL)
		return 1;

	if ((*head)->next == NULL)
	{
		memcpy(val, &(*head)->value, sizeof(s_element));
		free(*head);
		*head = NULL;
		return 0;
	}

	tmp = (*head);

	while (tmp->next->next)
		tmp = tmp->next;

	memcpy(val, &tmp->next->value, sizeof(s_element));

	free(tmp->next);
	tmp->next = NULL;
	return 0;
}