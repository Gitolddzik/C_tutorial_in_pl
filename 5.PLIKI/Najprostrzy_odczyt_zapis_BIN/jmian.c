#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int x=10, y;


int main(int argc, char* argv[]) {
   
    FILE* in;
    FILE* out;
    
    out = fopen("point.bin", "wb");
    if (out == NULL) {
        return 1;
    }
    
    size_t elements_written = fwrite(&x, sizeof(x), 1, out);
    fclose(out);
    if (elements_written == 0) {
        return 2;
    }
    
    in = fopen("point.bin", "rb");
    if (in == NULL) {
        return 3;
    }
    
    size_t elements_read = fread(&y, sizeof(y), 1, in);
    fclose(in);
    if (elements_read == 0) {
        return 4;
    }
    
    printf("Point read from binary file: %d \n", y);
    
    return 0;
}