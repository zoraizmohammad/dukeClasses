//Mohammad Zoraiz - ECE250

#include <stdio.h>
#include <stdlib.h>

//recursive function
int recurse(int multiplier) 
{

    if (multiplier == 0) 
    {
        return 2;
    } 
    
    else
    {
        return (3*multiplier)-2*recurse(multiplier-1)+7;
    }

}

//main function
int main(int argc, char *argv[]) 
{
    //edge case for wrong amount of arguements
    if (argc != 2) 
    {
        return EXIT_FAILURE;
    }

    int multiplier;

    sscanf(argv[1], "%d", &multiplier);

    //edge case for negative numbers
    if (multiplier < 0) 
    {
        return EXIT_FAILURE;
    }

    //calling on recursive method
    int final = recurse(multiplier);

    //print & return
    printf("%d\n", final);

    return EXIT_SUCCESS;
}