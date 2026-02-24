#include "stringdin.h"

void strcrear(string &s)
{
    s = new char[1];
    s[0] = '\0';
}

void strdestruir(string &s)
{
    if (s != NULL)
    {
        delete[] s;
        s = NULL;
    }
}

int strlar(const char *s)
{
    if (s == NULL)
        return 0;
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void strcop(string &s1, const char *s2)
{
    if (s2 == NULL)
    {
        if (s1 != NULL)
        {
            delete[] s1;
            s1 = NULL;
        }
        strcrear(s1);
        return;
    }

    if (s1 == s2)
        return;

    if (s1 != NULL)
    {
        delete[] s1;
        s1 = NULL;
    }

    int largo = strlar(s2);
    s1 = new char[largo + 1];
    for (int i = 0; i < largo; i++)
        s1[i] = s2[i];
    s1[largo] = '\0';
}

void scan(string &s)
{
    string aux = new char[MAX];
    int i = 0;
    char c;
    fflush(stdin);
    scanf("%c", &c);
    while (c != '\n' && i < MAX - 1)
    {
        aux[i] = c;
        i++;
        scanf("%c", &c);
    }
    aux[i] = '\0';
    strcop(s, aux);
    strdestruir(aux);
}

void strcon(string &s1, string s2)
{
    int largo1 = strlar(s1);
    int largo2 = strlar(s2);

    string aux = new char[largo1 + largo2 + 1];

    int i = 0;

    for (; i < largo1; i++)
        aux[i] = s1[i];

    for (int j = 0; j <= largo2; j++)
        aux[i + j] = s2[j];

    delete[] s1;
    s1 = aux;
}

void print(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
        printf("%c", s[i]);
    printf("\n");
}

boolean strmen(string s1, string s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] < s2[i])
            return TRUE;
        if (s1[i] > s2[i])
            return FALSE;
        i++;
    }
    if (s1[i] == '\0' && s2[i] != '\0')
        return TRUE;
    else
        return FALSE;
}

boolean streq(string s1, string s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return FALSE;
        i++;
    }

    if (s1[i] == '\0' && s2[i] == '\0')
        return TRUE;
    else
        return FALSE;
}

int strcomp(string a, string b)
{
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] < b[i])
            return -1;
        else if (a[i] > b[i])
            return 1;
        i++;
    }
    if (a[i] == '\0' && b[i] == '\0')
        return 0;
    else if (a[i] == '\0')
        return -1;
    else
        return 1;
}

boolean bajarString(string s, FILE *f)
{
    int largo = strlar(s);
    fwrite(&largo, sizeof(int), 1, f);
    fwrite(s, sizeof(char), largo, f);
    return TRUE;
}

boolean levantarString(string &s, FILE *f)
{
    int largo;
    if (fread(&largo, sizeof(int), 1, f) != 1)
        return FALSE;

    s = new char[largo + 1];
    fread(s, sizeof(char), largo, f);
    s[largo] = '\0';

    return TRUE;
}