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

#include "FIFO1.h"

#include "mPacket_m.h"

Define_Module(FIFO1);


FIFO1::FIFO1() {
    // TODO Auto-generated constructor stub

}

FIFO1::~FIFO1() {
    // TODO Auto-generated destructor stub
}


void FIFO1::initialize()
{


}

void FIFO1::handleMessage(cMessage *msg)
{

    if(strcmp(msg->getSenderModule()->getName(),"workstation") == 0)
    {
        queue1.insert(msg);
    }
    else if(msg->getSenderModuleId() == 7)
    {
        if(queue1.getLength() != 0)
        {
            mPacket *pack = (mPacket*)queue1.pop();
            send(pack, "fifoOut1");
        }
        else
        {
            cMessage* Msg = new cMessage("Queue Is Empty!");
            send(Msg, "fifoOut1");
        }
    }


    if(msg->getSenderModuleId() == 18)
    {
        queue1.insert(msg);
    }



}






