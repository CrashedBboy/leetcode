int main(void) {

    char str1[] = "String 1";
    // or str1[50] = "String 1" also works

    // a null-terminator will be appended at the end

    // avoid the declare a string like below:
    char str2[50] = {'A', 'B', 'C'};
    // because there's no null-terminator '\0', the printf("%s") may lead to undefined behavior because 
    // it relies on the presence of null-terminator.


    return 0;
}