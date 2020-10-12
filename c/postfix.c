// All rights reserved by @smallcuteGPA, 2020
//
// Reference:
//   https://twitter.com/smallcuteGPA/status/1315571103964696576

#include<stdio.h>
#include<stdlib.h>
#define STACK_MAX 1000

int top;
char expr[STACK_MAX];
int stack[STACK_MAX];
typedef enum {
    lparen,
    rparen,
    plus,
    minus,
    times,
    divide,
    mod,
    eos = '\0',
    operand
}precedence;

int eval(void);
precedence getToken(char * symbol, int *n);

void push(int value);
int pop();

int main() {
    int i = 0;
    printf("수식 입력 : ");
    scanf("%s", expr);
    // 혹은 scanf_s("%s", expr, STACK_MAX);
    printf("%d\n", eval());

    return 0;
}

int eval(void) {
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0;
    top = -1;
    token = getToken(&symbol, &n);

    while (token != eos)
    {
        if (token == operand)
        {
            push(symbol - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();
            switch (token)
            {
            case plus: push(op1 + op2);
                break;
            case minus: push(op1 - op2);
                break;
            case times: push(op1 * op2);
                break;
            case divide: push(op1 / op2);
                break;
            case mod: push(op1 % op2);
                break;
            }
        }
        token = getToken(&symbol, &n);
    }
    return pop();
}

precedence getToken(char* symbol, int* n) {
    *symbol = expr[(*n)++];
    switch (*symbol)
    {
    case '(': return lparen;
    case ')': return rparen;
    case '+': return plus;
    case '-': return minus;
    case '/': return divide;
    case '*': return times;
    case '%': return mod;
    case '\0': return eos;
    default: return operand;
    }
}

void push(int value) {
    if (top == STACK_MAX - 1)
    {
        printf("스택에 데이터가 가득 찼습니다.\n");
        // NOTE: 더이상 정상적인 실행이 불가능함, 종료
        exit(1);
    }

    stack[top + 1] = value;
    top++;
}

int pop() {
    if (top == - 1)
    {
        printf("스택이 비었습니다.\n");
        // NOTE: 더이상 정상적인 실행이 불가능함, 종료
        exit(1);
    }
    top--;
    return stack[top+1];
}
// vim: ts=4 sw=4 sts=4
