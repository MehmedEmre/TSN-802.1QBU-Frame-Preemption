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

#include "Buffer.h"
#include "mPacket_m.h"



Define_Module(Buffer);

Buffer::Buffer()
{
    // TODO Auto-generated constructor stub

}

Buffer::~Buffer()
{
    // TODO Auto-generated destructor stub
}


void Buffer::initialize()
{
    temp = -1;
    sflag = 0;
    drop_flag = 0;
}


void Buffer::handleMessage(cMessage *msg)
{
    if(getId() == 27)
    {
        mPacket *pckt = (mPacket*) msg;

        if(temp < pckt->getFragCount())
        {
            buffer_queue.insert(pckt);
            temp = pckt->getFragCount();

            if(pckt->getFragCount() == pckt->getSize() - 1)
            {
                mPacket* pckt = (mPacket*) msg;
                pckt->setFragCount(NULL);

                while(buffer_queue.getLength() != 0)
                {
                    buffer_queue.pop();
                }

                temp = -1;
                send(pckt, "bufferOut1");
            }
        }
        else
        {
            while(buffer_queue.getLength() != 0)
            {
                if(drop_flag == 0)
                {
                    EV << "Packet's Dropped!" << endl;
                    drop_flag = 1;
                }

                buffer_queue.pop();
            }

            drop_flag = 0;
            buffer_queue.insert(pckt);
            temp = pckt->getFragCount();
        }
    }
    else
    {
        if(strcmp(msg->getSenderModule()->getName(), "TransmissionSelection") == 0)
        {
            if(strcmp(msg->getName(), "Continue!") == 0 )
            {
                sflag = 0;
                scheduleAt(simTime() + 0.50, msg);
            }
            else if(strcmp(msg->getName(), "STOP!") == 0)
            {
                sflag = 1;
            }
            else
            {
                while(buffer_queue.getLength() != 0)
                {
                    if(drop_flag == 0)
                    {
                        EV << "Packet's Dropped" << endl;
                        drop_flag = 1;
                    }

                    buffer_queue.pop();
                }

                drop_flag = 0;
                mPacket *temp = (mPacket*) msg;
                mPacket *ptr = new mPacket[temp->getSize()];

                for(int i = 0 ; i < temp->getSize() ; i++)
                {
                    ptr[i].setName(temp->getName());
                    ptr[i].setSMD(temp->getSMD());
                    ptr[i].setFragCount(i);
                    ptr[i].setSize(temp->getSize());
                    buffer_queue.insert(ptr+i);
                }
                scheduleAt(simTime(), msg);
            }
        }
        else
        {
            if(buffer_queue.getLength() !=0 && sflag == 0)
            {
                send((mPacket*) buffer_queue.pop(), "bufferOut1");
                scheduleAt(simTime() + 0.50, msg);
            }
        }
    }
}


