
#include <stdio.h>
#include <stdlib.h>


typedef struct computer{
    char serialNumber[8];
    int price;
    int GBofRAM;
    int GBofHardFrive;
}Computer;

Computer* readComputers(char* filename);
void printComputers(Computer* comps);
Computer* insertionSortByPrice(Computer* comps);
Computer* selectionSortByPrice(Computer* comps);

int main(int argc, char** argv) {
    
    char* nameFile = argv[1];
    readComputers(nameFile);
    
    
    return 0;
}
Computer* readComputers(char* filename){
    int i;
    Computer *com = (Computer*)malloc(sizeof(Computer)*4);
    FILE *file = fopen(filename,"r");
    
    for(i = 0 ;i < 4;i++)
    {
        fscanf(file,"%s %d",(com+i)->serialNumber,&((com+i)->price));
        fscanf(file,"%d %d",&((com+i)->GBofRAM),&(com+i)->GBofHardFrive);
    }
    
    printf("Before sorting: \n\n");
    printComputers(com);
    
    
    printf("\nAfter sorting((ascending):\n\n");
    printComputers(insertionSortByPrice(com));
    
    free(com);
    
    com = (Computer*)malloc(sizeof(Computer)*4);
    rewind(file);
    for(i = 0 ;i < 4;i++)
    {
        fscanf(file,"%s %d",(com+i)->serialNumber,&((com+i)->price));
        fscanf(file,"%d %d",&((com+i)->GBofRAM),&(com+i)->GBofHardFrive);
    }
    printf("\nAfter sorting(descending):\n\n");
    printComputers(selectionSortByPrice(com));
    
    
    
}
void printComputers(Computer* comps){
    int i;
     for(i = 0 ;i < 4;i++)
     {
        printf("%-6s $%d\n", (comps+i)->serialNumber,(comps+i)->price );
        printf("%-6d %dGB\n",(comps+i)->GBofRAM,(comps+i)->GBofHardFrive); 
     }      
}
Computer* insertionSortByPrice(Computer* comps){
    Computer *sorted = (Computer*)malloc(sizeof(Computer)*4);

    int x;
     for(x = 1;x < 4; x++){
         Computer temp = *(comps+x);
         int j = x;
         
        while(j > 0 && (comps+(j-1))->price > temp.price ){
            *(comps+j) = *(comps+(j-1));
            j = j -1;
        }
         *(comps+j) = temp;
      }
    sorted = comps;
 
     return sorted ;
}
Computer* selectionSortByPrice(Computer* comps){
    Computer *sorted = (Computer*)malloc(sizeof(Computer)*4);
    int i,j;
    for(i = 3; i > 0;i--){
        int max = 0;
        for(j = 1; j <= i;j++){
            if(((comps+j)->price) < ((comps+max)->price)){
                max = j;
            }      
        }
        
        Computer temp = *(comps+max);
        *(comps+max) = *(comps+i);
        *(comps+i) = temp;
    }
    sorted = comps;
    
    return comps;
}