// Online C compiler to run C program online
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void get_byte(int signal)
{
    static char rec_byte = 0;
    static int counter = 0;
    
 
    if (signal == SIGUSR2)
    {
        rec_byte |= 1;
    }
    
    if (counter == 7)
    {
        write(1, &rec_byte, 1);
        counter = 0;
        rec_byte = 0;
    }
    else
    {
        rec_byte = rec_byte << 1;
        counter++;
    }
}   

void send_byte(char byte)
{
    int counter = 0;
    
    while (counter < 8)
    {
        if ((byte & 256) == 256)
            get_byte(SIGUSR2);
            //kill(pid, SIGUSR2);
            // send SIGUSR2
        else 
            get_byte(SIGUSR1);
            // send SIGUSR1
        byte = byte << 1;
        counter++;
    }
}

int main() {

	clock_t start_time, end_time;
    int i = 0;
    char c = 'a';

	start_time = clock();
    while (i <= 100)
    {
        send_byte(c);
        c++;
        i++;
    }
	end_time = clock();
	printf("\n %f", ((double)(end_time - start_time)) / CLOCKS_PER_SEC);
    return (0);
  
}