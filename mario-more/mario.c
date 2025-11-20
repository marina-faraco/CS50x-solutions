#include <cs50.h>
#include <stdio.h>

void row(int space, int bricks);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // print the pyramid
    for (int i = 0; i < height; i++)
    {
        row(height - i - 1, i + 1); // 1° pyramid
        printf("  ");               // gap
        row(0, i + 1);              // 2° pyramid
        printf("\n");
    }
}

void row(int space, int bricks)
{
    // print space
    for (int r = 0; r < space; r++)
    {
        printf(" ");
    }

    // print bricks
    for (int r = 0; r < bricks; r++)
    {
        printf("#");
    }
}
