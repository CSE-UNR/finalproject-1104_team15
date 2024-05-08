//Final Project
//Paige Krueger & Yael Collazo Osorio

#include <stdio.h>
#include <stdbool.h>

#define WIDTH 500
#define HEIGHT 500

//Define Functions

void ogMenu(char *choice);
void uploadimage(FILE *dest_fp, int *MH, int *MW, char string[], char image[][HEIGHT]);
void displayimage(char image[][HEIGHT], int imageWidth[WIDTH], int imageHeight[HEIGHT]);
void editMenu(char *echoice);
void cropimage(int *imageWidth, int *imageHeight, char image[][HEIGHT]);
void brightenimage(char image[][HEIGHT]);
void dimimage(char image[][HEIGHT]);
void done(char *fchoice, int imageWidth[WIDTH], int imageHeight[HEIGHT], char image[][HEIGHT]);


int main(){

	char image[WIDTH][HEIGHT];
	int imageHeight[HEIGHT];
	int imageWidth[WIDTH] ;
	FILE *dest_fp;
	int MH, MW;
	char string [HEIGHT];
	char choice;
	char echoice;
	char fchoice;

//Dispaly Menus and loop them

do{
	ogMenu(&choice);

		if(choice == '1'){
			uploadimage(dest_fp, &MH, &MW, string, image);} 
		else if(choice == '2'){
			displayimage(image, imageWidth, imageHeight);}
		else if(choice == '3'){
			do{
			editMenu(&echoice);
		
			if (echoice == '1'){
				cropimage(imageWidth, imageHeight, image);
				done(&fchoice, imageWidth, imageHeight, image);}
			else if (echoice == '2'){
	  			dimimage(image);
	  			done(&fchoice, imageWidth, imageHeight, image);}
			else if (echoice == '3'){
	 			brightenimage(image);
	 			done(&fchoice, imageWidth, imageHeight, image);}
			else if(echoice == '0'){
				printf("Okay!\n");}
			}
			while(echoice == '1' || echoice == '2' || echoice == '3');}
		else if(echoice == '0'){
		done(&fchoice, imageWidth, imageHeight, image);
		printf("Goodbye!\n");
		return 0;}
}while(choice == '1' || choice == '2' || choice == '3');

	return 0;}




//Function for the Main(first) menu

void ogMenu(char *choice){
do{
	printf("**ERINSTAGRAM**\n1: Load image\n2: Display image\n3: Edit image\n0: Exit\nChoose from one of the options above: ");
	scanf(" %c", choice);
		if(*choice != '1' && *choice !='2' && *choice != '3' && *choice != '0'){
			printf("Invalid Choice\n");}
}while(*choice != '1' && *choice !='2' && *choice != '3' && *choice != '0');}


	

//Function for the Edit(second) menu

void editMenu(char *echoice){
do{
	printf("1: Crop Image \n2: Dim Image\n3: Brighten Image\n0: Exit\nChoose from one of the options above: ");
	scanf(" %c", echoice);
		if(*echoice != '1' && *echoice !='2' && *echoice != '3' && *echoice != '0'){
		printf("Invalid Choice\n");}
}while(*echoice != '1' && *echoice !='2' && *echoice != '3' && *echoice != '0');}
	



//Function to upload the image file

void uploadimage(FILE *dest_fp, int *MH, int *MW, char string[], char image[][HEIGHT]){	
	int allrows = 0, allcolumns = 0;
	char input;
	
	printf("File name? ");
	scanf("%s", string);
	
	dest_fp = fopen(string, "r");
	printf("Image Uploaded\n");
	
	if (dest_fp == NULL){
		printf("ERROR\n");
		return;}}




//Function to display the image

void displayimage(char image[][HEIGHT], int imageWidth[WIDTH], int imageHeight[HEIGHT]){
	for (int i= 0; i < imageWidth[WIDTH]; i++){
		for (int l = 0; l < imageHeight[HEIGHT]; l++){
		
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
			break;}}
			printf("\n");}}
			
	
	

//Functoin to crop the image

void cropimage(int imageWidth[WIDTH], int imageHeight[HEIGHT], char image [][HEIGHT]){	
char brightness[5] = {' ', '.','o','O','0'};	
int croppedWidth, croppedHeight;
	
	printf("Enter how much coordinates you would like to crop\n");
	scanf("%d  %d", &croppedHeight, &croppedWidth);
			
			imageHeight = imageHeight - croppedHeight;
			imageWidth = imageWidth - croppedWidth;}




//Function to Dim Image

void dimimage(char image[][HEIGHT]){
char brightness[5] = {' ', '.','o','O','0'};
	char db, currentchar;
	int dimm, bright;
	
	printf("Enter how much you would like dimmed (0-4)\n");
	scanf("%d", &dimm);
	
	char dimarray[5] = {' ','.','o','O','0'};
	for (int i = 0; i < WIDTH; i++){
	for (int l = 0; l < HEIGHT; l++){
		 currentchar = image[i][l];
		 bright = currentchar - 'O';
		 
		 bright -= dimm;
	image[i][l] = bright[dimarray];}}
	printf("Image dimmed\n");}




//Function to brighten image

void brightenimage(char image[][HEIGHT]){
	int brighten, brit;
	char current;
	char brightness[5] = {' ', '.','o','O','0'};
	printf("How much would you like to be brightened (0-4)\n");
	scanf("%d", &brighten);
	
	for (int i = 0; i < WIDTH; i++){
	for (int l = 0; l < HEIGHT; l++){
		 current = image[i][l];
		 brit = current - 'O';
		 
		brit += brighten; 
	image[i][l] = brightness[brit];}}
	printf("Image Brightened\n");}




//Function to finish/save image file. 

void done(char *fchoice, int imageWidth[WIDTH], int imageHeight[HEIGHT], char image[][HEIGHT]){

	printf("Do you want to save your image? [Y/N]: ");
  	scanf(" %c", fchoice); 
do{

if(*fchoice == 'Y' || *fchoice == 'y'){
char FILE_NAME[HEIGHT];
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
        printf("Okay!\n");} 
else{
        printf("Invalid choice.\n");}
}
while(*fchoice != 'Y' && *fchoice !='y' && *fchoice != 'N' && *fchoice != 'n');
    }
