#include <stdio.h>
#include <string.h>

#include "l_system.h"

void insert(LSystem *l_system, Rule rule);
char *match(LSystem *l_system, char pred);

LSystem init_l_system(Rule *rules, int len) {
    if (len > LSYS_SIZE)
        perror("Invalid arg: 0 <= len <= LSYS_SIZE");

    LSystem l_system = { .rules={} };

    memset(&l_system.rules, 0, LSYS_SIZE * sizeof(char *));

    for (int i = 0; i < len; i++) {
        insert(&l_system, rules[i]);
    }

    return l_system;
}

void insert(LSystem *l_system, Rule rule) {
    l_system->rules[(unsigned char) rule.pred] = rule.succ;
}

int is_terminal(LSystem *l_system, char pred) {
    return l_system->rules[(unsigned char) pred] == NULL;
}

/// Applies the given `LSystem` to the `axiom` initiator string. It assumes the string is terminated by a null byte.
/// Writes the result to `buf`, truncating after `len` characters written (`buf` needs `len+1` bytes of space for null byte).
///
/// Does nothing if `len <= 0`.
void apply(LSystem *l_system, char *axiom, char *buf, int len) {
    if (len <= 0) {
        return;
    }

    char *ptr = buf;

    for (int i = 0; axiom[i] != '\0'; i++) {
        if (i == len) {
            break;
        }

        if (is_terminal(l_system, axiom[i])) {
            *ptr = axiom[i];
            ptr++;
        } else {
            char *succ = match(l_system, axiom[i]);
            for (int j = 0; succ[j] != '\0'; j++) {
                if (j == ptr - buf + len)
                    break;

                *ptr = succ[j];
                ptr++;
            }

            if (ptr - buf + len == 0) break;
        }
    }

    *ptr = '\0';
}

char *match(LSystem *l_system, char pred) {
    return l_system->rules[(unsigned char) pred];
}

/// Gets the length of the result of applying `l_system` to `axiom`.
int get_len(LSystem *l_system, char *axiom) {
    int len = 0;
    for (char *ptr = axiom; *ptr != '\0'; ptr++) {
        if (is_terminal(l_system, *ptr)) {
            len++;
        } else {
            len += strlen(match(l_system, *ptr));
        }
    }

    return len;
}
