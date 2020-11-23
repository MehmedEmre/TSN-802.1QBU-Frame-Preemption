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

module Switch
{
    @display("bgb=419.20804,197.08696");
    gates:
        input switchIn1;
        input switchIn2;
        input switchIn3;
        output switchOut1;

    submodules:
        TransmissionSelection: ts {
            @display("p=176.60448,104.688225;i=block/rightarrow;is=l");
        }

        BestEffortFifo: FIFO1 {
            @display("p=66.90943,67.36459");
        }

        ExpressFifo: FIFO2 {
            @display("p=66.90943,128.35686");
        }

        MACms: macMergeSublayer {


            @display("p=357.76062,96.49523;i=block/mac");
        }


        pMAC: pMAC {
            @display("p=291.30637,36.86846;i=block/mac");
        }

        eMAC: emac {
            @display("p=291.76154,155.66684;i=block/mac");
        }


    connections:

        switchIn1 --> BestEffortFifo.fifoInSwitch1;
        switchIn2 --> ExpressFifo.fifoInSwitch2;
        MACms.mmsOutput3 --> switchOut1;
        switchIn3 --> MACms.mmsInput3;


        BestEffortFifo.fifoOut1 --> TransmissionSelection.tsBestEffortIn;
        TransmissionSelection.tsBestEffortOut --> BestEffortFifo.fifoInTs1;

        ExpressFifo.fifoOut2 --> TransmissionSelection.tsExpressIn;
        TransmissionSelection.tsExpressOut --> ExpressFifo.fifoInTs2;

        eMAC.eMacOut1 --> TransmissionSelection.tsEMacIn;
        TransmissionSelection.tsEMacOut --> eMAC.eMacIn1;

        pMAC.pMacOut1 --> TransmissionSelection.tsPMacIn;
        TransmissionSelection.tsPMacOut --> pMAC.pMacIn1;

        pMAC.pMacOut2 --> MACms.mmsInput1;
        MACms.mmsOutput1 --> pMAC.pMacIn2;

        eMAC.eMacOut2 --> MACms.mmsInput2;
        MACms.mmsOutput2 --> eMAC.eMacIn2;


}
