#include "Champion.h"
#include <stdio.h>
#include <stdlib.h>

// Helper function to generate a random number within a range
int randomInRange(int min, int max) { return min + rand() % (max - min + 1); }

// Create a new champion
Champion *createChampion()
{
    Champion *newChampion = malloc(sizeof(Champion));
    if (!newChampion)
    {
        return NULL;
    }

    // Assign a random role to the champion
    newChampion->role =
        randomInRange(0, 3);

    // Assign a level based on role
    switch (newChampion->role)
    {
    case MAGE:
        newChampion->level = randomInRange(5, 8);
        break;
    case FIGHTER:
        newChampion->level = randomInRange(1, 4);
        break;
    case SUPPORT:
        newChampion->level = randomInRange(3, 6);
        break;
    case TANK:
        newChampion->level = randomInRange(1, 8);
        break;
    }

    newChampion->next = NULL;
    return newChampion;
}

const char *roleToString(Role role)
{
    switch (role)
    {
    case MAGE:
        return "MAGE";
    case FIGHTER:
        return "FIGHTER";
    case SUPPORT:
        return "SUPPORT";
    case TANK:
        return "TANK";
    default:
        return "UNKNOWN";
    }
}

// Add a new champion to the list in descending order of level
Champion *addChampion(Champion *head, Champion *c)
{
    if (!head || c->level > head->level)
    {
        c->next = head;
        return c;
    }

    Champion *current = head;
    while (current->next && current->next->level >= c->level)
    {
        current = current->next;
    }

    c->next = current->next;
    current->next = c;

    return head;
}

// Build a list of champions
Champion *buildChampionList(int n)
{
    Champion *head = NULL;
    for (int i = 0; i < n; i++)
    {
        Champion *newChampion = createChampion();
        head = addChampion(head, newChampion);
    }
    return head;
}

// Print the list of champions
void printChampionList(Champion *head)
{
    Champion *current = head;
    while (current)
    {
        char roleChar;
        switch (current->role)
        {
        case MAGE:
            roleChar = 'M';
            break;
        case FIGHTER:
            roleChar = 'F';
            break;
        case SUPPORT:
            roleChar = 'S';
            break;
        case TANK:
            roleChar = 'T';
            break;
        }
        printf("%c%d ", roleChar, current->level);
        current = current->next;
    }
    printf("\n");
}

// Remove and free the first champion from the list
Champion *removeChampion(Champion *head)
{
    if (!head)
    {
        return NULL;
    }

    Champion *nextChampion = head->next;
    free(head);
    return nextChampion;
}

// Destroy the entire list of champions
Champion *destroyChampionList(Champion *head)
{
    while (head)
    {
        head = removeChampion(head);
    }
    return NULL;
}