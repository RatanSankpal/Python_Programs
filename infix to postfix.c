#include<stdio.h>
#include"stack.h"

int is_operand(char ch);
int priority(char ch);

void infix_to_postfix(char infix[], char postfix[]);

int main(void)
{
	char infix[20] = "a*b/c*d+e-f*h+i";
	char postfix[20];

	printf("infix : %s\n", infix);
	infix_to_postfix(infix, postfix);
	printf("Postfix : %s\n", postfix);

	return 0;
}
void infix_to_postfix(char infix[], char postfix[])
{
	int j = 0;
	stack_t st;
	s_init(&st);

	
	for(int i = 0 ; infix[i] != '\0' ; i++)
	{
		
		if(is_operand(infix[i]))
			
			postfix[j++] = infix[i];
		else if(infix[i] == '(')
			// push '(' on stack
			s_push('(', &st);
		else if(infix[i] == ')')
		{
			char ch;
			while((ch = s_peek(&st)) != '(')
			{
				postfix[j++] = ch;
				s_pop(&st);
			}
			s_pop(&st);
		}
		
		else
		{
			
			while(!s_is_empty(&st) && priority(s_peek(&st)) >= priority(infix[i]))
			{
				
				postfix[j++] = s_peek(&st);
				s_pop(&st);
			}
			
			s_push(infix[i], &st);
		}
	}
	
	while(!s_is_empty(&st))
	{
		postfix[j++] = s_peek(&st);
		s_pop(&st);
	}
	postfix[j] = '\0';
}

int is_operand(char ch)
{
	return (ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122);
}
int priority(char ch)
{
	switch(ch)
	{
		case '$':
			return 10;
		case '*':
		case '/':
		case '%':
			return 9;
		case '+':
		case '-':
			return 8;
		case '(':
		case ')':
		default:
			return 0;
	}
}







