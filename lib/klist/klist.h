#ifndef keystr_H
# define keystr_H
# include "../ft/ft.h"
# include "../list/list.h"
# define DEF_KLIST_PROTO(TYPE, NAME)        \
                                            \
typedef struct s_##NAME##_entry     {       \
    const char  *key;                       \
    TYPE        value;                      \
} NAME##_entry;                             \
                                            \
DEF_LIST_PROTO(NAME##_entry*, NAME);        \
                                            \
int     NAME ##_set(NAME **map, const char *key, TYPE value);\
TYPE    NAME ##_get(NAME *map, const char *key);\

# define DEF_KLIST(TYPE, NAME, FREEF)       \
                                            \
DEF_LIST(NAME##_entry*, NAME, FREEF)        \
                                            \
int         NAME ## _set(NAME **map, const char *key, TYPE value)\
{                                           \
    NAME    *l;                             \
                                            \
    l = *map;                               \
    while (l)                               \
    {                                       \
        if (!strcmp(l->data->key, key))     \
        {                                   \
            l->data->value = value;         \
            return 1;                       \
        }                                   \
        l = l->next;                        \
    }                                       \
    NAME##_add(map, NAME ## _new(alloc(NAME ## _entry, .key=key, .value=value)));\
    return 1;                               \
}                                           \
                                            \
TYPE    NAME##_get(NAME *map, const char *key)\
{                                           \
    NAME    *l;                             \
                                            \
    l = map;                                \
    while (l)                               \
    {                                       \
        if (!strcmp(l->data->key, key))     \
            return l->data->value;          \
        l = l->next;                        \
    }                                       \
    return 0;                               \
}                                   

#endif
