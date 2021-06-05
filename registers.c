#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 255

typedef struct {
    char name[MAX];
} NAME;

void read_line(char [], FILE*);
int Compare(NAME, NAME);
void Trade(NAME [], int);
void bubble_sort(NAME [], int);

int main(){

    FILE *file;
    NAME list[MAX];
    int i=0;

    file = fopen("registers.csv", "r");

    if (file == NULL){
        printf("Couldn't open the file\n");
        exit(EXIT_FAILURE);
    }

    printf("Desordered List: \n");
    while (!feof(file)){
        read_line(list[i].name, file);
        printf("%s\n", list[i].name);
        i++;
    }
    fclose(file);

    printf("\n\nOrdered List:\n");
    bubble_sort(list, 15);

    for (i = 0; i < 15; i++){
        printf("%s\n", list[i].name);
    }

    return 0;
}

void read_line(char line[], FILE *file)
{
    fgets(line, MAX, file);
    if (line[strlen(line) - 1] == '\n')
        line[strlen(line) - 1] = '\0';
}

int Compare(NAME l1, NAME l2){
    return strcmp(l1.name, l2.name);
}

void Trade(NAME books[], int position){
    NAME aux;
    aux = books[position];
    books[position] = books[position+1];
    books[position+1] = aux;
}

void bubble_sort(NAME books[], int size){
    int i, j;
    for(i=size-1; i>=1; i--){
        for(j=0; j<=i-1; j++){
            if (Compare(books[j], books[j+1]) > 0){
                Trade(books, j);
            }
        }
    }
}