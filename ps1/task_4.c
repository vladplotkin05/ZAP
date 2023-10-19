#include<superkarel.h>
#define PERFORMANCE 50

void turn__right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(PERFORMANCE);
}
void turn__180(){
    set_step_delay(0);
    turn_left();
    set_step_delay(PERFORMANCE);
    turn_left();
}
void cheack_in_down(){
    while(front_is_clear()){
        step();
        if(!beepers_present()){
            put_beeper();

    }

    }

}





void red_road(){
    turn_left();
    while(front_is_clear()){
    if(beepers_present()){
        break;
        }
        step();
    }
    if(beepers_present()){
        cheack_in_down();
        turn__180();
        cheack_in_down();
        turn_left();

    }else{
    turn__180();
        while(front_is_clear()){
            step();
        }
        turn_left();

    }

}
int main(){
    turn_on("task_4.kw");
    set_step_delay(PERFORMANCE);
    while(front_is_clear()){   
        red_road();
        step();
    
    }
    red_road();


    turn_off();
return 0;
}







