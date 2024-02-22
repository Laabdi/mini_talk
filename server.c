#include "minitalk.h"


void    bit_writer(int bit_recieved)
{
    static int bit = 7;
    static int set = 0;
    set += (bit_recieved << bit);
    // printf("bit value after bit shifting :%d\n",bit);
    // printf("set value after bit shifting :%d\n",set);
    if (bit == 0)
    {
        printf("%c",set);
        bit = 7;
        set = 0;
    }
    else
        bit--;
}
void    bit_handler(int bit_recieved)
{
    if(bit_recieved == SIGUSR1)
    bit_writer(1);
    else
    bit_writer(0);

}
int main(void)
{  
    int nb = getpid();
    printf("server PID ----->%u\n",nb);
    signal(SIGUSR1,bit_handler);
    signal(SIGUSR2,bit_handler);
    printf("signal sent by the client ----->");
    while(1)
    pause();
}
  