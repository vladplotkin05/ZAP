#include <superkarel.h>
#define ULTRABOOST 97

void turn__180()
{
    set_step_delay(0);
    turn_left();
    set_step_delay(ULTRABOOST);
    turn_left();
}

void turn__right()
{
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(ULTRABOOST);
    turn_left();
}

void treasure_on_map()
{
    while (!beepers_present())
    {
        step();
    }
    if (beepers_present())
    {
        pick_beeper();
        while (!facing_north())
        {
            turn_left();
        }
    }
    if (beepers_present())
    {
        pick_beeper();
        while (!facing_west())
        {
            turn_left();
        }
    }
    if (beepers_present())
    {
        pick_beeper();
        while (!facing_south())
        {
            turn_left();
        }
    }
    if (beepers_present())
    {
        pick_beeper();
        while (!facing_east())
        {
            turn_left();
        }
    }
    if (beepers_present())
    {
        pick_beeper();
        return;
    }
    treasure_on_map();
}

int main()
{
    turn_on("task_6.kw");
 
    set_step_delay(ULTRABOOST);
    treasure_on_map();

    turn_off();
    return 0;
}
