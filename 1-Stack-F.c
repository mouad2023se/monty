#include "monty.h"

/**
* add_to_stack - Add a node to the stk
* @new_node: * to the new node
* @ln: Int representing the n\ namba of the opcode.
*/
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
* print_stack - Prints all nodes in the stk
* @stack: *p pointing to top node of the stk
* @line_number: n\ namba of  the opcode.
*/
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
* pop_top - Removes the top node from the stk
* @stack: *p pointing to top node of the stk
* @line_number: Int representing the n\ namba of of the opcode
*/
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
* print_top - Prints top node of the stk
* @stack: *p pointing to top node of the stk
* @line_number: Interger representing the n\ namba of the opcode
*/
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
