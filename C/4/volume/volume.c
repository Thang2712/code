// Modifies the volume of an audio file

#include <stdint.h>     // For fixed-width integer types(e.g., uint8_t, int16_t)
#include <stdio.h>      // For file input/output functions
#include <stdlib.h>     // For atof() to convert string to float

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // ------------------------
    // Step 1: Validate command-line arguments
    //-------------------------

    if (argc != 4)
    {
        // Programming requires 3 arguments: input file, output file, and factor
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }
    //--------------------
    // Step 2: Open input.wav file
    //--------------------

    FILE *input = fopen(argv[1], "r");  // Open file in read mode
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;   // Exit if file does not exist or cannot be read
    }   
    // ----------------------
    // Step 3: Open output.wav file
    // ----------------------

    FILE *output = fopen(argv[2], "w"); // Open file in write mode
    if (output == NULL)
    {
        printf("Could not open file.\n");
        fclose(input);  // Close input before existing to avoid leaks 
        return 1;
    }

    // ----------------------------
    // Step 4: Read volume scaling factor from argument
    // ----------------------------

    float factor = atof(argv[3]);   // Convert string to float (e.g., "2.0"->2.0)
    // ----------------------
    // Step 5: Copy .wav header unchanged
    // ----------------------
    // The first 44 bytes of a .wav file are the header (metadata)
    // These must remain unchanged to the output file is still a valid .wav file

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);       // Read header from input
    fwrite(header, HEADER_SIZE, 1, output);     // Write header to output
    // TODO: Read samples from input file and write updated data to output file
    // -------------------------
    // Step 6 : Process audio samples
    // -------------------------
    // Each audio sample is stored as a 16-bit signed integer (int16_t)
    // We'll read one sample at a time, multiply it by the factor,
    // and then write it to the output file
    int16_t buffer; 
    
    // Read samples until end of file
    while (fread(&buffer, sizeof(int16_t), 1, input) != 0)
    {
        // Modify the sample amplitude by scaling with factor
        // Update volume of sample
        buffer *= factor;

        // Writed modified sample to output file
        // Write updated sample to a new file
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }


    // ------------------------
    // Step 7: Close both files 
    // ------------------------

    // Close files
    fclose(input);
    fclose(output);

    // Successful execution 
    return 0; 
}
