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




module pMAC
{
    @display("bgb=281,209");
    gates:
        input pMacIn1;
        output pMacOut1;
        input pMacIn2;
        output pMacOut2;


    submodules:

        reassemble: Buffer {
            @display("p=204.36961,82.38508");
        }

        buffer2: Buffer {
            @display("p=85.57124,118.34321");
        }

    connections:

        pMacIn1 --> buffer2.bufferIn1;
        pMacIn2 --> reassemble.bufferIn1;
        reassemble.bufferOut1 --> pMacOut1;
        buffer2.bufferOut1 --> pMacOut2;

}
