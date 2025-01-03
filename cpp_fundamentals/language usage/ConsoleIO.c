#include "stdio.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {

    // printf, scanf, puts, putchar, getchar

    // scanf and printf
    // format specifiers: %c, %d, %f, %s, %x, %%
    char* name = "Cheng-Lin Wu";
    float height = -1;
    printf("Hello %s, please enter you height: ", name);
    scanf("%f", &height);
    printf("\t --> The user %s is %.2f cm tall.\n", name, height);

    // read a string (may include spaces) from console using fgets(..., stdin)
    clear_input_buffer(); // make sure to clear out the residual value in the stdin, such as '\n'
    char str[20]; // Buffer to store the input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Reads up to sizeof(str)-1 characters
    printf("You entered: %s\n", str);
    
    // puts() automatically prints a newline at the end
    puts("Print it again using puts():");
    puts(str);

    // getchar() doesn't take any parameter
    printf("Change the first char of str to: ");
    str[0] = getchar();
    printf("\t --> New string: %s \n", str);

    return 0;
}