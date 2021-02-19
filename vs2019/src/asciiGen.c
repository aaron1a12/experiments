#include <stdio.h>
#include "libbmp.h"
#include "cs50.h"

#include <math.h>

int main(int argc, char* argv[])
{
	const char* ascii = "@MBHENR#KWXDFPQASUZbdehx*8Gm&04LOVYkpq5Tagns69owz$CIu23Jcfry%1v7l+it[] {}?j|()=~!-/<>\"^_';,:`. ";

	if (argc < 2) {
		printf("Please include image in cmd args.");
		return 0;
	}

	bmp_img img;
	int error = bmp_img_read(&img, argv[1]);

	if (error != 0)
	{
		printf("Error reading BMP. Code: %i\n", error);
		return 0;
	}

	for (int y = 0, nPixels = img.img_header.biHeight;
		y < nPixels; y++)
	{
		for (int x = 0; x < img.img_header.biWidth; x++)
		{
			int color = 255 - img.img_pixels[y][x].red;
			const char* test = ".w#";

			// normalize to our character set
			float multiplier = ((float)95 / 255);

			printf("%c ", ascii[(int)round(color * multiplier)]);
		}

		printf("\n");
	}
}
