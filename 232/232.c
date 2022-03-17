
struct _stack {
    int val;
    struct _stack * next;
};

typedef struct _MyQueue {
    struct _stack * stack;
} MyQueue;

void _StackPush(struct _stack ** stack, int x) {
    struct _stack * node = malloc(sizeof(struct _stack));
    node->val = x;
    node->next = *stack;
    *stack = node;
}

int _StackPop(struct _stack ** stack) {
    struct _stack * tmp = *stack;
    int val = tmp->val;
    *stack = (*stack)->next;
    free(tmp);
    return val;
}

MyQueue* myQueueCreate() {
    MyQueue * head = malloc(sizeof(MyQueue));
    head->stack = NULL;
    return head;
}

void myQueuePush(MyQueue* obj, int x) {
    struct _stack * tmp;
    while(obj->stack) {
        _StackPush(&tmp, _StackPop(&obj->stack));
    }
    _StackPush(&tmp, x);
    while(tmp) {
        _StackPush(&obj->stack, _StackPop(&tmp));
    }
}

int myQueuePop(MyQueue* obj) {
    return _StackPop(&obj->stack);
}

int myQueuePeek(MyQueue* obj) {
    return obj->stack->val;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->stack == NULL;
}

void myQueueFree(MyQueue* obj) {
    while(!myQueueEmpty(obj)) {
        myQueuePop(obj);
    }
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
