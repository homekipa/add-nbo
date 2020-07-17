#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage : ./add-nbo <file1> <file2>\n");
        return 0;
    }
    FILE *file1, *file2;
    uint32_t buf[2] = {0,};

    if((file1 = fopen(argv[1], "rb")) == NULL)
    {
        printf("<file1> fopen error!\n");
        return 0;
    }

    if((file2 = fopen(argv[2], "rb")) == NULL)
    {
        printf("<file2> fopen error!\n");
        return 0;
    }

    fread(&buf[0], sizeof(uint32_t), 1, file1);
    buf[0] = ntohl(buf[0]);

    fread(&buf[1], sizeof(uint32_t), 1, file2);
    buf[1] = ntohl(buf[1]);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", buf[0], buf[0], buf[1], buf[1], (buf[0]+buf[1]), (buf[0]+buf[1]));

    fclose(file1);
    fclose(file2);

    return 0;
}
