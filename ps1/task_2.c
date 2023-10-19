#include<superkarel.h>
#define BOOST 97
void turn__180(){
    set_step_delay(0);
    turn_left();
    set_step_delay(BOOST);
    turn_left();
}
void turn__right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(BOOST);
    turn_left();
}
void tunnel_vision(){
    if(left_is_blocked()){
        while(front_is_clear()){
            step();
            if(beepers_present()){
                return;
            }
}}
    turn_left();
    step();
}
void spiral_room(){
   if(right_is_blocked()){
        while(front_is_clear()){
            step();
            if(front_is_blocked() && right_is_blocked()){        

            return;}
    }}
    turn__right();
    step();

}
int main(){
    turn_on("task_2.kw");
    set_step_delay(BOOST);
    if(beepers_present()){
        pick_beeper();
        return 0;
    }
    do{
        tunnel_vision();
        if(beepers_present()){
            break;}
   } while(true);
        pick_beeper();
    turn__180();
    step();
    while(true){   
        spiral_room();
        if(front_is_blocked() && right_is_blocked()){
            break;

        }
    }
    turn__right();
    turn_off();
return 0;
}
