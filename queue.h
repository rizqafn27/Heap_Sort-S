#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include "boolean.h"
#include "slink.h"

void EnQueue(LinkAddress *p,infotype value);
void DeQueue(LinkAddress *p,infotype *X);
 
#endif

