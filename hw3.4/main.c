#include <stdio.h>

int howManyActions(int people, int actions, int time)
{
    int countOfPeople = 0;
    while (people > 0)
    {
        int peopleActions = 0;
        scanf("%d", &peopleActions);
        int countOfActions = 0;
        while (peopleActions > 0)
        {
            int actionsTime = 0;
            scanf("%d", &actionsTime);
            if (actionsTime <= time)
            {
                ++countOfActions;
            }
            --peopleActions;
        }
        if (countOfActions == actions)
        {
            ++countOfPeople;
        }
        --people;
    }
    return countOfPeople;
}

int main() {
    int people = 0;
    int actions = 0;
    int time = 0;
    printf("Insert count of people, acts, time\n");
    scanf("%d %d %d", &people, &actions, &time);
    printf("%d", howManyActions(people, actions, time));
    return 0;
}