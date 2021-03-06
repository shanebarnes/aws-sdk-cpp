﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/ec2/model/InstanceIpv6AddressRequest.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

namespace Aws
{
namespace EC2
{
namespace Model
{

InstanceIpv6AddressRequest::InstanceIpv6AddressRequest() : 
    m_ipv6AddressHasBeenSet(false)
{
}

InstanceIpv6AddressRequest::InstanceIpv6AddressRequest(const XmlNode& xmlNode) : 
    m_ipv6AddressHasBeenSet(false)
{
  *this = xmlNode;
}

InstanceIpv6AddressRequest& InstanceIpv6AddressRequest::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode ipv6AddressNode = resultNode.FirstChild("Ipv6Address");
    if(!ipv6AddressNode.IsNull())
    {
      m_ipv6Address = ipv6AddressNode.GetText();
      m_ipv6AddressHasBeenSet = true;
    }
  }

  return *this;
}

void InstanceIpv6AddressRequest::OutputToStream(Aws::OStream& oStream, const char* location, unsigned index, const char* locationValue) const
{
  if(m_ipv6AddressHasBeenSet)
  {
      oStream << location << index << locationValue << ".Ipv6Address=" << StringUtils::URLEncode(m_ipv6Address.c_str()) << "&";
  }

}

void InstanceIpv6AddressRequest::OutputToStream(Aws::OStream& oStream, const char* location) const
{
  if(m_ipv6AddressHasBeenSet)
  {
      oStream << location << ".Ipv6Address=" << StringUtils::URLEncode(m_ipv6Address.c_str()) << "&";
  }
}

} // namespace Model
} // namespace EC2
} // namespace Aws
