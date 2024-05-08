//Final Project
//Paige Krueger & Yael Collazo Osorio

#include <stdio.h>
#include <stdbool.h>

#define MAXw 500
#define MAXh 500

void ogMenu(char *choice);
void uploadimage(char image[][MAXh], int imageWidth[MAXw], int imageHeight[MAXh]);
void displayimage(char image[][MAXh], int imageWidth[MAXw], int imageHeight[MAXh]);
void editMenu(char *echoice);
void cropimage(int imageWidth[MAXw], int imageHeight[MAXh], char image[][MAXh]);
void brightenimage(char image[][MAXh]);
void dimimage(char image[][MAXh]);
void done(char *fchoice, int imageWidth[MAXw], int imageHeight[MAXh], char image[][MAXh]);

int main(){

	char image[MAXw][MAXh];
	int imageHeight[MAXh];
	int imageWidth[MAXw];
	char choice;
	char echoice;
	char fchoice;

	do{
	ogMenu(&choice);

		if(choice == '1'){
			uploadimage(image, imageWidth, imageHeight);} 
		else if(choice == '2'){
			displayimage(image, imageWidth, imageHeight);}
		else if(choice == '3'){
			do{
			editMenu(&echoice);
		
			if (echoice == '1'){
				cropimage(imageWidth, imageHeight, image);}
			else if (echoice == '2'){
	  			dimimage(image);}
			else if (echoice == '3'){
	 			brightenimage(image);}
			else if(echoice == '0'){
				}
			}
			while(echoice == '1' || echoice == '2' || echoice == '3');}
		else if(echoice == '0'){
		done(&fchoice, imageWidth, imageHeight, image);
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
	


void uploadimage(char image[][MAXh], int imageWidth[MAXw], int imageHeight[MAXh]){	
	int index = 0;
	while(fscanf(dest_fp, " %c %c", &image[index][MAXw], &image[index][MAXh]) == 2
		index++;}
		return index;
		}
	


void displayimage(char image[][MAXh], int imageWidth[], int imageHeight[]){
	
	for(int MAXwI = 0; MAXwI < MAXw; MAXwI++){
		printf(" %c %c", &image[MAXwI][MAXw], &image[MAXwI][MAXh]);
		}}
	
	
	
	

void cropimage(int imageWidth[MAXw], int imageHeight[MAXh], char image [][MAXh]){	
char brightness[5] = {' ', '.','o','O','0'};	
	int croppedWidth, croppedHeight;
	
	printf("Enter how much coordinates you would like to crop\n");
		scanf("%d  %d", &croppedHeight, &croppedWidth);
			
			imageHeight[0] -= croppedHeight;
			imageWidth[0] -= croppedWidth;
		}

void dimimage(char image[][MAXh]){
char brightness[5] = {' ', '.','o','O','0'};
	char db, currentchar;
	int dimm, bright;
	
	printf("Enter how much you would like dimmed (0-4)\n");
	scanf("%d", &dimm);
	
	char dimarray[5] = {' ','.','o','O','0'};
	for (int i = 0; i < MAXw; i++){
	for (int l = 0; l < MAXh; l++){
		 currentchar = image[i][l];
		 bright = currentchar - 'O';
		 
		 bright -= dimm;
	image[i][l] = bright[dimarray];
	}
}
	printf("Image dimmed\n");
}

void brightenimage(char image[][MAXh]){
	int brighten, brit;
	char current;
	char brightness[5] = {' ', '.','o','O','0'};
	printf("How much would you like to be brightened (0-4)\n");
	scanf("%d", &brighten);
	
	for (int i = 0; i < MAXw; i++){
	for (int l = 0; l < MAXh; l++){
		 current = image[i][l];
		 brit = current - 'O';
		 
		brit += brighten; 
	image[i][l] = brightness[brit];
	}
	  }
	printf("Image Brightened\n");
	}


void done(char *fchoice, int imageWidth[MAXw], int imageHeight[MAXh], char image[][MAXh]){

	printf("Do you want to save your image? [Y/N]: ");
  	scanf(" %c", fchoice); 
do{

if(*fchoice == 'Y' || *fchoice == 'y'){
char FILE_NAME[MAXh];
FILE* dest_fp;

	do{
        	printf("Enter the file name to save: ");
        	fgets(FILE_NAME, sizeof(FILE_NAME), stdin);
		
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
    

