
int kbhit();

char screen[50][50];

int init();

int main(){//will be renamed startgame in the end
    init();
    while (1){
        if (kbhit()){
            break;
        }
        //usleep(50000);
    }
    while (1){

    }
}
