//Final Project
//Paige Krueger & Yael Collazo Osorio

#include <stdio.h>

#define MAX_WIDTH 500
#define MAX_HEIGHT 500

void ogMenu(char *choice);
void uploadimage(FILE *dest_fp, int *MAXh, int *MAXw, char string[], char image[][MAX_HEIGHT]);
void displayimage(FILE *fp ,char image[][MAX_HEIGHT], int imageWidth[][MAX_HEIGHT], int imageHeight[][MAX_HEIGHT]);
void editMenu(char *echoice);
void cropimage(int *imageWidth, int *imageHeight, char image[][MAX_HEIGHT]);
void brightenimage(char image[][MAX_HEIGHT]);
void dimimage(char image[][MAX_HEIGHT]);
void done(char *fchoice, int imageWidth[MAX_WIDTH], int imageHeight[MAX_HEIGHT], char image[][MAX_HEIGHT]);


int main(){

	char image[MAX_WIDTH][MAX_HEIGHT];
	int imageHeight[MAX_HEIGHT][MAX_WIDTH];
	int imageWidth[MAX_WIDTH][MAX_HEIGHT] ;
	FILE *dest_fp;
	FILE *fp;
	int MAXh, MAXw;
	char string [MAX_HEIGHT];
	char choice;
	char echoice;
	char fchoice;

	do{
	ogMenu(&choice);

		if(choice == '1'){
			uploadimage(dest_fp, &MAXh, &MAXw, string, image);} 
		else if(choice == '2'){
			displayimage(fp,image, imageWidth, imageHeight);}
		else if(choice == '3'){
			do{
			editMenu(&echoice);
		
			if (echoice == '1'){
				cropimage(&imageWidth[0][0], &imageHeight[0][0], image);}
			else if (echoice == '2'){
	  			dimimage(image);}
			else if (echoice == '3'){
	 			brightenimage(image);}
			else if(echoice == '0'){
				}
			}
			while(echoice == '1' || echoice == '2' || echoice == '3');}
		else if(echoice == '0'){
		done(&fchoice, &imageWidth[0][0], &imageHeight[0][0], image);
		}
	}
	while(choice == '1' || choice == '2' || choice == '3');



	return 0;
	}



void ogMenu(char *choice){
		do{
		printf("**ERINSTAGRAM**\n1: Load image\n2: Display image\n3: Edit image\n0: Exit\nChoose from one of the options above: ");
			scanf(" %c", choice);
		if(*choice != '1' && *choice !='2' && *choice != '3' && *choice != '0'){
			printf("Invalid Choice\n");}
		}
		while(*choice != '1' && *choice !='2' && *choice != '3' && *choice != '0');
	}
	
	

void editMenu(char *echoice){
	do{
		printf("1: Crop Image \n2: Dim Image\n3: Brighten Image\n0: Exit\nChoose from one of the options above: ");
		scanf(" %c", echoice);
	if(*echoice != '1' && *echoice !='2' && *echoice != '3' && *echoice != '0'){
		printf("Invalid Choice\n");}
		}
	while(*echoice != '1' && *echoice !='2' && *echoice != '3' && *echoice != '0');
	}
	


void uploadimage(FILE *dest_fp, int *MAXh, int *MAXw, char string[], char image[][MAX_HEIGHT]){	
	int allrows = 0, allcolumns = 0;
	char input;
	
	printf("File name? ");
	scanf("%s", string);
	
	dest_fp = fopen(string, "r");
	printf("Image Uploaded\n");
	
	if (dest_fp == NULL){
		printf("ERROR\n");
		return;
		}
	}


void displayimage(FILE *fp, char image[][MAX_HEIGHT], int imageWidth[][MAX_HEIGHT], int imageHeight[][MAX_HEIGHT]){
    for (int i = 500; i < imageWidth[0][0]; i++) {
        for (int l = 500; l < imageHeight[0][0]; l++) {
            switch (image[i][l]) {
                case 0:
                    fprintf(fp, " ");
                    break;
                case 1:
                    fprintf(fp, ".");
                    break;
                case 2:
                    fprintf(fp, "o");
                    break;
                case 3:
                    fprintf(fp, "O");
                    break;
                case 4:
                    fprintf(fp, "0");
                    break;
                default:
                    fprintf(fp, " ");
                    break;
            }
        }
        fprintf(fp, "\n");
    }
}
	

void cropimage(int imageWidth[MAX_WIDTH], int imageHeight[MAX_HEIGHT], char image [][MAX_HEIGHT]){	
char brightness[5] = {' ', '.','o','O','0'};	
	int croppedWidth, croppedHeight;
	
	printf("Enter how much coordinates you would like to crop\n");
		scanf("%d  %d", &croppedHeight, &croppedWidth);
			
			imageHeight[0] -= croppedHeight;
			imageWidth[0] -= croppedWidth;
		}

void dimimage(char image[][MAX_HEIGHT]){
char brightness[5] = {' ', '.','o','O','0'};
	char db, currentchar;
	int dimm, bright;
	
	printf("Enter how much you would like dimmed (0-4)\n");
	scanf("%d", &dimm);
	
	char dimarray[5] = {' ','.','o','O','0'};
	for (int i = 0; i < MAX_WIDTH; i++){
	for (int l = 0; l < MAX_HEIGHT; l++){
		 currentchar = image[i][l];
		 bright = currentchar - 'O';
		 
		 bright -= dimm;
	image[i][l] = bright[dimarray];
	}
}
	printf("Image dimmed\n");}

void brightenimage(char image[][MAX_HEIGHT]){
	int brighten, brit;
	char current;
	char brightness[5] = {' ', '.','o','O','0'};
	printf("How much would you like to be brightened (0-4)\n");
	scanf("%d", &brighten);
	
	for (int i = 0; i < MAX_WIDTH; i++){
	for (int l = 0; l < MAX_HEIGHT; l++){
		 current = image[i][l];
		 brit = current - 'O';
		 
		brit += brighten; 
	image[i][l] = brightness[brit];
	}
	  }
	printf("Image Brightened\n");
	}


void done(char *fchoice, int imageWidth[MAX_WIDTH], int imageHeight[MAX_HEIGHT], char image[][MAX_HEIGHT]){

	printf("Do you want to save your image? [Y/N]: ");
  	scanf(" %c", fchoice); 
do{

	if(*fchoice == 'Y' || *fchoice == 'y'){
	char FILE_NAME[MAX_HEIGHT];
	FILE* dest_fp;

	do{
        	printf("Enter the file name to save: ");
        	scanf("%s", FILE_NAME);
		
		dest_fp = fopen(FILE_NAME, "w");

		if (dest_fp == NULL) {
   			 printf("Can't open file\n");} 
   		else{
    			for (int i = 0; i < imageWidth[0]; i++){
        			for (int l = 0; l < imageHeight[0]; l++) {
            				fprintf(dest_fp, " %c", image[i][l]);
            				}
        	fprintf(dest_fp, "\n");
        	
        	
        	}
    			printf("Image saved successfully.\n");
    				fclose(dest_fp);}
	}
	while(dest_fp == NULL);}

	else if(*fchoice == 'N' || *fchoice == 'n'){
        printf("Goodbye!\n");} 
	else{
        printf("Invalid choice.\n");}
	}
	while(*fchoice != 'Y' && *fchoice !='y' && *fchoice != 'N' && *fchoice != 'n');
    }
    

