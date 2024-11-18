//Mohammad Zoraiz

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    //Counter Variable
    long long counter;


    //Scanning in Variable
    if(sscanf(argv[1], "%lld", &counter) != 1)
    {
        return EXIT_FAILURE;
    }

    if (counter <= 0) 
    {
        return EXIT_FAILURE;
    }

    //Initialization
    long long first = 1;
    long long second = 1;
    long long third = 2;

    //Total
    long long total = 3;

    if (counter >= 1) printf("%lld\n", first);
    if (counter >= 2) printf("%lld\n", second);
    if (counter >= 3) printf("%lld\n", third);

    //Adding it all together
    for (long long x = 4; x <= counter; x++) 
    {
        total = first + second + third;
        printf("%lld\n", total);

        first = second;
        second = third;
        third = total;
    }

    return EXIT_SUCCESS;
}