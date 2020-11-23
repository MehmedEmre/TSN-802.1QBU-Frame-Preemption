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

#include "ts.h"
#include "mPacket_m.h"

Define_Module(ts)

ts::ts() {
    // TODO Auto-generated constructor stub

}

ts::~ts() {
    // TODO Auto-generated destructor stub
}


void ts::initialize(){

    pflag = 0;
    cMessage* cont = new cMessage("Tick");
    scheduleAt(simTime() + 2, cont);
}

void ts::handleMessage(cMessage *msg){

    if(getId() == 7)
    {
        cMessage* cont = new cMessage("Is There a Packet?");


        if(strcmp(msg->getSenderModule()->getName(),"TransmissionSelection") == 0)
        {
            send(cont,"tsExpressOut");
            scheduleAt(simTime() + 2, msg);
        }


        if(strcmp(msg->getSenderModule()->getName(),"ExpressFifo") == 0)
        {
            if(strcmp(msg->getName(), "Queue Is Empty!") == 0)
            {
                if(pflag == 0)
                {
                    cMessage* dev = new cMessage("Continue!");
                    send(dev, "tsPMacOut");
                    pflag = 1;
                }
                send(cont,"tsBestEffortOut");
            }
            else
            {
                if(pflag == 1)
                {
                    cMessage* stp = new cMessage("STOP!");
                    send(stp, "tsPMacOut");
                    pflag = 0;
                }

                send(msg, "tsEMacOut");
                send(cont,"tsExpressOut");
            }
        }


        if(strcmp(msg->getSenderModule()->getName(),"BestEffortFifo") == 0)
        {
            if(strcmp(msg->getName(),"Queue Is Empty!") != 0)
            {
                send(msg,"tsPMacOut");
                pflag = 1;
                send(cont,"tsExpressOut");
            }
         }
    }
    else
    {
        if(msg->getSenderModuleId() == 27)
        {
            send(msg, "tsBestEffortOut");
        }
        else if(msg->getSenderModuleId() == 23)
        {
            send(msg, "tsExpressOut");
        }
    }
}



