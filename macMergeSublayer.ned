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


module macMergeSublayer
{
    @display("bgb=284,273");
    gates:
        output mmsOutput1;
        input mmsInput1;
        output mmsOutput2;
        input mmsInput2;
        output mmsOutput3;
        input mmsInput3;

    submodules:

        channel_pMAC: receiveProcessing {
            @display("p=144.73848,128.49232;is=l");
        }
        transmitAndReceive: transmitBlock {
            @display("p=220.80002,175.01541");
        }
        channel_eMAC: expressFilter {
            @display("p=53.169235,175.75386");
        }

    connections:
        mmsInput1 --> transmitAndReceive.transmitIn1; //pMAC girişi
        mmsInput2 --> transmitAndReceive.transmitIn2; //eMAC girişi

        mmsInput3 --> transmitAndReceive.transmitIn3; //Switch2 girişi

        transmitAndReceive.transmitOut1 --> channel_eMAC.expressIn; //transmit to express

        channel_eMAC.expressOut1 --> channel_pMAC.receiveIn; //express to receive

        transmitAndReceive.transmitOut2 --> mmsOutput3; //Switch 2'e gonderim.
        channel_pMAC.receiveOut --> mmsOutput1; //receive to pMAC
        channel_eMAC.expressOut2 --> mmsOutput2; //express to eMAC

}
