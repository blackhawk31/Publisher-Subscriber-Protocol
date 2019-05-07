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

#include "Publisher.h"
#include "feed_m.h"

Define_Module(Publisher);

void Publisher::initialize()
{
    // TODO - Generated method body
    Pid = par("Pid");
    pubFeed = par("feed");
    gout = gate("PtoSys");

    if(Pid == 1 || Pid == 2 || Pid == 3){
        Feed* event = new Feed();
        scheduleAt(0,event);
      }
}

void Publisher::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->isSelfMessage()){
        Feed* FeedMsg = new Feed();
        FeedMsg->setFeed(pubFeed);
        FeedMsg->setSaddress(Pid);
        send(FeedMsg, gout);
    }
}
