#include <stdio.h>

int howManyActions(int people, int actions, int minutesAgo)
{
    int countOfPeople = 0;
    for ( ; people > 0; --people)
    {
        int peopleActions = 0;
        scanf("%d", &peopleActions);
        int countOfActions = 0;
        for ( ; peopleActions > 0; --peopleActions)
        {
            int actionsTime = 0;
            scanf("%d", &actionsTime);
            if (actionsTime <= minutesAgo)
            {
                ++countOfActions;
            }
        }
        if (countOfActions == actions)
        {
            ++countOfPeople;
        }
    }
    return countOfPeople;
}

int main() {
    int people = 0;
    int actions = 0;
    int minutesAgo = 0;
    printf("Insert count of people, acts, time\n");
    scanf("%d %d %d", &people, &actions, &minutesAgo);
    printf("%d", howManyActions(people, actions, minutesAgo));
    return 0;
}