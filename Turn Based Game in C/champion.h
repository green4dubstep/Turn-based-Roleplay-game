#ifndef CHAMPION_H
#define CHAMPION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
    MAGE,
    FIGHTER,
    SUPPORT,
    TANK
} Role;

typedef struct Champion
{
    Role role;
    int level;
    struct Champion *next;
} Champion;

Champion *createChampion();
Champion *addChampion(Champion *head, Champion *c);
Champion *buildChampionList(int n);
void printChampionList(Champion *head);
Champion *removeChampion(Champion *head);
Champion *destroyChampionList(Champion *head);

#endif