#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char **argv) {
	FILE *p1, *p2;
	uint32_t num1, num2;

	if (argc != 3) {
		printf("INPUT EXAMPLE : ./add-nbo <FILE1> <FILE2>\n");
		exit(1);
	}

	if ((p1 = fopen(argv[1], "rb")) == NULL) {
		fputs("File error\n", stderr);
		exit(2);
	}

	if ((p2 = fopen(argv[2], "rb")) == NULL) {
		fputs("File error\n", stderr);
		exit(2);
	}

	fread(&num1, sizeof(num1), 1, p1);
	fread(&num2, sizeof(num2), 1, p2);

	fclose(p1);
	fclose(p2);

	num1 = htonl(num1);
	num2 = htonl(num2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1+num2, num1+num2);

	return 0;
	
}

