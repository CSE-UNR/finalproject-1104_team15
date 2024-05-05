//Final Project
//Paige Krueger & Yael Collazo Osorio

#include <stdio.h>

//Declare Functions
int ogMenu(char choice);
int uploadimage(int image[][500]);
int displayimage(int image[][500]);
int editMenu(char echoice);
void cropimage(int imageWidth, int imageHeight);
void brightenimage(char db, int image[][500]);
void dimimage(char db, int image[][500]);
int done(char fchoice, int imageWidth, int imageHeight, int image[][500]);

int main(){

int image[500][500];
int imageHeight = 500;
int imageWidth = 500;
char choice;
char echoice;
char fchoice;git
double db;


	if(uploadimage == 1){
	printf("   \n",);
	//pointers
	} 
	if(displayimage == 2){
	printf("   \n");

	}
	if(dimimage == 3){
	printf("     \n");

	}
	if(exit == 0){
	printf("   \n");
	}


return 0;
}


int ogMenu(char choice){
	do{
		printf("**ERINSTAGRAM**\n1: Load image\n2: Display image\n3: Edit image\n0: Exit\nChoose from one of the options above: ");
		scanf(" %c", &choice);
	}
	while(choice != '1' && choice !='2' && choice != '3' && choice != '0');

	return 0;}



int uploadimage(int image[][500]){	
char FILE_NAME[500];

	printf("Enter your file name : \n");
	scanf("%s", FILE_NAME);

	FILE* readFilePointer = fopen(FILE_NAME, "r");
	
	if(readFilePointer == NULL){
		printf("Input file does not exist.\nGoodbye!\n");
		return 0;}
	
	else{ 
		for (int i = 0; i < 500; i++){
		for (int l = 0; l < 500; l++){
				fscanf(readFilePointer, "%d ", &image[i][l]);
		}}}
	fclose(readFilePointer);
	return 0;}



int displayimage(int image[][500]){
	printf("Current Image: \n");
	for (int imageWidth = 0; imageWidth < 500; imageWidth++){
		for (int imageHeight = 0; imageHeight < 500; imageHeight++){
			printf("%d ", image[imageWidth][imageHeight]);
			
	}
	}
	return displayimage;
}

int editMenu(char echoice){
	do{
		printf("1: Crop Image [1]\n2: Dim Image\n3: Brighten Image\n0: Exit\nChoose from one of the options above: ");
		scanf(" %c", &echoice);
	}
	while(echoice != '1' && echoice !='2' && echoice != '3' && echoice != '0');
	return echoice;}



void cropimage(int imageWidth, int imageHeight){
	int croppedHeight=0;
	int croppedWidth=0;	
	
	printf("Your currect max image height is 500x500\n");
	printf("Enter how much coordinates you would like to crop\n");
		scanf("%d %d", &croppedHeight, &croppedWidth);
		
		for (int imageWidth = croppedWidth; imageWidth < croppedWidth; croppedWidth++){
		for (int imageHeight = croppedHeight; imageHeight < croppedHeight; croppedHeight++){
			croppedHeight = imageHeight;
			croppedWidth = imageWidth;
			
			imageHeight = imageHeight - croppedHeight;
			imageWidth = imageWidth - croppedWidth;
		}}}

void dimimage(char db, int image[][500]){
	
	for (int i = 0; i < 500; i++){
	for (int l = 0; l < 500; l++){
		scanf(" %d ", &image[i][l]);
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
	


void brightenimage(char db, int image[][500]){
	
	for (int i = 0; i < 500; i++){
	for (int l = 0; l < 500; l++){
		scanf("%d", &image[i][l]);
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
	


int done(char fchoice, int imageWidth, int imageHeight, int image[][500]){
char FILE_NAME[500];
double l;
double i;
	printf("Do you want to save your image? [Y/N]: ");
	scanf(" %c", &fchoice);
	
	switch(fchoice){
		case 'Y':
		case 'y': 		
			FILE* dest_fp;
			dest_fp = fopen(FILE_NAME, "w");
		
			if(dest_fp == NULL){
				printf("Can't open file\n");
				return 0;}
			else{
				
		imageWidth = i;
		imageHeight = l;
				for (int i = 0; i < 500; i++){
				for (int l = 0; l < 500; l++){
					fprintf(dest_fp, "%d ", image[i][l]);
				}}}
					fclose(dest_fp);
		break;
		
		case 'N':
		case 'n': printf("\nGoodbye!\n");
		break;
	return done;
		}}




