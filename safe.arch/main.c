#include <stdio.h>
#include <stdlib.h>

#include "./../include/libstream.h"

int main(void)
{
    struct stream *my_stream;

    // Test: Open a file for writing
    my_stream = lbs_fopen("testfile.txt", "w");
    if (!my_stream)
    {
        perror("Failed to open file for writing");
        return 1;
    }

    // Test: Write characters to the file using lbs_fputc
    const char *message =
        "Hello, World!\nJe suis fatiguer\na la mort\nmais je ne "
        "laisserais\npas tomber\ncar je suis le meilleur\n";
    for (int i = 0; message[i] != '\0'; i++)
    {
        if (lbs_fputc(message[i], my_stream) == LBS_EOF)
        {
            perror("Error writing to file");
            lbs_fclose(my_stream);
            return 1;
        }
    }

    // Test: Flush the buffer
    if (lbs_fflush(my_stream) == LBS_EOF)
    {
        perror("Error flushing the stream");
        lbs_fclose(my_stream);
        return 1;
    }

    // Test: Close the file
    if (lbs_fclose(my_stream) == LBS_EOF)
    {
        perror("Error closing the file");
        return 1;
    }

    // Test: Open the file for reading
    my_stream = lbs_fopen("testfile.txt", "r");
    if (!my_stream)
    {
        perror("Failed to open file for reading");
        return 1;
    }

    // Test: Read characters from the file using lbs_fgetc
    int c;
    printf("Reading from file:\n");
    while ((c = lbs_fgetc(my_stream)) != LBS_EOF)
    {
        putchar(c);
    }

    // Test: Close the file
    if (lbs_fclose(my_stream) == LBS_EOF)
    {
        perror("Error closing the file");
        return 1;
    }

    return 0;
}
