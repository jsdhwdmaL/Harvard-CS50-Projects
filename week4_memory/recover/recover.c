//Recover jpg images
//This might cause segmentation fault
//Usage (in IDE): ./recover image_name
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *image = fopen(argv[1], "r");
    if (image == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int i = 0;
    FILE *img;
    BYTE buffer[512];
    char filename[10];

    while(fread(buffer, 512, 1, image))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (i != 0)
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", i);
            img = fopen(filename, "w");
            fwrite(buffer, 512, 1, img);
            i++;
        }
        else
        {
            fwrite(buffer, 512, 1, img);
        }
    }
    fclose(image);

}
