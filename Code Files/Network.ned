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
    submodules:
        Node1: Subscriber {
            Sid = 1;
           	interest = 1;
            @display("p=130,60");
        }
        Node2: Subscriber {
            Sid = 2;
            interest = 2; 
            @display("p=37,184");
        }
        Node3: Subscriber {
            Sid = 3;
            interest = 1;
            @display("p=149,340");
        }
        Node4: Publisher {
            Pid = 1;
            feed = 1;
            @display("p=623,87");
        }
        Node5: Publisher {
            Pid = 2;
            feed = 1;
            @display("p=707,200");
        }
        Node6: Publisher {
            Pid = 3;
            feed = 2;
            @display("p=616,349");
        }
        Node7: System {

            @display("p=362,184;is=l");
        }

    connections:
        Node1.StoSys --> {  delay = 100ms; } --> Node7.fromSub1;			//Subscriber to System
        Node7.toSub1 --> {  delay = 100ms; } --> Node1.fromSys;

        Node2.StoSys --> {  delay = 100ms; } --> Node7.fromSub2;
        Node7.toSub2 --> {  delay = 100ms; } --> Node2.fromSys;

        Node3.StoSys --> {  delay = 100ms; } --> Node7.fromSub3;
        Node7.toSub3 --> {  delay = 100ms; } --> Node3.fromSys;

        Node4.PtoSys --> {  delay = 100ms; } --> Node7.fromPub1;			//Publisher to System

        Node5.PtoSys --> {  delay = 100ms; } --> Node7.fromPub2;

        Node6.PtoSys --> {  delay = 100ms; } --> Node7.fromPub3;

}
