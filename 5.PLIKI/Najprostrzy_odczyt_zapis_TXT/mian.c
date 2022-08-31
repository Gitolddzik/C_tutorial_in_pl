#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char* argv[]) 
{

    int x=10;

    FILE* in;
    FILE* out;
    
    char buffer_in[256], buffer_out[256];
    out = fopen("point.dat", "w");
    if (out == NULL) {
        return 1;
    }
    
    snprintf(buffer_out, 256, "%d\n", x);
    size_t bytesWrote = fwrite(buffer_out, sizeof(char), strlen(buffer_out), out);
    fclose(out);
    
    if (bytesWrote != strlen(buffer_out)) {
        return 1;
    }

    int y;
    
    // -- READ --
    in = fopen("point.dat", "r");
    if (in == NULL) {
        return 1;
    }
    
    if (fgets(buffer_in, 256, in) == NULL) 
    {
        fclose(in);
        return 1;
    }
    fclose(in);
    
    sscanf(buffer_in, "%d\n", &y);
    printf("Read from file the point: %d\n", y);
    
    return 0;
}