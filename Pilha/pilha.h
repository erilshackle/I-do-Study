#ifndef PILHA_H
#define PILHA_H

#define MAX 10

struct Pilha{
    int elementos[MAX];
    int top;
};

typedef struct Pilha Pilha;

void setStack(Pilha *strcuts);
int stacks_status(Pilha *stack, char mode[]);
void push(Pilha *stack, int val);
void pop(Pilha *stack);
void stack_print(Pilha *stack);
void push_file(Pilha *stack, char filename[]);


#endif // PILHA_H
