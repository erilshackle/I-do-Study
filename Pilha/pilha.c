#include <stdio.h>
#include "pilha.h"
#include <string.h>

void setStack(Pilha *list){
    list->top = -1;
}

int stacks_status(Pilha *stack, char mode[])
{
    if(strcmp(mode,"full")){
        if(stack->top == MAX-1)
            return 1;
        else
            return 0;
    }else if(strcmp(mode,"empty")){
        if(stack->top ==-1)
            return 1;
        else
            return 0;
    }
    return -1;
}
void push(Pilha *stack, int val)
{
    if(stacks_status(stack, "full")){
        puts("A lista esta cheia");
    }else{
        stack->top++;
        stack->elementos[stack->top] = val;
    }
}
void pop(Pilha *stack)
{
    if(stacks_status(stack, "empty")){
        puts("A lista esta vazia");
    }else {
        printf("%d foi removido da lista\n", stack->elementos[stack->top]);
        stack->elementos[stack->top] = 0;
        stack->top--;
    }
}

void stack_print(Pilha *stack){
    puts("LISTA:");
    int i;
    for(i=0;i<=stack->top;i++){
        printf("%-3i", stack->elementos[i]);
    }
    puts("");
}

void save_file(Pilha *stack, char filename[]){
    FILE *fp = fopen(filename, "w");
    if(!fp){
        puts("File not created");
    }else{
        int i;
        for(i =0;i<=stack->top;i++){
            fprintf(fp,"%d\n",stack->elementos[i]);
        }
    }
}
