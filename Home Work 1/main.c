//Benjarit Hotrabhavananda
//bhmcf
//HomeWork 1
//cs2050


#include <stdio.h>
#include <stdlib.h>


typedef struct _category{
    char name[20];
    int numInCategory;
}Category;
typedef struct _shield{
    char name[50];
    int price;
    int defense;
    int weight;
}Shield;
typedef struct _sword{
    char name[50];
    int price;
    int damage;
    int weight;
}Sword;
typedef struct _footwear{
    char name[50];
    int price;
    int defense;
    int weight;
}Footwear;
typedef struct _headgear{
    char name[50];
    int price;
    int defense;
    int weight;
}Headgear;
typedef struct _hero{
    char name[30];
    int health;
    int defense;
    int speed;
    int attack;
    int luck;
}Hero;
void mainMenu();
void highScores();
void newGame();
void processHeroes();
void weaponSelection();
void sheildSelection(Shield* shields,int numShields);
void swordSelection(Sword* swords, int numSwords);
void footwearSelection(Footwear* footwear, int numFootwear);
void headgearSelection(Headgear* headgear,int numHeadgear);

//global varible
Category *category;

int main(int argc, const char * argv[]) {
    mainMenu();
    return 0;
}
void mainMenu(){

    //everything cycle back here
    int selection;
    do{
    printf("WELCOME! Please select an option:\n");
    printf("1. New Game\n2. Hight Scores\n3. ExitGame\n");
    scanf("%d",&selection);
        switch (selection) {
            case 1:
                newGame();
                break;
            case 2:
                highScores();
                break;
            case 3:
                break;
            default:
                printf("Invalid selection. Try again\n\n");
                break;
        }
    }while(selection != 3);
    exit(0);
}
void newGame(){
    
    //open and put in the user name in the that file.
    FILE *person = fopen("highScores.txt","a+");
    char name[20];
    printf("\nWhat is your name?\n");
    scanf("%s",name);
    fprintf(person,"\n%s",name);
    
    //heart of the program
    printf("Hello %s. Welcome to the gauntlet.\n\n",name);
    processHeroes();
    weaponSelection();
    
    fclose(person);
}

void highScores(){
    char name[20];
    long highScore;
    FILE *file = fopen("highScores.txt", "r+");
    if(file==NULL)
    {
        exit(0);
    }
    printf("Username:   Score:\n\n");
    while(!feof(file)){
        fscanf(file,"%s",name);
        fscanf(file,"%lu",&highScore);
        printf("%-12s",name);
        printf("%lu\n",highScore);
    }
    printf("\n");
    fclose(file);
}
void processHeroes(){
    //first file for reading in.
    //second file for writing to save hero datas
    FILE *file = fopen("HeroesFile.txt", "rb+");
    FILE *file2 = fopen("HeroFileSelected.txt", "wb+");
    
    //initiate the choice array with 0 so that we can check later
    long fileSize;
    int choice[3] = {0,0,0},i = 0;
    
    fseek(file,0,SEEK_END);
    fileSize = ftell(file);
    Hero *hero = (Hero*)malloc(sizeof(Hero)*(fileSize/sizeof(Hero)));
    rewind(file);
    
    //if the heroesfile.txt is not exited
    if(file == NULL){
        printf("File could not be opened.\n");
        exit(0);
    }
    
    printf("Hero data:\n");
    
    //run it as long as there is hero left in the file
    while(i < (fileSize/sizeof(Hero))){
        fread((hero+i),sizeof(Hero),1,file);
        printf("%s\n",(hero+i)->name);
        printf("    Health: %d hp\n",(hero+i)->health);
        printf("    Attack: %d \n",(hero+i)->attack);
        printf("    Defense: %d \n",(hero+i)->defense);
        printf("    Speed: %d \n",(hero+i)->speed);
        printf("    Luck: %d \n",(hero+i)->luck);
        i++;
    }
    
    //first input
    printf("\nChoose the first here you wish to add to your team(1-5):");
    scanf("%d",&choice[0]);
    //check errors
    while( choice[0] > 5 || choice[0] < 1){
        printf("Incorrect choice. Choose again: ");
        scanf("%d",&choice[0]);
    }
    
    fseek(file2,0*sizeof(Hero),SEEK_SET);
    fwrite((hero+(choice[0]-1)),sizeof(Hero),1,file2);
    
    //the rest of choosing
    for(i = 1; i < 3; i++){
        //input
        printf("Excellent choice. Choose your %d:",i+1);
        scanf("%d",&choice[i]);
        
        //nothing here
        //just check errors
        while( choice[i] > 5 || choice[i] < 1 || choice[i] == choice[0] || choice[i] == choice[i-1]){
            printf("Incorrect choice. Choose again: ");
            scanf("%d",&choice[i]);
        }
        //seek the hero info
        fseek(file2,i*sizeof(Hero),SEEK_SET);
        fwrite((hero+(choice[i]-1)),sizeof(Hero),1,file2);
    }
    
    printf("\nHero chioces saved successfully.\n\n");
    
    //close and free everything
    fclose(file);
    fclose(file2);
    free(hero);
}
void weaponSelection(){
    //open category.txt file
    FILE *file = fopen("CategoryList.txt","rb");
    long fileSize;
    int i = 0,option;
    
    //promt user
    printf("Select a category to see its items\n");
    
    //malloc space for category
    fseek(file,0,SEEK_END);
    fileSize = ftell(file);
    category = (Category*)malloc(sizeof(Category)*(fileSize/sizeof(Category)));
    rewind(file);
    
    //keep doing this as long as user put 4
    do{
    while(i < 4){
        fread((category+i),sizeof(Category),1,file);
        printf("%d: %s\n",i,(category+i)->name);
        i++;
    }
    
    printf("4: quit\n\nOption: ");
    scanf("%d",&option);
    
    //check error
    while(option > 4 || option < 0){
        printf("Invalid choice. Try again: ");
        scanf("%d",&option);
    }
        
    
    //see option and match the case
        if(option == 0){
            printf("Item data: \n");
            
            Shield *shields = (Shield*)malloc(sizeof(Shield)*((category+0)->numInCategory));
            sheildSelection(shields,((category+0)->numInCategory));
            
            free(shields);
        }
        //will load sword items
        else if(option == 1){
            printf("Item data: \n");
            Sword *sword = (Sword*)malloc(sizeof(Sword)*((category+1)->numInCategory));
            swordSelection(sword,((category+1)->numInCategory));
            free(sword);
        }
        //will load footwear items
        else if(option == 2){
            printf("Item data: \n");
            Footwear *footwear = (Footwear*)malloc(sizeof(Footwear)*((category+2)->numInCategory));
            footwearSelection(footwear,((category+2)->numInCategory));
            free(footwear);
        }
        //will load headgear items
        else if(option == 3){
            printf("Item data: \n");
            Headgear *headGear = (Headgear*)malloc(sizeof(Headgear)*((category+3)->numInCategory));
            headgearSelection(headGear,((category+3)->numInCategory));
            free(headGear);
        }
        
        i = 0;
        rewind(file);
    }while(option != 4);
    fclose(file);
    free(category);
    mainMenu();
}
void sheildSelection(Shield* shields,int numShields){
    FILE *file = fopen("ItemsFile.txt","rb+");
    int i = 0;
    //since we always kow the shild will be in the first position
    fseek(file,0,SEEK_SET);
    //read data out
    while(i < numShields){
        fread((shields+i),sizeof(Shield),1,file);
        printf("%s\n",(shields+i)->name);
        printf("    Price: $%d\n",(shields+i)->price);
        printf("    Multiplier: %d\n",(shields+i)->defense);
        printf("    Weight: %dkg\n\n",(shields+i)->weight);
        i++;
    }
    fclose(file);
}
void swordSelection(Sword* swords,int numSwords){
    FILE *file = fopen("ItemsFile.txt","rb+");
    int i = 0;
    //move to the sword items
    fseek(file,sizeof(Shield)*(category+0)->numInCategory,SEEK_SET);
    //read data out
    while(i < numSwords){
        fread((swords+i),sizeof(Sword),1,file);
        printf("%s\n",(swords+i)->name);
        printf("    Price: $%d\n",(swords+i)->price);
        printf("    Multiplier: %d\n",(swords+i)->damage);
        printf("    Weight: %dkg\n\n",(swords+i)->weight);
        i++;
    }
    fclose(file);
}
void footwearSelection(Footwear* footwear, int numFootwear){
    FILE *file = fopen("ItemsFile.txt","rb+");
    int i = 0;
    //move to the footwear items
    fseek(file,(sizeof(Shield)*(category+0)->numInCategory)+(sizeof(Sword)*(category+1)->numInCategory),SEEK_SET);
    //read data out
    while(i < numFootwear){
        fread((footwear+i),sizeof(Footwear),1,file);
        printf("%s\n",(footwear+i)->name);
        printf("    Price: $%d\n",(footwear+i)->price);
        printf("    Multiplier: %d\n",(footwear+i)->defense);
        printf("    Weight: %dkg\n\n",(footwear+i)->weight);
        i++;
    }
    fclose(file);
}
void headgearSelection(Headgear* headgear,int numHeadgear){
    FILE *file = fopen("ItemsFile.txt","rb+");
    int i = 0;
    //move to the headgear items
    fseek(file,(sizeof(Shield)*(category+0)->numInCategory)+(sizeof(Sword)*(category+1)->numInCategory)
          +(sizeof(Footwear)*(category+2)->numInCategory),SEEK_SET);
    //read data out
    while(i < numHeadgear){
        fread((headgear+i),sizeof(Headgear),1,file);
        printf("%s\n",(headgear+i)->name);
        printf("    Price: $%d\n",(headgear+i)->price);
        printf("    Multiplier: %d\n",(headgear+i)->defense);
        printf("    Weight: %dkg\n\n",(headgear+i)->weight);
        i++;
    }
    fclose(file);
}