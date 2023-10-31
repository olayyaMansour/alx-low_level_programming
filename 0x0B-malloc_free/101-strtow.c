#include <stdlib.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *str)
{
    int count = 0;
    int is_word = 0;

    while (*str)
    {
        if (is_space(*str))
        {
            is_word = 0;
        }
        else if (!is_word)
        {
            is_word = 1;
            count++;
        }
        str++;
    }
    return (count);
}

char *duplicate_word(char *str)
{
    char *word;
    int len = 0;

    while (str[len] && !is_space(str[len]))
    {
        len++;
    }
    word = (char *)malloc(len + 1);

    if (word)
    {
        int i;
        for (i = 0; i < len; i++)
        {
            word[i] = str[i];
        }
        word[len] = '\0';
    }

    return (word);
}

char **strtow(char *str)
{
    int words, i;
    char **word_array;

    if (!str || !*str)
    {
        return (NULL);
    }

    words = count_words(str);
    if (words == 0)
    {
        return (NULL);
    }

    word_array = (char **)malloc(sizeof(char *) * (words + 1));
    if (word_array)
    {
        int j;
        int in_word = 0;
        for (i = 0, j = 0; str[i]; i++)
        {
            if (!is_space(str[i]))
            {
                if (!in_word)
                {
                    word_array[j] = duplicate_word(str + i);
                    in_word = 1;
                    if (!word_array[j])
                    {
                        while (j >= 0)
                        {
                            free(word_array[j]);
                            j--;
                        }
                        free(word_array);
                        return (NULL);
                    }
                    j++;
                }
            }
            else
            {
                in_word = 0;
            }
        }
        word_array[words] = NULL;
    }

    return (word_array);
}

