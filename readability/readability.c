#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_grade(int letters, int words, int sentences);
void print_grade(int index);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int index = calculate_grade(letters, words, sentences);

    // Compute the Coleman-Liau index

    // Print the grade level
    print_grade(index);
}

int count_letters(string text)
{
    int len = strlen(text);
    int letters = 0;

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int len = strlen(text);
    int words = 1;

    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int len = strlen(text);
    int sentences = 0;

    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

int calculate_grade(int letters, int words, int sentences)
{

    float l = ((float) letters / words) * 100;
    float s = ((float) sentences / words) * 100;
    int index = round(0.0588 * l - 0.296 * s - 15.8);
    return index;
}

void print_grade(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
