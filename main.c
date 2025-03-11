#include "lib/l_system.h"
#include "lib/rule.h"

int main(void) {
    Rule rules[2] = {
        init_rule('A', "BB"),
        init_rule('B', "AB")
    };

    LSystem l_system = init_l_system(rules, 2);

    char *axiom = "ABC"; // Expected BBABC
    char result[100];

    apply(&l_system, axiom, result, 99);

    printf("axiom: %s\nresult: %s", axiom, result);

    return 0;
}
