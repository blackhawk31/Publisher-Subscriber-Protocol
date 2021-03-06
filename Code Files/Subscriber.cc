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
#include "InterestMsg_m.h"
#include "Subscriber.h"

Define_Module(Subscriber);

void Subscriber::initialize()
{
    Sid = par("Sid");
    Interest = par("interest");
    gin = gate("fromSys");
    gout = gate("StoSys");

    if(Sid == 1 || Sid == 2 || Sid == 3){
            InterestMsg* event = new InterestMsg();
            scheduleAt(0,event);
        }

}
void Subscriber::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage()){
            InterestMsg* interestMsg=new InterestMsg();
            //interestMsg->setId(1);
            interestMsg->setInterest(Interest);
            interestMsg->setSaddress(Sid);
            send(interestMsg,gout);
        }

}



