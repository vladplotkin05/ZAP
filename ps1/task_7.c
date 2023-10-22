#include<superkarel.h>
#define FASTFuRIOS 77 
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
    }else{
        comeback_again();
        step();
        stocking_cheacking_the_room();
        if(front_is_clear()){
            pick_beeper();
            step();
        }
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
bool STOCKCHEACK_the_exit(){
    while(left_is_blocked()){
        step();
    }
    LLLL
    step();
    if(beepers_present()){
        comeback_again();
        step();
        LLLL
        step();
        return true;
    }else{
        stocking_cheacking_the_room();
    }
    return false;
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

    while(STOCKCHEACK_the_exit()){
        projectX();
    }
    turn_off();
    STOCKCHEACK_the_exit();
    projectX();
    set_step_delay(100);
    MERRFYYY();
    

    

    turn_off();
return 0;
}
