#include "shell.h"
/*
* err_msg: prints error message to the terminal
* @prg: count
* @address: command
* @i: int variable
* return: -1
*/
int err_msg(char *prg, char **address, int i)
{
   static int x = 1;
    
    if(!i)
    x++;
    
    if(i)
    {
        write(2, prg, my_strlen(prg));
        write(2, ": ", my_strlen(": "));
        print_int(x);
    }


    if(i == 1)
    {
        write(2, ": ", my_strlen(": "));
        write(2, address[0], my_strlen(address[0]));
        write(2, ": Fork failed\n", my_strlen(": Forkfailed\n"));

    }

    if(i == 2)
    {
        write(2, ": ", my_strlen(": "));
        write(2, address[0], my_strlen(address[0]));
        write(2, ": No such file or directory\n", my_strlen(": No such file or directory\n"));

    }

     if(i == 3)
    {
        write(2, ": ", my_strlen(": "));
        write(2, address[0], my_strlen(address[0]));
        write(2, ": not found\n", my_strlen(": not found\n"));

    }

    return(-1);

}


/*
* print_int: custom function to print an interger
* @number: interger
* return: value
*/
int print_int(int numb)
{
    char y;
    if (numb > 9)
    {
        return (print_int(numb / 10) + print_int(numb % 10));
    }
    
    y = '0' + numb;

    return (write(2, &y, 1));
}
