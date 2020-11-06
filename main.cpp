#include <stdio.h>
#include <unistd.h>
#define max 1024

int main(void)
{
    int n;
    char buf[max];
    
    while ((n = read(STDIN_FILENO, buf, max)) > 0)
        
        if (write(STDOUT_FILENO, buf, n) != n)
        err_sys("ошибка записи ");
    
    if (n < 0)
    err_sys("ошибка чтения");
    
    exit(0);
}

