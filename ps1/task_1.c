#include <superkarel.h>
#define NITRO 97

void turn__right()
{
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(NITRO);
    turn_left();
}
void turn__180()
{
    set_step_delay(0);
    turn_left();
    set_step_delay(NITRO);
    turn_left();
}
void check_in_right()
{
    if (right_is_clear())
    {
        turn__right();
        while (front_is_clear())
        {
            step();
            if (beepers_present())
            {
                return;
            }
        }
        turn_left();
    }

    if (front_is_blocked())
    {
        turn_left();
        while (right_is_blocked())
        {
            step();
            if (beepers_present())
            {
                return;
            }
        }
        turn__right();
    }

    step();
    if (beepers_present())
    {
        return;
    }
}

void cheack_in_left()
{
    if (left_is_clear())
    {
        turn_left();
        while (front_is_clear())
        {
            step();
            if (beepers_present())
            {
                return;
            }
        }
        turn__right();
    }
    if (front_is_blocked())
    {
        turn__right();
        while (left_is_blocked())
        {
            step();
            if (beepers_present())
            {
                return;
            }
        }
        turn_left();
    }
    step();
    if (beepers_present())
    {
        return;
    }
}

int main()
{
    turn_on("task_1.kw");

    if (beepers_present())
    {
        pick_beeper();
        turn__180();
        turn_off();
        return 0;
    }
    set_step_delay(0);
    put_beeper();
    do
    {
        check_in_right();
        if (beepers_present())
        {
            break;
        }
    } while (true);
    pick_beeper();
    set_step_delay(NITRO);
    while (!facing_west())
    {
        turn_left();
    }
    set_step_delay(300);
    do
    {
        cheack_in_left();
        if (beepers_present())
        {
            break;
        }
    } while (true);
    pick_beeper();
    while (!facing_west())
    {
        turn_left();
    }
    
    turn_off();
    return 0;
}
