/* 
# CSCB58 Winter 2022 Assembly Final Project 
# University of Toronto, Scarborough 
# 
# Student: Ankit Devesh Shrivastava, ankit.shrivastava@mail.utoronto.ca / shrivastava.ankit2113@gmail.com
# Used to convert a global array of values into the neccesary color codes we want 
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "waybig_shooting.c"

void printSimplified(FILE *fp, const uint32_t array[1][16384], int *indices, int size){
    for (int i = 0; i < 16384; i++){
            char str[20] = {};
            sprintf(str, "%08x", array[0][i]);

            if (strcmp("00000000", str) != 0){
                indices[size] = i;
                char final[25] = {};
                strcat(final, "0x");
                final[2] = str[6];
                final[3] = str[7];
                final[4] = str[4];
                final[5] = str[5];
                final[6] = str[2];
                final[7] = str[3];
                final[8] = '\0';
                fprintf(fp,"%s, %d, ",final, i*4);
                size++;
            }
    }

    fprintf(fp, "-1\n");
}


int main()
{
    int num;
    FILE *fptr;

    int indices[65537];
    for (int i = 0; i < 65537; i++){
        indices[i] = -1;
    }

    int size = 0;

    fptr = fopen("C:\\Users\\shriv\\OneDrive\\Desktop\\CSCB58\\Project\\Final Images\\waybig_shoot.txt","w");
    if(fptr == NULL)
    {
    printf("Error!");   
    exit(1);             
    }

    printSimplified(fptr, ultimate_waybig_data, indices, size);
    fclose(fptr);

    return 0;
}