#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

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

void blurImage(Pixel *pixels, int width, int height) {
    Pixel *tempPixels = (Pixel *)malloc(width * height * sizeof(Pixel));
    int radius = 1; // Radius of the blur effect

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int rSum = 0, gSum = 0, bSum = 0;
            int count = 0;

            // Iterate over the kernel
            for (int ky = -radius; ky <= radius; ky++) {
                for (int kx = -radius; kx <= radius; kx++) {
                    int px = x + kx;
                    int py = y + ky;

                    // Check if pixel is within bounds
                    if (px >= 0 && px < width && py >= 0 && py < height) {
                        Pixel *p = &pixels[py * width + px];
                        rSum += p->red;
                        gSum += p->green;
                        bSum += p->blue;
                        count++;
                    }
                }
            }

            // Average the sum to get the blurred value
            tempPixels[y * width + x].red = rSum / count;
            tempPixels[y * width + x].green = gSum / count;
            tempPixels[y * width + x].blue = bSum / count;
        }
    }

    // Copy the blurred image back to the original pixel array
    for (int i = 0; i < width * height; i++) {
        pixels[i] = tempPixels[i];
    }

    free(tempPixels);
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

    // Convert to grayscale
    for (int i = 0; i < dibHeader.width * dibHeader.height; i++) {
        convertToGrayscale(&pixels[i]);
    }

    // Save the grayscale image
    file = fopen("grayscale.bmp", "wb");
    if (!file) {
        printf("Could not crreate file.\n");
        free(pixels);
        return 1;
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&dibHeader, sizeof(DIBHeader), 1, file);
    fwrite(pixels, dibHeader.imageSize, 1, file);

    fclose(file);

    // Apply blur to the grayscale image
    blurImage(pixels, dibHeader.width, dibHeader.height);

    // Save the blurred grayscale image
    file = fopen("blurred.bmp", "wb");
    if (!file) {
        printf("Could not create file.\n");
        free(pixels);
        return 1;
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&dibHeader, sizeof(DIBHeader), 1, file);
    fwrite(pixels, dibHeader.imageSize, 1, file);

    fclose(file);
    free(pixels);

    printf("Grayscale and blurred successful.\n");
    return 0;
}
