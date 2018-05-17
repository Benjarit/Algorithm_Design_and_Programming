#include "game.h"

int fight(Player* playerList, Hero* heroes, Boss* boss)
{
    if(!heroes || !boss || !playerList)
    {
        //No idea how'd I get here, but just in case.
        printf("ERROR: parameters to fightFxns\n");
        freePlayerList(playerList);
        return -1;
    }
    //utility pointer, to move down the list.
    //Just in case we need to get back to the top of the turn order.
    Player* currentActor = playerList;
    //will reference the list of decisions the boss is using for the applicable turns.
    //This will need to be reset once the list of decisions runs out. 
    bossDecision* bossStack = NULL;
    
    while(1)
    {
        //Shows everyone's health on the screen, in a fashion that's pretty. 
        printFightStatus(heroes, boss);
        //The user decides what all the heroes do next. 
        getDecisions(heroes);
        //run through the turn order. Fastest player goes first, all the way to the slowest player. 
        while(currentActor != NULL)
        {
            if(bossStack == NULL)
            {
                //if the boss needs a new set of decisions, that has to be found before
                //anything happens. Otherwise, it will just use what is already there.
                bossStack = getNewListInTree(boss->root, boss->health);
                if(!bossStack)
                {
                    freePlayerList(playerList);
                    printf("ERROR: boss stack is NULL!\n");
                    return -1;
                }
            }
            //If the player is the boss, do his actions.
            if(currentActor->boss != NULL)
            {
                //he'll attack a random hero, I guess.
                Hero* defender = &heroes[rand() % NUMHEROES];
                //make sure the guy he's attacking is alive.
                while(defender->health == 0)
                {
                    defender = &heroes[rand() % NUMHEROES];
                }
                //get next thing from the list of decisions
                boss->nextAction = bossStack->type;
                evaluateDecision(defender, boss, 1);
                //get the next decision prepped. 
                bossStack = bossStack->next;
            }
            //If the player is a hero, just do his action. There's only one boss for now,
            //so that hero will just be attacking him if he's attacking. 
            else
            {
                evaluateDecision(currentActor->hero, boss, 0);
            }
            //remove the player that was just done, and go to the next guy.
            currentActor = currentActor->next;
            free(playerList);
            playerList = currentActor;
        }
        //turn order was exhausted, so a new one has to be made.
        //As of this version, we technically could just use the same list over and over,
        //but if we wanted to have stat modifying actions later, we'd need a whole new list
        //each time. 
        currentActor = createNewPlayerList(heroes, boss);
        if(!currentActor)
        {
            printf("ERROR: turn order list creation failed.\n");
            return -1;
        }
        int check;
        //checks to see if anyone is dead. If they are, they shouldn't be in the list. 
        playerList = resizeListAndCheckBoss(currentActor, &check);
        if(!playerList)
        {
            printf("ERROR: turn order list resizing failed.\n");
            return -1;
        }
        //the check was done above, sees if the boss is dead. If the boss is dead, game's over.
        if(check == 1)
        {
            //as of now, this is the only way to win the fight. 
            freePlayerList(playerList);
            return 0;
        }
        //reset this utility pointer. Just to be consistent. 
        currentActor = playerList;
        //checks to see how many players are left in the turn order once the dead ones 
        //are filtered out. 
        //I have literally no idea why Netbeans complains about this function. Yes, I declared it.
        if(countHeroesInFight(currentActor) < 1)
        {
            //if everyone's dead, game's over.
            freePlayerList(playerList);
            return 1;
        }
    }
    //I should never get here, but just in case...
    printf("ERROR: unexpected code execution\n");
    return -1;
}

Player* resizeListAndCheckBoss(Player* playerList, int* check)
{
    //go through the list similar to what is done in the fight function.
    Player* currentActor = playerList;
    Player* prev = playerList;
    while(currentActor != NULL)
    {
        //if the player is a boss
        if(currentActor->boss != NULL)
        {
            if(currentActor->boss->health <= 0)
            {
                //if the boss is dead, game over. 
                *check = 1;
                return playerList;
            }
            prev = currentActor;
            currentActor = currentActor->next;
        }
        else
        {
            //check for a dead hero.
            if(currentActor->hero->health <= 0)
            {
                //finds out where the hero is in the list, and repairs the list accordingly.
                if(currentActor == playerList)
                {
                    playerList = playerList->next;
                    free(currentActor);
                    prev = playerList;
                    currentActor = playerList;
                }
                else if(currentActor->next == NULL)
                {
                    prev->next = NULL;
                    free(currentActor);
                    break;
                }
                else
                {
                    prev->next = currentActor->next;
                    free(currentActor);
                    currentActor = prev->next;
                }
            }
            else
            {
                //if hero isn't dead, move to next one.
                prev = currentActor;
                currentActor = currentActor->next;
            }
        }
    }
    //return the newly updated list of all players that are alive. 
    return playerList;
}

//must be implemented////////////////////////
int countHeroesInFight(Player* list)
{
    Player* temp = list;
    int count;
    while(temp->next != NULL){
        count++;
        temp = temp->next;
    }
    count++;
    return count;
}

//Must be Implemented
/*Cateria:
 *       - The front of the queue must be fastest speed  
         - player is not boss or hero then it is null
         - Boss and Hero are Player!!!!!! (Important)
 *       - So fastest player on the field means fastest speed hero or boss
 */      

// Function Status: DONE
//create a queue list of players
//Players including boss and heroes
// set the boss or hero to NULL;whichever that node is not
Player* createNewPlayerList(Hero* heroes, Boss* boss)
{
    
    Player* front = NULL;
    Player* rear = NULL;
    
    int countHero = 0;
    
    //Transfer speed of hero to a new created array
    //so that we can focus on just speed and manipulate it
    int speed[NUMHEROES+1];
    while(countHero < NUMHEROES){
        speed[countHero] = heroes[countHero].speed;
        countHero++;
    }
    //set speed[3] or means the last element to the boss speed
    speed[NUMHEROES] = boss[0].speed;
    int i,j;
    
    // 5 1 8 6
    //do a bubble sort to see the fastest speed of heroes and boss
    for(i = 0; i <  NUMHEROES+1; i++){
        for(j = 0; j < NUMHEROES; j++ ){
            if(speed[j] < speed[j+1]){
                int temp = speed[j+1];
                speed[j+1] = speed[j];
                speed[j] = temp;
            }
        }
    }
    //8 6 5 1
    
    // create a queue linkList of players---done
    for(countHero = 0; countHero < NUMHEROES+1; countHero++){
        int count = 0;
        while(count < NUMHEROES){
            if(speed[countHero] == heroes[count].speed || speed[countHero] == boss[0].speed ){
                    Player* temp = (Player*)malloc(sizeof(Player));
                    if(speed[countHero] == heroes[count].speed){
                        temp->hero = (heroes+count);
                        temp->boss = NULL;
                        temp->next = NULL;
                    }
                    else{
                        temp->hero = NULL;
                        temp->boss = boss;
                        temp->next = NULL;
                    }
                    // 
                    //if-else statement  for making list
                    if(front == NULL && rear == NULL){
                        front = rear = temp;
                    }
                    else if(front != NULL && rear != NULL){
                         rear->next = temp;
                         rear = temp;
                    }          
            }
            //if we found the boss speed then exit the loop
            if(speed[countHero] == boss[0].speed){
                break;
            }
            count++;
        }//loop inside       
    }//big loop......List should be done after this loop is finished
    
    //Testing 
   /* Player* temp = front;
    while(temp->next != NULL){
        if(temp->boss != NULL){
            printf("%d\n",temp->boss->speed);
        }
        else if(temp->hero != NULL){
            printf("%d\n",temp->hero->speed);
        }
        temp = temp->next;
    }
    if(temp->boss != NULL){
            printf("%d\n",temp->boss->speed);
    }
    else if(temp->hero != NULL){
            printf("%d\n",temp->hero->speed);
    }*/
    // end of testing code
    
    //return the pointer to the head of the list
    return front;
}
//------------------------------------------------------------------------------


void printFightStatus(Hero* heroes, Boss* boss)
{
    int i;
    for(i = 0; i < 3; i++)
    {
        printf("--------%s----------", heroes[i].name);
        if(i == 1)
        {
            printf("\t\t\t\t--------%s----------\n", boss->name);
        }
        else
        {
            printf("\n");
        }
        printf("\t%d/%d", heroes[i].health, heroes[i].maxHealth);
        if(i == 1)
        {
            printf("\t\t\t\t\t%d/%d\n", boss->health, boss->maxHealth);
        }
        else
        {
            printf("\n");
        }
    }
}

void getDecisions(Hero* heroes)
{
    printf("\n\n");
    int i;
    for(i = 0; i < 3; i++)
    {
        if(heroes[i].health > 0)
        {
            printf("Choose your action for %s: \n", heroes[i].name);
            printf("0: Attack\n1: Defend\n2: Heal\n");
            printf(">");
            int choice; 
            scanf("%d", &choice);
            while(0 > choice || choice > 2)
            {
                printf("Invalid choice. Try again: \n");
                printf(">");
                scanf("%d", &choice);
            }
            heroes[i].decision = choice;
        }
    }
}
//Must be Implemented-----Status: Done
//See who takes action first
//What affects the health of opponents
//and etc.
void evaluateDecision(Hero* hero, Boss* boss, int takingAction)
{
    
    //Hero takes action
    if(takingAction == 0){
        if(hero->decision == DEFEND){
            //do nothing
            printf("%s is defending!\n",hero->name);
        }
        else if(hero->decision == HEAL){
            if(hero->hasHealed == false){
                hero->health = hero->maxHealth;
                printf("%s has been healed to full health!!\n",hero->name);
                hero->hasHealed = true;
            }
            else{
                                               //rand()%151 gives 0-150
                hero->health = (hero->health) + ((rand()%151)+50);
                 if(hero->health >= hero->maxHealth){
                     hero->health = hero->maxHealth;
                 }
                printf("%s is healing!!\n",hero->name);
            }
        }//end of heal if statement
        else if(hero->decision == ATTACK){
            if(boss->nextAction == DEFEND){
                int temp = (boss->defense) - (int)(((hero->attack)+(hero->sword->damage))*(.3));
                boss->health = (boss->health) + temp;
                if(boss->health <= 0){
                    boss->health = 0;
                }
                printf("%s attacks!! %s takes %d damages.\n",hero->name,boss->name,(-temp));
            }
            else if(boss->nextAction != DEFEND){
                int temp = (((hero->attack)+(hero->sword->damage))+(50-(boss->defense)));
                boss->health = (boss->health) - temp;
                if(boss->health <= 0){
                    boss->health = 0;
                }
                printf("%s attacks!! %s takes %d damages.\n",hero->name,boss->name,temp);
            }
        }//end of hero attack if statement       
    }//end of HERO decision if statement
    
    //boss takes action
    else if(takingAction == 1){
        if(boss->nextAction == DEFEND){
            //do nothing
            printf("%s is defending!\n",boss->name);
        }
        else if(boss->nextAction == HEAL){
                                            //rand()%51 gives 0-50)
            boss->health = (boss->health) + ((rand()%51)+100);
            if(boss->health >= boss->maxHealth){
                boss->health = boss->maxHealth;
            }
            printf("%s is healing!!\n",boss->name);
        }
        else if(boss->nextAction == ATTACK){
            if(hero->decision != DEFEND){ 
                int temp = (int)((boss->attack)*1.5);
                hero->health = (hero->health) - temp;
                 printf("%s attacks!! %s takes %d damages.\n",boss->name,hero->name,temp);
                if(hero->health <= 0){
                    hero->health = 0;
                }
            }
            else if(hero->decision == DEFEND){
                int temp = (boss->attack)-(int)(((hero->defense)+(hero->shield->defense))*(.3));
                hero->health = (hero->health) - temp;
                printf("%s attacks!! %s takes %d damages.\n",boss->name,hero->name,temp);
                //if hero health less than 0
                if(hero->health <= 0){
                    hero->health = 0;
                }
            }
        }
    }//end of boss action if statement
    //in case something is wrong
    else{
        printf("error!\n\n");
        return;
    }
}
//---------------------------------------End of HW3