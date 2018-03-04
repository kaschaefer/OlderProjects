#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *input = NULL;
	FILE *output = NULL; 
	int counter =0;
	
	input = fopen(argv[1], "r");
	output = fopen(argv[2], "w");
	if (input == NULL) {
		char errmsg[21] = "File failed to open.";
		fwrite(errmsg, 1, 20, output);
	}

	else {
	//Read 5 ints into a temp array, write them to the output file, repeat 5x
		for (int i =0; i <5; i++) {
			//Move to Correct Location in File
			fseek(input,sizeof(int)*(10*i), SEEK_SET);	
			//Read 5 ints to File	
			for (int j=0; j<5; j++) {
				int x =0;
				fread(&x, sizeof(int), 1, input);
				fprintf(output, "%d\n", x);	
			}
		}
	}
	

	fclose(output);
	fclose(input);
	return 0;
}

