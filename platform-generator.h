#ifndef PLATFORMGENERATOR_H
#define PLATFORMGENERATOR_H

#include "platform.h"
#include "platform1.h"
#include "platform2.h"
#include "platform3.h"
#include "monster.h"
#include "monster1.h"
#include "monster2.h"
#include "monster3.h"

platform* genplat();
platform2* genplat2();
monster* genmonst(platform* p);
#endif // PLATFORMGENERATOR_H
