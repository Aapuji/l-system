#include <string.h>

#include "lib/l_system.h"
#include "lib/rule.h"

int main(void) {
    Rule rules[2] = {
        init_rule('A', "AB"),
        init_rule('B', "A")
    };

    LSystem l_system = init_l_system(rules, 2);

    char axiom[1024] = "B"; // Lengths of results will be fibonacci sequence
    char result[1024] = "Hello!";

    const int NUM = 10;

    printf("0: %s: %llu\n", axiom, strlen(axiom));
    for (int i = 0; i < NUM; i++) {
        apply(&l_system, axiom, result, 1023);

        printf("%i: %s: %llu\n", i+1, result, strlen(result)); // You can apply some f(result), here it is strlen to get fibonacci
        strcpy(axiom, result);
    }

    return 0;
}
