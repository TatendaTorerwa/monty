#include "monty.h"

/**
 * file_open - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void file_open(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		error(2, file_name);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_file(FILE *fd)
{
	int line_counter, storage_format = 0;
	char *buff = NULL;
	size_t length = 0;

	for (line_counter = 1; getline(&buff, &length, fd) != -1; line_counter++)
	{
		storage_format = parse_line(buff, line_counter, storage_format);
	}
	free(buff);
}
/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buff: line from the file
 * @line_counter: line number
 * @storage_format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buff, int line_counter, int storage_format)
{
	char *op_code, *value;
	const char *separator = "\n ";

	if (buff == NULL)
		error(4);

	op_code = strtok(buff, separator);
	if (op_code == NULL)
		return (storage_format);
	value = strtok(NULL, separator);

	if (strcmp(op_code, "stack") == 0)
		return (0);
	if (strcmp(op_code, "queue") == 0)
		return (1);

	find_function(op_code, value, line_counter, storage_format);
	return (storage_format);
}

/**
 * find_function - find the appropriate function for the opcode
 * @op_code: opcode
 * @value: argument of opcode
 * @storage_format:  storage format. If 0 Nodes will be entered as a stack.
 * @line_number: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_function(char *op_code, char *value, int line_number, int storage_format)
{
	int p;
	int flag;

	instruction_t function_list[] = { 
		{"push", add_to_stack},
		{"pall", printStack},
		{"pint", printTop},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", addNode},
		{"sub", subNode},
		{"div", divNode},
		{"mul", stack_multiply},
		{"mod", stack_modulo},
		{"pchar", print_character},
		{"pstr", print_string},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	

	if (op_code[0] == '#')
		return;

	for (flag = 1, p = 0; function_list[p].opcode != NULL; p++)
	{
		if (strcmp(op_code, function_list[p].opcode) == 0)
		{
			call_function(function_list[p].f, op_code, value, line_number, storage_format);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, line_number, op_code);
}


/**
 * call_function - Calls the required function.
 * @function: Pointer to the function that is about to be called.
 * @op_code: string representing the opcode.
 * @numeric_value: string representing a numeric value.
 * @line_number: line numeber for the instruction.
 * @storage_format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */

void call_function(op_func function, char *op_code, char *numeric_value, int line_number, int storage_format)
{
	stack_t *head;
	stack_t *node;
	int flag;
	int p;

	flag = 1;
	if (strcmp(op_code, "push") == 0)
	{
		if (numeric_value != NULL && numeric_value[0] == '-')
		{
			numeric_value = numeric_value + 1;
			flag = -1;
		}
		if (numeric_value == NULL)
			error(5, line_number);
		for (p = 0; numeric_value[p] != '\0'; p++)
		{
			if (isdigit(numeric_value[p]) == 0)
				error(5, line_number);
		}
		node = createNode(atoi(numeric_value) * flag);
		if (storage_format == 0)
			function(&node, line_number);
		if (storage_format == 1)
			add_to_queue(&node, line_number);
	}
	else
		function(&head, line_number);

}
