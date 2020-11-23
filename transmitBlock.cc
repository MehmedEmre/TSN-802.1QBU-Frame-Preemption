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

#include "transmitBlock.h"

#include "mPacket_m.h"

Define_Module(transmitBlock);


transmitBlock::transmitBlock() {
    // TODO Auto-generated constructor stub

}

transmitBlock::~transmitBlock() {
    // TODO Auto-generated destructor stub
}

void transmitBlock::initialize() {



}

void transmitBlock::handleMessage(cMessage *msg) {

    if(strcmp(msg->getSenderModule()->getName(), "eMAC") == 0 || strcmp(msg->getSenderModule()->getParentModule()->getName(), "pMAC") == 0 )
    {
        send(msg, "transmitOut2");
    }


    if(msg->getSenderModuleId() == 14 && getId() == 25)
    {
        send(msg, "transmitOut1");
    }


}

