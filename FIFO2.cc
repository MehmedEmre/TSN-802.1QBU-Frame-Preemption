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

#include "FIFO2.h"
#include "mPacket_m.h"
Define_Module(FIFO2);


FIFO2::FIFO2() {
    // TODO Auto-generated constructor stub

}

FIFO2::~FIFO2() {
    // TODO Auto-generated destructor stub
}


void FIFO2::initialize()
{



}

void FIFO2::handleMessage(cMessage *msg)
{

    if(strcmp(msg->getSenderModule()->getName(),"ExpressGenerator")==0)
    {
        queue2.insert(msg);
    }


    if(msg->getSenderModuleId() == 7){

        if(queue2.getLength() != 0)
        {
            mPacket *pack = (mPacket*)queue2.pop();
            send(pack,"fifoOut2");
        }
        else
        {
            cMessage* empt = new cMessage("Queue Is Empty!");
            send(empt,"fifoOut2");
        }
    }

    if(msg->getSenderModuleId() == 18)
    {
        queue2.insert(msg);
    }
}






