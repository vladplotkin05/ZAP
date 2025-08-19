#include <superkarel.h>
#define FAST 52
#define bppick             \
    if (beepers_present()) \
    {                      \
        pick_beeper();     \
    }
#define bppuut            \
    if (beepers_in_bag()) \
    {                     \
        put_beeper();     \
    }
#define LLL turn__right();



void turn__right()
{
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(FAST);
    turn_left();
}

void turn__180()
{
    set_step_delay(0);
    turn_left();
    set_step_delay(FAST);
    turn_left();
}

void put_alll_beepers()
{
    while (beepers_in_bag())
    {
        put_beeper();
    }
}

void cleaner_coat_cheack()
{
    while (!facing_east())
    {
        turn_left();
    }
    while (front_is_clear())
    {
        step();
        if (beepers_present())
        {
            pick_beeper();
        }
    }
    turn__180();
    if (!right_is_clear())
    {
        if (beepers_in_bag())
        {
            put_beeper();
        }
    }
    while (!front_is_blocked())
    {
        step();
        if (!right_is_clear())
        {
            if (beepers_in_bag())
            {
                put_beeper();
            }
        }
    }
}

void cleaner_before_over_IN_beepers()
{
    turn_left();
    if (front_is_clear())
    {
        step();
    }
    else
    {
        turn_left();
        return;
    }
    turn_left();
    while (front_is_clear())
    {
        step();
        if (beepers_present())
        {
            pick_beeper();
        }
    }
    turn__180();
    while (front_is_clear())
    {
        turn__right();
        step();
        if (beepers_present())
        {
            turn__180();
            step();
            bppuut if (!beepers_in_bag())
            {
                LLL while (front_is_clear())
                {
                    step();
                }
                return;
            }
            LLL
            step();
        }
        else
        {
            turn__180();
            step();
            LLL
            step();
        }
    }
}

void turn_back_in_first_corner()
{
    turn__180();
    while (true)
    {
        if (facing_east())
        {
            turn_left();
            step();
            turn_left();
            if (beepers_present())
            {
                break;
            }
        }
        else
        {
            LLL
            step();
            LLL if (beepers_present())
            {
                break;
            }
        }
        while (front_is_clear())
        {
            step();
            if (beepers_present())
            {
                break;
            }
        }
    }

    while (!facing_north())
    {
        turn_left();
    }
    while (front_is_clear())
    {
        step();
    }
    turn_left();
    while (front_is_clear())
    {
        step();
    }
    turn__180();
}

int main()
{
    turn_on("task_3.kw");

    set_step_delay(0);
    cleaner_coat_cheack();
    while (right_is_clear())
    {
        cleaner_before_over_IN_beepers();
    }
    set_step_delay(100);
    turn_back_in_first_corner();

    turn_off();
    return 0;
}
