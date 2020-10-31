void kmain();
void entry(){
    kmain();
}


void print(char* message){
    char *p_video_buffer = (char*) 0xb8000;
    char *p_next_char = message;
    while(*p_next_char){
        *p_video_buffer = *p_next_char;
        p_next_char++;
        p_video_buffer +=2 ; 
    }
}

void kmain(){
    print("helooo");
    while(1){
        
    }
}






// void print(){
//     char *base = (char *) 0xb8000;
    
//     char *ch = 'Z';
//     *base = *ch;
//     while(1){

//     } 
// }


