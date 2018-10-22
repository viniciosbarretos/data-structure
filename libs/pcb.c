#include <stdio.h>
#include <stdlib.h>
#include "pcb.h"
#include "rand.h"

//Creates 38% rate for process interruption
unsigned int _interruptionGenerator(unsigned int quantum) {

    // This is about 38% likely to happen, it`s possible only one interruption for process
    if (getRandom(0, 100) < 38 && quantum > 1)
        return (unsigned) getRandom(1, quantum);
    else
        return 0;

//    return (getRandom(0, 101) <= 38) ? (unsigned) getRandom(1, quantum - 1) : 0;
}

// Allocate memory for pcb.
PCB* newPCB() {
    return (PCB*) malloc(sizeof(PCB));
}

// Create the pointer for a PCB.
PCB* generatePCB(unsigned int id, unsigned int creationTime) {
    PCB *pcb = newPCB();

    pcb->id = id;
    pcb->quantum = (unsigned) getRandom(1, 90);
    pcb->priority = (unsigned short) getRandom(0, 3);
    pcb->status = _pcbStatusNew;
    pcb->lineCounter = 0;
    pcb->interruption = _interruptionGenerator(pcb->quantum);
    pcb->next = NULL;
    pcb->startProcessingTime = 0;
    pcb->endProcessingTime = 0;
    pcb->creationTime = creationTime;
    pcb->waitTime = 0;

    return pcb;
}

PCB* getWaitTime(PCB* pcb) {
    pcb->waitTime = (unsigned) getRandom(1, 64);
    return pcb;
}
