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

#include "emac.h"

#include "mPacket_m.h"

Define_Module(emac);


emac::emac() {
    // TODO Auto-generated constructor stub

}

emac::~emac() {
    // TODO Auto-generated destructor stub
}


void emac::initialize() {



}

void emac::handleMessage(cMessage *msg) {

    if(getId() == 12 )
    {
        send(msg, "eMacOut2");
    }
    else
    {
        send(msg, "eMacOut1");
    }
}


