#include "game.h" 

//just do the recgular add node to linklist here
//return the top or head node pointer
bossDecision* addDecisionNodeToList(bossDecision* top, bossDecision* newTop)
{
    newTop->next = top;
    top = newTop; 
    return top;
}                  

//add more nodes to the binary search tree
// Left side of the root: the healthMax is less than the root healthMin 
// Right side of the root: the healthMin is more than the root healthMax
bossDecisionNode* addNodeToDecisionTree(bossDecisionNode* root, bossDecisionNode* newNode)
{
    if(root == NULL){
        root = newNode;
    }
    else if(newNode->healthMax < root->healthMin){
        root->leftNode = addNodeToDecisionTree(root->leftNode,newNode);
    } 
    else if(newNode->healthMin > root->healthMax){
        root->rightNode = addNodeToDecisionTree(root->rightNode,newNode);
    }
    return root;
}
// DONE CORRECTLY!! 
//do the search in the binary search tree
bossDecision* getNewListInTree(bossDecisionNode* root, int currentBossHealth)
{
    if(root == NULL){
        return NULL;
    }
    else if((currentBossHealth >= root->healthMin) && (currentBossHealth <= root->healthMax)){
        return (root->topOfStack);
    }
    else if(currentBossHealth < root->healthMin){
        return getNewListInTree(root->leftNode,currentBossHealth);
    }
    else if(currentBossHealth > root->healthMax){
        return getNewListInTree(root->rightNode,currentBossHealth);
    }
}