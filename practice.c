#include <stdio.h>

#define MAXw 500
#define MAXh 500

void uploadimage(char image[][MAXh], int *imageWidth, int *imageHeight);
void displayimage(char image[][MAXh], int imageWidth, int imageHeight);

int main() {
    char image[MAXw][MAXh];
    int imageHeight;
    int imageWidth;

    uploadimage(image, &imageWidth, &imageHeight);
    displayimage(image, imageWidth, imageHeight);

    return 0;
}


void uploadimage(char image[][MAXh], int imageWidth[MAXw], int imageHeight[MAXh]){	
char FILE_NAME[MAXh];
char brightness[5] = {' ', '.','o','O','0'};

	printf("Enter your file name : ");
	
	if(scanf("%s", FILE_NAME) != 1){
		printf("Error reading file name. \n");
		return;}

	FILE *readFilePointer = fopen(FILE_NAME, "r");
	
	if(readFilePointer == NULL){
		printf("Input file does not exist.\n");}
	else{for (int i = 0; i < imageWidth[MAXw]; i++){
		for (int l = 0; l < imageHeight[MAXh]; l++){
			fscanf(readFilePointer, " %c", &image[i][l]);
		}}
		fclose(readFilePointer);
		printf("Image uploaded\n");
		}
		
	}

void displayimage(char image[][MAXh], int imageW, int imageH){

	for (int i= 0; i < MAXw; i++){
		for (int l = 0; l < MAXh; l++){
		
		switch (image[i][l]){
		case 0:
			printf(" ");
			break;
		case 1:
			printf(".");
			break;
		case 2:
			printf("o");
			break;
		case 3:
			printf("O");
			break;
		case 4:
			printf("0");
			break;
		default: 
			printf(" ");
			break;
			}}
			printf("\n");
			}}
