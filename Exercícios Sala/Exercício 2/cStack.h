#ifndef CSTACK_H_
#define CSTACK_H_

#define SIZE 10

typedef struct Stack{
    int elements[SIZE];
    int top;
} Stack;

void init(Stack *stack);
void push(Stack *stack, int element);
int pop(Stack *stack);
int top(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
int size(Stack *stack);
int capacity(Stack *stack);
void show (Stack *stack);

void init(Stack *stack){
    stack->top = -1;
}

void push(Stack *stack, int element){
    if (!isFull(stack)){
        stack->top++;
        stack->elements[stack->top] = element;
    }
    else
        printf("Pilha cheia!");
}

int pop(Stack *stack){
    if (!isEmpty(stack)) {
		stack->top--;
		return stack->elements[stack->top+1];
	}
	else{
        printf("Pilha vazia\n");
	}
}

int top(Stack *stack){
    if (isEmpty(stack)){
		return stack->elements[stack->top];
    }
}

int isEmpty(Stack *stack){
    return (stack->top == -1);
}

int isFull(Stack *stack){
    return (stack->top == SIZE-1);
}

int size(Stack *stack){
    return stack->top+1;
}

int capacity(Stack *stack){
    return SIZE;
}

void show(Stack *stack){
    while(!isEmpty(stack)){
        printf("%c", pop(stack));
    }
}

#endif
