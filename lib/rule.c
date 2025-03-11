#include "rule.h"

Rule init_rule(char predecessor, char *successor) {
    return (Rule) {
        .pred=predecessor,
        .succ=successor
    };
}
