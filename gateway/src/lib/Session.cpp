//
// Copyright 2016 (C). Alex Robenko. All rights reserved.
//

// This file is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


#include "mqttsn/gateway/Session.h"
#include "SessionImpl.h"

namespace mqttsn
{

namespace gateway
{

Session::Session()
  : m_pImpl(new SessionImpl)
{
}

Session::~Session() = default;

void Session::setNextTickProgramReqCb(NextTickProgramReqCb&& func)
{
    m_pImpl->setNextTickProgramReqCb(std::move(func));
}

void Session::setSendDataClientReqCb(SendDataReqCb& func)
{
    m_pImpl->setSendDataClientReqCb(std::move(func));
}

void Session::setSendDataBrokerReqCb(SendDataReqCb&& func)
{
    m_pImpl->setSendDataBrokerReqCb(std::move(func));
}

void Session::setGatewayId(std::uint8_t value)
{
    m_pImpl->setGatewayId(value);
}

bool Session::start()
{
    return m_pImpl->start();
}

void Session::stop()
{
    m_pImpl->stop();
}

void Session::tick(unsigned ms)
{
    m_pImpl->tick(ms);
}

}  // namespace gateway

}  // namespace mqttsn

