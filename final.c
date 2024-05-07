//Final Project
//Paige Krueger & Yael Collazo Osorio

#include <stdio.h>

#define MAXw 500
#define MAXh 500

void ogMenu(char *choice);
void uploadimage(char image[][MAXh]);
void displayimage(char image[][MAXh], char imageWidth[MAXw], char imageHeight[MAXh]);
void editMenu(char *echoice);
void cropimage(char imageWidth[MAXw], char imageHeight[MAXh], char image[][MAXh]);
void brightenimage(char image[][MAXh]);
void dimimage(char image[][MAXh]);
void done(char *fchoice, char imageWidth[MAXw], char imageHeight[MAXh], char image[][MAXh]);

int main(){

	char image[MAXw][MAXh];
	char imageHeight[MAXh];
	char imageWidth[MAXw];
	char choice;
	char echoice;
	char fchoice;

	do{
	ogMenu(&choice);

		if(choice == '1'){
			uploadimage(image);} 
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
		if(fchoice == 'Y' || fchoice == 'y'){
		}
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
	


void uploadimage(char image[][MAXh]){	
char FILE_NAME[MAXh];

	printf("Enter your file name : ");
	scanf("%s", FILE_NAME);

	FILE *readFilePointer = fopen(FILE_NAME, "r");
	
	if(readFilePointer == NULL){
		printf("Input file does not exist.\n");}
	else{for (int i = 0; i < MAXw; i++){
		for (int l = 0; l < MAXh; l++){
			fscanf(readFilePointer, " %c", &image[i][l]);
		}}}
		fclose(readFilePointer);
		printf("image uploaded\n");
	}



void displayimage(char image[][MAXh], char imageWidth[MAXw], char imageHeight[MAXh]){
	printf("Current Image: \n");
	for (int i = 0; i < imageWidth[0]; i++){
		for (int l = 0; l < imageHeight[0]; l++){
			printf("%c", image[i][l]);		
	}
	printf("\n");
	}
}



void cropimage(char imageWidth[MAXw], char imageHeight[MAXh], char image [][MAXh]){	
	int croppedWidth, croppedHeight;
	
	printf("Enter how much coordinates you would like to crop\n");
		scanf("%d  %d", &croppedHeight, &croppedWidth);
			
			imageHeight[0] -= croppedHeight;
			imageWidth[0] -= croppedWidth;
		}

void dimimage(char image[][MAXh]){
	char db, currentchar;
	int dimm, brightness;
	
	printf("Enter how much you would like dimmed (0-4)\n");
	scanf("%d", &dimm);
	
	char dimarray[5] = {' ','.','o','O','0'};
	for (int i = 0; i < MAXw; i++){
	for (int l = 0; l < MAXh; l++){
		 currentchar = image[i][l];
		 brightness = currentchar - 'O';
		 
		 brightness -= dimm;
	image[i][l] = brightness[dimarray];
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


void done(char *fchoice, char imageWidth[MAXw], char imageHeight[MAXh], char image[][MAXh]){

	printf("Do you want to save your image? [Y/N]: ");
  	scanf(" %c", fchoice); 
do{

if(*fchoice == 'Y' || *fchoice == 'y'){
char FILE_NAME[MAXh];
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
    

