#include <stdio.h>
#include <stdlib.h>

#pragma pack(1) // Disable padding

typedef struct {
    unsigned char signature[2];
    unsigned int fileSize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int dataOffset;
} BMPHeader;

typedef struct {
    unsigned int size;
    int width, height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    int xPixelsPerMeter, yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int importantColors;
} DIBHeader;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;

void convertToGrayscale(Pixel *pixel) {
    unsigned char gray = (unsigned char)(0.299 * pixel->red + 0.587 * pixel->green + 0.114 * pixel->blue);
    pixel->red = pixel->green = pixel->blue = gray;
}

int main() {
    FILE *file = fopen("nature.bmp", "rb");
    if (!file) {
        printf("Could not open file.\n");
        return 1;
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, file);

    DIBHeader dibHeader;
    fread(&dibHeader, sizeof(DIBHeader), 1, file);

    fseek(file, bmpHeader.dataOffset, SEEK_SET);

    Pixel *pixels = (Pixel *)malloc(dibHeader.imageSize);
    fread(pixels, dibHeader.imageSize, 1, file);
    fclose(file);

    for (int i = 0; i < dibHeader.width * dibHeader.height; i++) {
        convertToGrayscale(&pixels[i]);
    }

    file = fopen("grayscale.bmp", "wb");
    if (!file) {
        printf("Could not open file.\n");
        free(pixels);
        return 1;
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&dibHeader, sizeof(DIBHeader), 1, file);
    fwrite(pixels, dibHeader.imageSize, 1, file);

    fclose(file);
    free(pixels);

    printf("Image converted to grayscale.\n");
    return 0;
}
