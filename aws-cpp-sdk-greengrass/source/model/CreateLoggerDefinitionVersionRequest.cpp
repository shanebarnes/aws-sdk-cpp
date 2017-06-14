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

#include <aws/greengrass/model/CreateLoggerDefinitionVersionRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Greengrass::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

CreateLoggerDefinitionVersionRequest::CreateLoggerDefinitionVersionRequest() : 
    m_amznClientTokenHasBeenSet(false),
    m_loggerDefinitionIdHasBeenSet(false),
    m_loggersHasBeenSet(false)
{
}

Aws::String CreateLoggerDefinitionVersionRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_loggersHasBeenSet)
  {
   Array<JsonValue> loggersJsonList(m_loggers.size());
   for(unsigned loggersIndex = 0; loggersIndex < loggersJsonList.GetLength(); ++loggersIndex)
   {
     loggersJsonList[loggersIndex].AsObject(m_loggers[loggersIndex].Jsonize());
   }
   payload.WithArray("Loggers", std::move(loggersJsonList));

  }

  return payload.WriteReadable();
}

Aws::Http::HeaderValueCollection CreateLoggerDefinitionVersionRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  Aws::StringStream ss;
  if(m_amznClientTokenHasBeenSet)
  {
    ss << m_amznClientToken;
    headers.insert(Aws::Http::HeaderValuePair("x-amzn-client-token", ss.str()));
    ss.str("");
  }

  return headers;

}



