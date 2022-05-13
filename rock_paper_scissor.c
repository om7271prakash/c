#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void nextLine(int count){
    for (int i = 0; i < count; i++)
    {
        printf("\n");
    }
    
}

void useSleep(char *string){
    for (int i = 0; i < strlen(string); i++){
        Sleep(10);
        printf("%c", string[i]);
    }
}

int generateRandomNumber(int n){
    srand(time(NULL));
    return rand()%n;
}

void wellcomeMessage(){
    char message[] = "Wellcome to Rock Paper Scissor Game";
    nextLine(1);
    useSleep(message);
    nextLine(1);
}

void letStartGameMessage(char *name){
    char preText[] = "Come on \"";
    char postText[] = "\", lets start the game....";
    nextLine(1);
    useSleep(preText);
    useSleep(name);
    useSleep(postText);
}

void addSeperator(){
    for (int i = 0; i < 60; i++)
    {
        Sleep(30);
        printf("=");
    }
    printf("\n");
}

void gameInstructions(){
    char firstLine[] = "***Read the instruction very carefully ***";
    char secondLine[] = "Enter 1 to choose \"Rock\".";
    char thirdLine[] = "Enter 2 to choose \"Paper\".";
    char fourthLine[] = "Enter 3 to choose \"Scissor\".";
    useSleep(firstLine);
    nextLine(1);
    useSleep(secondLine);
    nextLine(1);
    useSleep(thirdLine);
    nextLine(1);
    useSleep(fourthLine);
    nextLine(1);
}

void generateGameOutput(char *name, int selectedOption){
    switch (selectedOption)
    {
        case 1:
            useSleep(name);
            useSleep(" have chosen \"Rock\".");
            nextLine(1);
            break;
        case 2:
            useSleep(name);
            useSleep(" have chosen \"Paper\".");
            nextLine(1);
            break;
        case 3:
            useSleep(name);
            useSleep(" have chosen \"Scissor\".");
            nextLine(1);
            break;
        default:
            break;
    }
}

int checkWinner(int computer, int person){
    if (computer == person)
    {
        return 0;   // return 0 => equal
    }
    if(computer == 1)
    {
        if(person == 2){
            return 2;   // return 2 => person
        }
        if(person == 3){
            return 1;   // return 1 => computer
        }
    }
    if(computer == 2)
    {
        if(person == 1){
            return 1;   // return 1 => computer
        }
        if(person == 3){
            return 2;   // return 2 => person
        }
    }
    if(computer == 3)
    {
        if(person == 1){
            return 2;   // return 2 => person
        }
        if(person == 2){
            return 1;   // return 1 => computer
        }
    }
    
}

void game(char *name){
    int turn = 1;
    int personWinCount = 0;
    int computerWinCount = 0;

    while (turn <= 3)
    {
        srand(time(NULL));
        int selectedOption;
        int computerInput = rand()%3;
        char count[5];
        int currentWinner;  // 0 => equal, 1 => computer, 2 => person
        useSleep(name);
        useSleep(", Please enter your option for round ");
        sprintf(count, "%d", turn);
        useSleep(count);
        useSleep(": ");
        scanf("%d", &selectedOption);
        generateGameOutput(name, selectedOption);
        Sleep(10);
        generateGameOutput("Computer", computerInput);
        currentWinner = checkWinner(computerInput, selectedOption);
        if(currentWinner == 0){
            useSleep("Both player are equal.");
        }
        if(currentWinner == 1){
            useSleep("Winner for this round is Computer.");
            computerWinCount++;
        }
        if(currentWinner == 2){
            useSleep("Winner for this round is ");
            useSleep(name);
            useSleep(".");
            personWinCount++;
        }
        nextLine(1);
        addSeperator();
        nextLine(1);
        turn++;
    }
    nextLine(1);
    if((personWinCount == 0 && computerWinCount == 0) || (personWinCount == computerWinCount)){
        useSleep("Both player have equal score. Therefore no one is winner");
    }else if(personWinCount > computerWinCount){
        useSleep("Overall Winner is ");
        useSleep(name);
        useSleep(".");
    }else{
        useSleep("Overall Winner is Computer.");
    }
    nextLine(2);
}

int main()
{
    char name[30];
    wellcomeMessage();
    addSeperator();
    nextLine(1);
    useSleep("First Player name is \"Computer\"");
    nextLine(1);
    useSleep("Please enter your name: ");
    gets(name);
    letStartGameMessage(name);
    nextLine(2);
    gameInstructions();
    addSeperator();
    nextLine(1);
    game(name);

    return 0;
}
