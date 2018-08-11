#include <stdio.h>
int main(int argc, char* argv[]) {
    int length=0;
    for (int i=0;argv[1][i] != '\0';i++) length++;
    printf("%d \n",length);
    return 0;
}
