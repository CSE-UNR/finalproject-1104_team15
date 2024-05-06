//Final Project
//Paige Krueger & Yael Collazo Osorio

#include <stdio.h>

#define MAXw 500
#define MAXh 500

void ogMenu(char *choice);
void uploadimage(char image[][MAXh]);
void displayimage(char image[][MAXh], char imageWidth[MAXw], char imageHeight[MAXh]);
void editMenu(char *echoice);
void cropimage(char *imageWidth[MAXw], char *imageHeight[MAXh], char image[][MAXh]);
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
				cropimage(&imageWidth, &imageHeight, image);}
			else if (echoice == '2'){
	  			dimimage(image);}
			else if (echoice == '3'){
	 			brightenimage(image);}
			else if(echoice == '0'){
				printf("Okay!\n");}
		}
		while(choice == '1' || choice == '2' || choice == '3');}
	else if(choice == '0'){
		done(&fchoice, imageWidth, imageHeight, image);
		return 0;}
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
	}



void displayimage(char image[][MAXh], char imageWidth[MAXw], char imageHeight[MAXh]){
	printf("Current Image: \n");
	for (int i = 0; i < imageWidth[MAXw]; i++){
		for (int j = 0; j < imageHeight[MAXh]; j++){
			printf(" %c", image[i][j]);		
	}}
}



void cropimage(char *imageWidth[MAXw], char *imageHeight[MAXh], char image [][MAXh]){	
	char croppedWidth, croppedHeight;
	
	printf("Your currect max image height is 500x500\n");
	printf("Enter how much coordinates you would like to crop\n");
		scanf(" %c  %c", &croppedHeight, &croppedWidth);
			
			(*imageHeight[MAXh]) = imageHeight[MAXh] - croppedHeight;
			(*imageWidth[MAXw]) = imageHeight[MAXw] - croppedWidth;
		}

void dimimage(char image[][MAXh]){
	char db;
	for (int i = 0; i < 500; i++){
	for (int l = 0; l < 500; l++){
		scanf(" %c", &image[i][l]);
			if(db == '0'){ 
				db = 'O';} 
               		else if(db == 'O'){ 
                		db = 'o';} 
                	else if(db == 'o'){ 
                		db = '.';} 
                	else if (db == '.'){ 
                		db = ' ';} 
                	else if (db == ' '){ 
                		printf("Image cannot be any dimmer\n");}}}
}
	


void brightenimage(char image[][MAXh]){
	char db;
	for (int i = 0; i < 500; i++){
	for (int l = 0; l < 500; l++){
		scanf(" %c", &image[i][l]);
			if(db == ' '){ 
				db = '.';} 
               		else if(db == '.'){ 
                		db = 'o';} 
                	else if(db == 'o'){ 
                		db = 'O';} 
                	else if (db == 'O'){ 
                		db = '0';} 
                	else if (db == '0'){ 
                		printf("Image cannot be any brighter\n");}}}
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
    			for (int i = 0; i < imageWidth[MAXw]; i++){
        			for (int j = 0; j < imageHeight[MAXh]; j++) {
            				fprintf(dest_fp, " %c", image[i][j]);}
        	fprintf(dest_fp, "\n");}}
    			printf("Image saved successfully.\n");
    				fclose(dest_fp);
}
	while(dest_fp == NULL);}

else if(*fchoice == 'N' || *fchoice == 'n'){
        printf("Goodbye!\n");} 
else{
        printf("Invalid choice.\n");}
}
while(*fchoice != 'Y' && *fchoice !='y' && *fchoice != 'N' && *fchoice != 'n');
    }
    

