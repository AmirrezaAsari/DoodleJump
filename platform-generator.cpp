#include "platform-generator.h"
#define PLATFORM_NUM 3

platform* genplat(){
    int plat_tp;
    platform* ptr;

    plat_tp = rand() % 30;
    if(plat_tp<=24){
        ptr = new platform1;
    }
    else if(plat_tp <29 && plat_tp>=25)
    {
        ptr = new platform3;
    }
    else{
        ptr = new platform2;
    }

    return ptr;
}
platform2* genplat2(){
    platform2 *ptr = new platform2;
    return ptr;

}
