//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Generator.h"
#include "mPacket_m.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define DESTINATION_ID 6
using namespace std;

Define_Module(Generator);

Generator::Generator() {

}

Generator::~Generator() {

}

void Generator::initialize() {

    mPacket *packet = new  mPacket("Preemptable Packet");
    scheduleAt(simTime() + 1, packet);
    i = 0;
}


void Generator::handleMessage(cMessage *msg) {

    srand(time(NULL));
    int r = 1 + rand() % 15;

    if(i >= 2)
    {
        i = 0;
    }

    char str[2];
    switch(i++)
    {
        case 0:
            strcpy(str, "S0");
            break;

        case 1:
            strcpy(str, "S1");
            break;
    }

    if(strcmp(msg->getSenderModule()->getName(),"workstation") == 0)
    {
        mPacket *packet = new  mPacket("Preemptable Packet");
        packet->setSMD(str);
        packet->setMAC_DID(DESTINATION_ID);
        packet->setMAC_SID(getId());
        packet->setPayload("Data");
        packet->setFragCount(0);
        packet->setSize(r);
        send(packet,"generatorOut");
    }
    else
    {
        mPacket *packet = new  mPacket("Express Packet");
        packet->setSMD("E");
        packet->setMAC_DID(DESTINATION_ID);
        packet->setMAC_SID(getId());
        packet->setSize(r);
        packet->setFragCount(0);
        send(packet,"generatorOut");
    }

    scheduleAt(simTime() + par("uretimPeriyodu").doubleValue(), msg);
}




