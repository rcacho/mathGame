// // We are going to create a 2-player guessing game where players take turns to answer simple addition problems.
// The math questions are automatically generated by the game. It should do this by picking two numbers between 1 and 20.

// // Example prompt: "Player 1: What does 5 plus 3 equal?"

// // Both players start with 3 lives. They lose a life if they mis-answer a question. If a player gets a question wrong,
// the game should output the new scores for both players, so players know where they stand.

// // The game doesn't end until one of the players loses all their lives. At this point, the game should announce who won and what the other player's score is.

// // Please read all of the tips prior to starting your game.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct player
{
    char *name;
    int lives;
    int score;
};

struct question
{
    int first_number;
    int second_number;
    char *statement;
    int answer;
};

typedef struct player Player;
typedef struct question Question;

enum math { addition, subtraction, multiplication, division, power };



void gameController();
Player* playerCreator();
Player* constructUser(char name[]);
Player* constructComp();
int getRandomNumber();
int getRandomMath();
Question* questionGenerator();
void responseHandler(Player *user, Question *question);
// numberGenerator();
// mathGenerator();
// responseReciever();
// questionReciever();
// parseForNumbers();
// parseForMath();
// lifeHandler();


int main()
{
    
    gameController();
    
    return 0;
}


void gameController()
{
    Player* user;
    Player* comp;
    user = playerCreator();
    comp = constructComp();
    
    
    //Question *question;
    //question = questionGenerator();
    

    
     do  {
      	Question *question;
      	question = questionGenerator();
         printf("%s\n", question->statement);
         printf("%d\n", question->answer);
         responseHandler(user, question);
         
     } while (user->lives != 0);
}

Player* playerCreator()
{
    char name[35];
    Player *user;
    printf("What Is Your Name?:\n");
    fgets(name, 35, stdin);
    user = constructUser(name);
    printf("Hello %s\n", user->name);
    return user;
}

Player* constructUser(char name[])
{
    Player *user = malloc(sizeof(Player));
    
    user->lives = 3;
    user->name = name;
    user->score = 0;
    
    
    
    return user;
    
}

Player* constructComp()
{
    Player *comp = malloc(sizeof(Player));
    
    comp->lives = 3;
    comp->name = "comp";
    comp->score = 0;
    
    return comp;
}


Question* questionGenerator()
{
    Question *question = malloc(sizeof(Question));
    int i;
    char sentence[100];
    
    question->first_number = getRandomNumber();
    question->second_number = getRandomNumber();
    char first = question->first_number + '0';
    char second = question->second_number = '0';
    i = getRandomMath();
    
    switch(i)
    {
        case addition:
            
            strcpy(sentence, "What does _");
            sentence[10] = first;
            strcat(sentence, " plus _");
            sentence[17] = second;
            strcat(sentence, " equal?");
            
            question->answer = question->first_number + question->second_number;
            question->statement =  sentence;
            break;
            
        case subtraction:
            
            strcpy(sentence, "What does _");
            sentence[10] = first;
            strcat(sentence, " minus _");
            sentence[18] = second;
            strcat(sentence, " equal?");
            
            question->answer =  question->first_number - question->second_number;
            question->statement =  sentence;
            break;
            
        case multiplication:
            
            strcpy(sentence, "What is equal to _");
            sentence[17] = first;
            strcat(sentence, " multiplied by _");
            sentence[33] = second;
            strcat(sentence, "?");
            
            question->answer = question->first_number * question->second_number;
            question->statement = sentence;
            break;
            
        case division:
            
            strcpy(sentence, "What is equal to _");
            sentence[17] = first;
            strcat(sentence, " divided by _");
            sentence[30] = second;
            strcat(sentence, "?");
            
            question->answer = question->first_number / question->second_number;
            question->statement = sentence;
            break;
            
        case power:
            
            strcpy(sentence, "What is _");
            sentence[8] = first;
            strcat(sentence, " to the power of _");
            sentence[26] = second;
            strcat(sentence, " equal to?");
            
            question->answer = question->first_number ^ question->second_number;
            question->statement = sentence;
            break;
            
        default:
            
            strcpy(sentence, "What does _");
            sentence[10] = first;
            strcat(sentence, " plus _");
            sentence[17] = second;
            strcat(sentence, " equal?");
            
            question->answer = question->first_number + question->second_number;
            question->statement =  sentence; 	
            break;
    }

    return question;
}

void responseHandler(Player *user, Question *question)
{
    char response[100];
    fgets(response, 20, stdin);
    int num = atoi(response);
    
    if (question->answer == num)
    {
        printf("That's Correct!");
    } else {
        printf("Wrong! The correct answer is %d\n", question->answer);
        user->lives--;
    }
    
    
}


int getRandomNumber()
{
    int num;
    srand(time(NULL));
    num = rand()%(20);
    
    return num;
}

int getRandomMath() 
{	
    int num;
    srand(time(NULL));
    num = rand()%(5);
    
    return num;
}













