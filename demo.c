#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int authenticated = 0;
    char buf[8];

    printf("&buf = %p, &authenticated = %p\n", (void *)buf, (void *)&authenticated);
    strcpy(buf, argv[1]);   // no bounds check!

    printf("buf = \"%s\"\n", buf);
    printf("authenticated = %d\n", authenticated);
    if (authenticated) printf("ACCESS GRANTED\n");
    else printf("access denied\n");
    return 0;
}
