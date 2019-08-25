/* **************************************************************************** */
#include <stdio.h>

int main()
{
    unsigned int x = 1027;
    char *msb;

    printf("Address at %p = 0x%02x\n",msb, *(msb));
    printf("Address at %p = 0x%02x",msb+1, *(msb+1));
    
    return 0;
}
