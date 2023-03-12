#include "klist.h"
#include "assert.h"
#include "string.h"

DEF_KLIST_PROTO(char *, strpair); 
DEF_KLIST(char *, strpair, 0); 

int main()
{
    strpair    *sl;

    sl = 0;
    assert(!strpair_get(sl, "test"));
    strpair_set(&sl, "test", "lol");
    assert(!strcmp(strpair_get(sl, "test"), "lol"));
    printf ("OK\n");
}