#include<superkarel.h>
#define FAST 99

void turn__right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(FAST);
    turn_left();
}
void turn__180(){
    set_step_delay(0);
    turn_left();
    set_step_delay(FAST);
    turn_left();
}
void put_alll_beepers(){
    while(beepers_in_bag()){
        put_beeper();
    }
}

void cleaner_coat_cheack(){
  
  while(front_is_clear()){
    while(!facing_east()){
        turn_left();
    }
    while(!beepers_present()){
        step();
    }
    turn__right();
    while(beepers_present()){
        pick_beeper();
        step();
    }
    turn__180();
    while(front_is_clear()){
        step();
    }
    turn__right();
    put_alll_beepers();
    step();
    }
    cleaner_coat_cheack();

}
int main(){
    turn_on("task_3.kw");
    set_step_delay(FAST);
    while(true){
        cleaner_coat_cheack();
    }
    cleaner_coat_cheack();
    turn_off();
return 0;
}
