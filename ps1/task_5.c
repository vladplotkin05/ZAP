#include<superkarel.h>
#define _180_ turn__180();
#define _0_ set_step_delay(0);
#define _77_ set_step_delay(77);
#define LLL turn_left();

void turn__180(){
    _0_
    LLL
    _77_
    LLL
}
void frame_tamer(){
        while(facing_north()){
            LLL
    }
        while(front_is_clear()){
            step();
    }
    turn_left();
    while(front_is_clear()){
        step();
    }
    _180_
    if(front_is_clear()){
        while(front_is_clear()){  
            put_beeper();
            step();
        }
    }   
}
void neymar();
void messi();
void mbappe();
void psg(){
    neymar();
    messi();
    mbappe();
    }
void neymar() {
    put_beeper();
        while (front_is_clear()){
            step();
            put_beeper();
    }
    _180_
}
void messi() {      
    while (front_is_clear()) {  
        step();
    }
    _180_
    while(!beepers_present()) {
        step();
    }
    step();
    if(beepers_present()){
        _180_
        step();
        pick_beeper();
        _180_
        messi();
    }
}
void mbappe(){
    _180_
    step();
}
void square_draw(){
    while(true){
    if(!beepers_present()){
        while(front_is_clear()){
            put_beeper();
            step();
            if(beepers_present()){
            return ;
            }
        }
    turn_left();
    }
 }
}
int main(){
    turn_on("task_5.kw");
    _77_
    frame_tamer();
    psg();
    LLL
    psg();
    while(front_is_clear()){
        step();    
    }
    turn_left();
    square_draw();
    turn_left();
    step();
    while(!beepers_present()){
        step();
    }
    pick_beeper();
    while(!facing_north()){
        turn_left();
        }
    turn_off();
return 0;
}







