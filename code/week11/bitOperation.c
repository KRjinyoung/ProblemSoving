/* #include <stdio.h>
int main()
{
    printf("%d", 7 - 3);
    printf("%d", 0x00000007 + (~(0x00000003) + 1));

    int n = 6;
    if (n & 0x00000001)
        printf("홀수");
    else
        printf("짝수");
} */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define mask 0x00FF0000
int main()
{

}

#define DIRTY 0x01 
#define OPEN 0x02 
#define VERBOSE 0x04 
#define RED 0x08 
#define SEASICK 0x10 
// Testing, setting and clearing a flag 
if (flags & DIRTY)     /* code for dirty case */  
if (!(flags & OPEN))  /* code for closed case */  
if (flags & DIRTY) /* means ``if the DIRTY bit is on''.  */
flags = flags | DIRTY;   /* set DIRTY bit */
flags = flags & ~DIRTY;   /* clear DIRTY bit */