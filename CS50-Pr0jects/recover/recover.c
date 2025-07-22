#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512
#define FILENAME_SIZE 8

int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open forensic image file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        fprintf(stderr, "Could not open %s for reading.\n", argv[1]);
        return 1;
    }

    // Variables to track JPEG recovery
    uint8_t buffer[BLOCK_SIZE];
    FILE *output_file = NULL;
    char filename[FILENAME_SIZE];
    int jpeg_count = 0;
    int is_jpeg_open = 0;

    // Read blocks until end of file
    while (fread(buffer, BLOCK_SIZE, 1, input_file))
    {
        // Check if the block is the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous JPEG file if open
            if (is_jpeg_open)
            {
                fclose(output_file);
            }
            else
            {
                is_jpeg_open = 1;
            }

            // Create new JPEG file
            sprintf(filename, "%03i.jpg", jpeg_count);
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", filename);
                fclose(input_file);
                return 1;
            }

            // Write block to JPEG file
            fwrite(buffer, BLOCK_SIZE, 1, output_file);
            jpeg_count++;
        }
        else
        {
            // Continue writing to current JPEG file
            if (is_jpeg_open)
            {
                fwrite(buffer, BLOCK_SIZE, 1, output_file);
            }
        }
    }

    // Close files
    fclose(input_file);
    if (is_jpeg_open)
    {
        fclose(output_file);
    }

    return 0;
}
