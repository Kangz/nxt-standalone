// Copyright 2018 The Dawn Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef BACKEND_VULKAN_COMPUTEPIPELINEVK_H_
#define BACKEND_VULKAN_COMPUTEPIPELINEVK_H_

#include "backend/ComputePipeline.h"

#include "common/vulkan_platform.h"

namespace backend { namespace vulkan {

    class Device;

    class ComputePipeline : public ComputePipelineBase {
      public:
        ComputePipeline(ComputePipelineBuilder* builder);
        ~ComputePipeline();

        VkPipeline GetHandle() const;

      private:
        VkPipeline mHandle = VK_NULL_HANDLE;
        Device* mDevice = nullptr;
    };

}}  // namespace backend::vulkan

#endif  // BACKEND_VULKAN_COMPUTEPIPELINEVK_H_
