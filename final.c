//Final Project
//Paige Krueger & Yael Collazo Osorio

#include <stdio.h>

<<<<<<< HEAD
void ogMenu(char *choice);
void uploadimage(int image[][500]);
void displayimage(int image[][500], int imageWidth, int imageHeight);
void editMenu(char *echoice);
void cropimage(int *imageWidth, int *imageHeight, int image[][500]);
void brightenimage(int image[][500]);
void dimimage(int image[][500]);
void done(char *fchoice, int imageWidth, int imageHeight, int image[][500]);
=======
//Declare Functions
int ogMenu(char choice);
int uploadimage(int image[][500]);
int displayimage(int image[][500]);
int editMenu(char echoice);
void cropimage(int imageWidth, int imageHeight);
void brightenimage(char db, int image[][500]);
void dimimage(char db, int image[][500]);
int done(char fchoice, int imageWidth, int imageHeight, int image[][500]);
>>>>>>> 69e1a7f77bd853790bd5a591312ccbe79c1dbcad

int main(){

int image[500][500];
int imageHeight = 500;
int imageWidth = 500;
char choice;
char echoice;
<<<<<<< HEAD
char fchoice;
<<<<<<< HEAD
=======
=======
char fchoice;git
>>>>>>> 579f2c9f8fd6d2e2082c4c86e8db47a2daec4de8
double db;
>>>>>>> 69e1a7f77bd853790bd5a591312ccbe79c1dbcad

	ogMenu(&choice);

<<<<<<< HEAD
	if(choice == '1'){
		uploadimage(image);
		
	} else if(choice == '2'){
		displayimage(image, imageWidth, imageHeight);
		
	}else if(choice == '3'){
		editMenu(&echoice);
		
	if (echoice == '1'){
		cropimage( &imageWidth, &imageHeight, image);
	}else if (echoice == '2'){
	  dimimage(image);
	  
	 }else if (echoice == '3'){
	 	brightenimage(image);
		 	
	}else if(echoice == '0'){
		printf("bye\n");
=======
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

>>>>>>> 69e1a7f77bd853790bd5a591312ccbe79c1dbcad

	}else if(choice == '0'){
		printf("bye\n");
		return 0;
	}
	done(&fchoice, imageWidth, imageHeight, image);
return 0;
}


void ogMenu(char *choice){
	do{
		printf("**ERINSTAGRAM**\n1: Load image\n2: Display image\n3: Edit image\n0: Exit\nChoose from one of the options above: ");
<<<<<<< HEAD
		scanf(" %c", choice);
	}
	while(*choice != '1' && *choice !='2' && *choice != '3' && *choice != '0');
}



void uploadimage(int image[][500]){	
=======
		scanf(" %c", &choice);
	}
	while(choice != '1' && choice !='2' && choice != '3' && choice != '0');

	return 0;}



int uploadimage(int image[][500]){	
>>>>>>> 69e1a7f77bd853790bd5a591312ccbe79c1dbcad
char FILE_NAME[500];

	printf("Enter your file name : \n");
	scanf("%s", FILE_NAME);

<<<<<<< HEAD
	FILE *readFilePointer = fopen(FILE_NAME, "r");
	
	if(readFilePointer == NULL){
		printf("Input file does not exist.\nGoodbye!\n");
		
		}else{ 
		for (int i = 0; i < 500; i++){
			for (int l = 0; l < 500; l++){
				fscanf(readFilePointer, "%d ", &image[i][l]);
		}}}
	fclose(readFilePointer);
	}



void displayimage(int image[][500], int imageWidth, int imageHeight){
	printf("Current Image: \n");
	for (int i = 0; i < 500; i++){
		for (int j = 0; j < 500; j++){
			printf("%d ", image[i][j]);
			
	}
	}
	}

void editMenu(char *echoice){
	do{
		printf("1: Crop Image [1]\n2: Dim Image\n3: Brighten Image\n0: Exit\nChoose from one of the options above: ");
		scanf(" %c", echoice);
	}
	while(*echoice != '1' && *echoice !='2' && *echoice != '3' && *echoice != '0');
	}



void cropimage(int *imageWidth, int *imageHeight, int image [][500]){	
	int croppedWidth, croppedHeight;
=======
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
>>>>>>> 69e1a7f77bd853790bd5a591312ccbe79c1dbcad
	
	printf("Your currect max image height is 500x500\n");
	printf("Enter how much coordinates you would like to crop\n");
		scanf("%d %d", &croppedHeight, &croppedWidth);
<<<<<<< HEAD
			
			*imageHeight -=croppedHeight;
			*imageWidth -=croppedWidth;
		}
=======
		
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
>>>>>>> 69e1a7f77bd853790bd5a591312ccbe79c1dbcad

void dimimage(int image[][500]){
	char db;
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
	


void brightenimage(int image[][500]){
	char db;
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
	


void done(char *fchoice, int imageWidth, int imageHeight, int image[][500]){

	printf("Do you want to save your image? [Y/N]: ");
  	  scanf(" %c", fchoice); 

    if (*fchoice == 'Y' || *fchoice == 'y') {
        char FILE_NAME[500];
        printf("Enter the file name to save: ");
        scanf("%s", FILE_NAME);

        FILE *dest_fp = fopen(FILE_NAME, "w");

        if (dest_fp == NULL) {
            printf("Can't open file\n");
            return;
        } else {
            for (int i = 0; i < imageWidth; i++) {
                for (int j = 0; j < imageHeight; j++) {
                    fprintf(dest_fp, "%d ", image[i][j]);
                }
                fprintf(dest_fp, "\n"); 
            }
            printf("Image saved successfully.\n");
        }
        fclose(dest_fp);
    } else if (*fchoice == 'N' || *fchoice == 'n') {
        printf("Goodbye!\n");
    } else {
        printf("Invalid choice.\n");
         } 
    }
    }
    

