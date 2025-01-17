#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 216
#define MAX_ITEM_LEN 16

typedef struct {
    char item[MAX_ITEM_LEN + 1];
    int frequency;
} ItemFrequency;

ItemFrequency itemList[MAX_ITEMS];
int currentItemCount = 0;

int findItemIndex(const char *item) {
    for (int i = 0; i < currentItemCount; i++) {
        if (strcmp(itemList[i].item, item) == 0) {
            return i;
        }
    }
    return -1;
}

void incrementFrequency(const char *item) {
    int index = findItemIndex(item);
    if (index == -1) {
        if (currentItemCount < MAX_ITEMS) {
            strcpy(itemList[currentItemCount].item, item);
            itemList[currentItemCount].frequency = 1;
            currentItemCount++;
        }
    } else {
        itemList[index].frequency++;
    }
}

void displayFrequency(const char *item) {
    int index = findItemIndex(item);
    if (index == -1) {
        printf("0\n");
    } else {
        printf("%d\n", itemList[index].frequency);
    }
}

void resetFrequency(const char *item) {
    int index = findItemIndex(item);
    if (index != -1) {
        itemList[index].frequency = 0;
    }
}

int main() {
    int command;
    char item[MAX_ITEM_LEN + 1];

    while (scanf("%d %s", &command, item) != EOF) {
        if (command == 1) {
            incrementFrequency(item);
        } else if (command == 2) {
            displayFrequency(item);
        } else if (command == 3) {
            resetFrequency(item);
        }
    }

    return 0;
}
