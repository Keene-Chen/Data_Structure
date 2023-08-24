/**
 * @file    : String.c
 * @author  : KeeneChen
 * @date    : 2023.08.24-15:42:57
 * @details : String
 */

#include <stdio.h>
#include <string.h>

#define MANLEN 100

typedef struct {
    char ch[100];
    int len;
} String;

String *strCat(String *s, String *t);

int main(void)
{
    String *str1;
    strcpy(str1->ch, "abcd");
    str1->len = strlen(str1->ch);

    printf("%s", str1->ch);
    // puts(str1->ch);

    return 0;
}

String *strCat(String *s, String *t)
{
    if (s->len + t->len <= MANLEN) {
        for (int i = s->len; i < s->len + t->len; i++) {
            s->ch[i] = t->ch[i - s->len];
        }
        s->len += t->len;
        return s;
    }
    else if (s->len < MANLEN) {
        for (int i = s->len; i < MANLEN; i++) {
            s->ch[i] = t->ch[i - s->len];
        }
        s->len = MANLEN;
        return s;
    }
    else
        return s;
}