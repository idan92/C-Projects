#include "PointersLibs.h"

/*struct stack
{
    void ** values;
    unsigned int items;
};*/




void main(void)
{
    struct stack s;
    InitializeStack(&s);
    int num1 = 4, num2 = 5, num3 = 6;
    PushStack(&s, &num1);
    PushStack(&s, &num2);
    PushStack(&s, &num3);
    printf("%hu\n", ItemsStack(&s));
    printf("%p\n", PopStack(&s));
    printf("%hu\n", PopStack(&s));
    printf("%hu\n", PopStack(&s));
}