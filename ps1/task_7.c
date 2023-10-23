#include<superkarel.h>
#define FASTFuRIOS 120 
#define LLLL turn_left();
#define bp if(beepers_present()){return;}


void turn__right(){
    set_step_delay(0);
    LLLL
    LLLL
    set_step_delay(FASTFuRIOS);
    LLLL
}
void comeback_again(){
    set_step_delay(0);
    LLLL
    set_step_delay(FASTFuRIOS);
    LLLL
}    
void stock_X(){
        while(front_is_clear()){
                put_beeper();
                step();
            }
    put_beeper();        
    comeback_again();
    while(front_is_clear()){
            step();
    }   
    comeback_again();
}
void before_while_true(){
   while(true){
       while(!left_is_clear()&&front_is_clear()){
            step();
            bp
        }
        if(left_is_clear()){
            LLLL
            step();
            bp
            continue;
        }
        turn__right();
    }
}    
void stocking_cheacking_the_room(){
    put_beeper();
    before_while_true();
    if(front_is_clear()){
        put_beeper();
        step();
    }else{
        comeback_again();
        step();
        stocking_cheacking_the_room();
        comeback_again();
        step();
        pick_beeper();
        if(!beepers_present()){
            put_beeper();
        }
        comeback_again();
        step();
    }
}
void projectX(){
    if(front_is_clear()){
        step();
    }
    turn__right();
    while(front_is_clear()){
        step();
    }
    comeback_again();
}
void STOCKCHEACK_the_exit(){
    while(left_is_blocked()){
        step();
        if(front_is_blocked()){
            return;
        }
    }
    LLLL
    step();
    if(beepers_present()){
        comeback_again();
        step();
        LLLL
        if(front_is_blocked()){
            return;
        }
        step();
        STOCKCHEACK_the_exit();
    }else{
        stocking_cheacking_the_room();
        projectX();
    }
}
void MERRFYYY(){
    while(!facing_west()){
        LLLL
    }
    while(front_is_clear()){
        step();
    }
    comeback_again();
    while(true){
    while(left_is_blocked()){
        step();
        if(front_is_blocked()){
            return;
        }
    }
    if(left_is_clear()){
        LLLL
        step();
        pick_beeper();
        if(!beepers_present()){
            put_beeper();
        }else{
            pick_beeper();
        }
        comeback_again();
        step();
        LLLL
        step();
        if(front_is_blocked()){
            return;

        }
    }
}
}
int main(){
    turn_on("task_7.kw");    
    set_step_delay(0);
    stock_X();

    while(front_is_clear()){
        STOCKCHEACK_the_exit();
    }
    turn_off();
    set_step_delay(100);
    MERRFYYY();
    turn_off();
return 0;
}
