#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute_score(string w);
void print_winner(int p1, int p2);

// value of each letter of the alphabet
//             {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z}
const int LETTER_VALUES[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // prompt for input
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // compute the score for each word
    int p1 = compute_score(player1);
    int p2 = compute_score(player2);

    // print the winner
    print_winner(p1, p2);
}

int compute_score(string word)
{
    int len = strlen(word);
    int total = 0;

    for (int pos = 0; pos < len; pos++)
    {
        char w = tolower(word[pos]);

        if (w >= 'a' && w <= 'z')
        {
            int index = w - 'a';
            total += letter_values[index];
        }
    }
    return total;
}

void print_winner(int p1, int p2)
{
        if (p1 > p2)
    {
        printf("Player 1 wins!");
    }
    else if (p1 < p2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
    printf("\n");
}
