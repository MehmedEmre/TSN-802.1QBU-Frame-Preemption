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


network Network
{
    @display("bgb=317.706,152.0255");

    submodules:

        switch1: Switch {

            @display("p=110.150215,72.82659;i=old/switch2");
        }


        switch2: Switch {

            @display("p=200.27312,72.82659;i=old/switch2");
        }

        workstation: Generator {
            @display("p=24.578974,14.565318;i=device/pc4");
        }

        ExpressGenerator: Generator {
            @display("p=24.578974,129.72237;i=device/cpu");
        }

        Other: other {
            @display("p=278.10654,73.28175;i=block/bucket");
        }



    connections:

        workstation.generatorOut --> switch1.switchIn1;
        ExpressGenerator.generatorOut --> switch1.switchIn2;
        switch1.switchOut1 --> switch2.switchIn3;
        switch2.switchOut1 --> switch1.switchIn3;

        switch2.switchIn1 <-- Other.otherOut1;
        switch2.switchIn2 <-- Other.otherOut2;

}
