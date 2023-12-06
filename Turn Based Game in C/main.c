#include "Champion.h"
#include <stdio.h>
#include <stdlib.h>

void battleOutcome(Champion **player1, Champion **player2);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number_of_champions>\n", argv[0]);
        return 1;
    }

    int numChampions = atoi(argv[1]);
    if (numChampions <= 0)
    {
        fprintf(stderr, "Number of champions must be a positive integer.\n");
        return 1;
    }

    Champion *player1 = buildChampionList(numChampions);
    Champion *player2 = buildChampionList(numChampions);

    int round = 1;
    while (player1 && player2)
    {
        printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n");
        printf("----- ROUND %d -----\n", round);
        printf("Player 1: ");
        printChampionList(player1);
        printf("Player 2: ");
        printChampionList(player2);

        battleOutcome(&player1, &player2);

        player1 = removeChampion(player1);
        player2 = removeChampion(player2);

        round++;
    }

    printf("============ GAME OVER =============\n");
    printf("Player 1 ending champion list: ");
    printChampionList(player1);
    printf("Player 2 ending champion list: ");
    printChampionList(player2);

    destroyChampionList(player1);
    destroyChampionList(player2);

    return 0;
}

void battleOutcome(Champion **player1, Champion **player2)
{
    if (!(*player1) || !(*player2))
        return;

    Role role1 = (*player1)->role;
    Role role2 = (*player2)->role;
    int level1 = (*player1)->level;
    int level2 = (*player2)->level;

    // Helper function to compare levels
    int levelDifference = level1 - level2;

    printf("Player 1 is a %s and Player 2 is a %s\n", roleToString(role1),
           roleToString(role2));

    // Implementing logic for each role combination
    switch (role1)
    {
    case MAGE:
        switch (role2)
        {
        case MAGE:
            // MAGE vs MAGE
            if (levelDifference > 0)
            {
                printf("Player 1 (MAGE) loses one champion.\n");
                *player1 = removeChampion(*player1);
            }
            else if (levelDifference < 0)
            {
                printf("Player 2 (MAGE) wins and gains one new champion.\n");
                *player2 = addChampion(*player2, createChampion());
            }
            break;
        }
        break;
    }
}
