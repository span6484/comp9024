
#include <stdbool.h>

typedef struct StackRep *Stack;
typedef struct NodeRep *Node;
// set up empty stack
Stack newStack();

 //remove unwanted stack
void dropStack(Stack);


 // check whether stack is empty
bool StackIsEmpty(Stack);

 // insert an int on top of stack
void StackPush(Stack, int);

 // remove int from top of stack
int StackPop(Stack);

// print the stacks val;
void printStack(Stack);



