#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <calc.h>

char* getline(void)
{
    char *line = (char *)malloc(sizeof(char) * 100), *linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;

    if (line == NULL)
    {
        return NULL;
    }

    for (;;)
    {
        c = fgetc(stdin);
        if (c == EOF)
        {
            break;
        }

        if (--len == 0)
        {
            len = lenmax;
            char* linen = realloc(linep, lenmax *= 2);

            if (linen == NULL)
            {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if ((*line++ = c) == '\n')
        {
            break;
        }
    }
    *line = '\0';
    return linep;
}

float takeOPERATION()
{
    float ret = 0;
    char* c = getline();

    if (NULL == c)
    {
        printf("");
        return 0;
    }

    int iter = 0, iter2 = 0;
    int i = 0;

    for (i; i < strlen(c); i++)
    {
        if ('+' == c[i] || '-' == c[i] && ' ' == c[i + 1] || '*' == c[i] || '/' == c[i])
        {
            iter = iter + 1;
        }
        else if (' ' == c[i])
        {
            iter2++;
        }
    }
    char* signs_tab = (char*)malloc(sizeof(char) * iter);
    float* num_tab = (float*)malloc(sizeof(float) * (iter2 / 2) + 1);
    int* num_tab_used = (int*)malloc(sizeof(int) * (iter2 / 2) + 1);

    iter = 0;
    iter2 = 0;
    i = 0;

    for (i; i < strlen(c); i++)
    {
        if (('+' == c[i] || '-' == c[i] || '*' == c[i] || '/' == c[i]) && ' ' == c[i + 1])
        {
            signs_tab[iter] = c[i];
            iter = iter + 1;
        }
        else if (i == 0
            || (c[i - 1] == ' ')
                && ('+' == c[i - 2] || '-' == c[i - 2] || '*' == c[i - 2] || '/' == c[i - 2]))
        {
            num_tab[iter2] = atof(&c[i]);
            iter2++;
        }
        else if (('-' == c[i])
            && ('+' != c[i - 2] || '-' != c[i - 2] || '*' != c[i - 2] || '/' != c[i - 2]))
        {
            ret = 1;
        }
        else if (('+' == c[i] || '*' == c[i] || '/' == c[i]) && ' ' != c[i + 1])
        {
            ret = 1;
        }
    }
    i = 0;
    for (i; i < iter2; i++)
    {
        num_tab_used[i] = 1;
    }

    signs_tab[iter] = '\0';
    i = 0;

    for (i; i < iter; i++)
    {
        if (signs_tab[i] == '*')
        {
            int curr = i, right = i + 1;
            if (num_tab_used[curr] != 0)
            {
                num_tab[curr] *= num_tab[right];
                num_tab_used[right] = 0;
            }
            else if (num_tab_used[right] != 0)
            {
                while (num_tab_used[curr] == 0)
                {
                    curr--;
                }
                num_tab[curr] *= num_tab[right];
                num_tab_used[right] = 0;
            }
        }
        else if ('/' == signs_tab[i] && 0 != num_tab[i + 1])
        {
            int curr = i, right = i + 1;
            if (num_tab_used[curr] != 0)
            {
                num_tab[curr] /= num_tab[right];
                num_tab_used[right] = 0;
            }
            else if (num_tab_used[right] != 0)
            {
                while (num_tab_used[curr] == 0)
                {
                    curr--;
                }
                num_tab[curr] /= num_tab[right];
                num_tab_used[right] = 0;
            }
        }
        else if (0 == num_tab[i + 1])
        {
            ret = 1;
        }
    }
    if (ret == 0)
    {
        i = 0;

        for (i; i < iter; i++)
        {
            if (signs_tab[i] == '-')
            {
                int curr = i, right = i + 1;
                if (num_tab_used[curr] != 0)
                {
                    num_tab[curr] -= num_tab[right];
                    num_tab_used[right] = 0;
                }
                else if (num_tab_used[right] != 0)
                {
                    while (num_tab_used[curr] == 0)
                    {
                        curr--;
                    }
                    num_tab[curr] -= num_tab[right];
                    num_tab_used[right] = 0;
                }
            }
            if (signs_tab[i] == '+')
            {
                int curr = i, right = i + 1;
                if (num_tab_used[curr] != 0)
                {
                    num_tab[curr] += num_tab[right];
                    num_tab_used[right] = 0;
                }
                else if (num_tab_used[right] != 0)
                {
                    while (num_tab_used[curr] == 0)
                    {
                        curr--;
                    }
                    num_tab[curr] += num_tab[right];
                    num_tab_used[right] = 0;
                }
            }
        }
    }
    i = 0;
    iter = 0;
    iter2 = 0;

    result = num_tab[0];
    free(num_tab);
    free(signs_tab);
    free(num_tab_used);
    free(c);

    return ret;
}

