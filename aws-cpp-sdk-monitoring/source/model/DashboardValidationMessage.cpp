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

#include <aws/monitoring/model/DashboardValidationMessage.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

namespace Aws
{
namespace CloudWatch
{
namespace Model
{

DashboardValidationMessage::DashboardValidationMessage() : 
    m_dataPathHasBeenSet(false),
    m_messageHasBeenSet(false)
{
}

DashboardValidationMessage::DashboardValidationMessage(const XmlNode& xmlNode) : 
    m_dataPathHasBeenSet(false),
    m_messageHasBeenSet(false)
{
  *this = xmlNode;
}

DashboardValidationMessage& DashboardValidationMessage::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode dataPathNode = resultNode.FirstChild("DataPath");
    if(!dataPathNode.IsNull())
    {
      m_dataPath = dataPathNode.GetText();
      m_dataPathHasBeenSet = true;
    }
    XmlNode messageNode = resultNode.FirstChild("Message");
    if(!messageNode.IsNull())
    {
      m_message = messageNode.GetText();
      m_messageHasBeenSet = true;
    }
  }

  return *this;
}

void DashboardValidationMessage::OutputToStream(Aws::OStream& oStream, const char* location, unsigned index, const char* locationValue) const
{
  if(m_dataPathHasBeenSet)
  {
      oStream << location << index << locationValue << ".DataPath=" << StringUtils::URLEncode(m_dataPath.c_str()) << "&";
  }

  if(m_messageHasBeenSet)
  {
      oStream << location << index << locationValue << ".Message=" << StringUtils::URLEncode(m_message.c_str()) << "&";
  }

}

void DashboardValidationMessage::OutputToStream(Aws::OStream& oStream, const char* location) const
{
  if(m_dataPathHasBeenSet)
  {
      oStream << location << ".DataPath=" << StringUtils::URLEncode(m_dataPath.c_str()) << "&";
  }
  if(m_messageHasBeenSet)
  {
      oStream << location << ".Message=" << StringUtils::URLEncode(m_message.c_str()) << "&";
  }
}

} // namespace Model
} // namespace CloudWatch
} // namespace Aws
