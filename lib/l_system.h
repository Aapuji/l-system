#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <stdio.h>

#include "rule.h"

#define LSYS_SIZE 256

typedef struct {
    char *rules[LSYS_SIZE];
} LSystem;

LSystem init_l_system(Rule *rules, int len);
void apply(LSystem *l_system, char *axiom, char *buf, int len);
int get_len(LSystem *l_system, char *axiom);

#endif

