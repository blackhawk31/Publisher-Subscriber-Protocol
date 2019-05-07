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

#include "System.h"
#include "SubscriberMsg_m.h"
#include "feed_m.h"

Define_Module(System);

void System::initialize()
{
    // TODO - Generated method body
    Sgin1 = gate("fromSub1");
    Sgin2 = gate("fromSub2");
    Sgin3 = gate("fromSub3");
    Pgin1 = gate("fromPub1");
    Pgin2 = gate("fromPub2");
    Pgin3 = gate("fromPub3");

    Sgout1 = gate("toSub1");
    Sgout2 = gate("toSub2");
    Sgout3 = gate("toSub3");
}

void System::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->getArrivalGate()==Pgin1){
        Feed* received1 = static_cast<Feed*>(msg);
        SubscriberMsg* sm1 = new SubscriberMsg();
        sm1->setFeedForSub(received1->getFeed());
        send(sm1->dup(), Sgout1);
        send(sm1, Sgout3);
    }
    if(msg->getArrivalGate()==Pgin2){
        Feed* received2 = static_cast<Feed*>(msg);
        SubscriberMsg* sm2 = new SubscriberMsg();
        sm2->setFeedForSub(received2->getFeed());
        send(sm2->dup(), Sgout1);
        send(sm2, Sgout3);
    }
    if(msg->getArrivalGate()==Pgin3){
         Feed* received3 = static_cast<Feed*>(msg);
         SubscriberMsg* sm3 = new SubscriberMsg();
         sm3->setFeedForSub(received3->getFeed());
         send(sm3, Sgout2);
    }
}
