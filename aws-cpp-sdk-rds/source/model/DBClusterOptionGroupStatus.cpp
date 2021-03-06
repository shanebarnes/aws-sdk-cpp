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

#include <aws/rds/model/DBClusterOptionGroupStatus.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

namespace Aws
{
namespace RDS
{
namespace Model
{

DBClusterOptionGroupStatus::DBClusterOptionGroupStatus() : 
    m_dBClusterOptionGroupNameHasBeenSet(false),
    m_statusHasBeenSet(false)
{
}

DBClusterOptionGroupStatus::DBClusterOptionGroupStatus(const XmlNode& xmlNode) : 
    m_dBClusterOptionGroupNameHasBeenSet(false),
    m_statusHasBeenSet(false)
{
  *this = xmlNode;
}

DBClusterOptionGroupStatus& DBClusterOptionGroupStatus::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode dBClusterOptionGroupNameNode = resultNode.FirstChild("DBClusterOptionGroupName");
    if(!dBClusterOptionGroupNameNode.IsNull())
    {
      m_dBClusterOptionGroupName = dBClusterOptionGroupNameNode.GetText();
      m_dBClusterOptionGroupNameHasBeenSet = true;
    }
    XmlNode statusNode = resultNode.FirstChild("Status");
    if(!statusNode.IsNull())
    {
      m_status = statusNode.GetText();
      m_statusHasBeenSet = true;
    }
  }

  return *this;
}

void DBClusterOptionGroupStatus::OutputToStream(Aws::OStream& oStream, const char* location, unsigned index, const char* locationValue) const
{
  if(m_dBClusterOptionGroupNameHasBeenSet)
  {
      oStream << location << index << locationValue << ".DBClusterOptionGroupName=" << StringUtils::URLEncode(m_dBClusterOptionGroupName.c_str()) << "&";
  }

  if(m_statusHasBeenSet)
  {
      oStream << location << index << locationValue << ".Status=" << StringUtils::URLEncode(m_status.c_str()) << "&";
  }

}

void DBClusterOptionGroupStatus::OutputToStream(Aws::OStream& oStream, const char* location) const
{
  if(m_dBClusterOptionGroupNameHasBeenSet)
  {
      oStream << location << ".DBClusterOptionGroupName=" << StringUtils::URLEncode(m_dBClusterOptionGroupName.c_str()) << "&";
  }
  if(m_statusHasBeenSet)
  {
      oStream << location << ".Status=" << StringUtils::URLEncode(m_status.c_str()) << "&";
  }
}

} // namespace Model
} // namespace RDS
} // namespace Aws
