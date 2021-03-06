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

#include "backend/metal/QueueMTL.h"

#include "backend/metal/CommandBufferMTL.h"
#include "backend/metal/DeviceMTL.h"

namespace backend { namespace metal {

    Queue::Queue(Device* device) : QueueBase(device) {
    }

    void Queue::Submit(uint32_t numCommands, CommandBuffer* const* commands) {
        Device* device = ToBackend(GetDevice());
        device->Tick();
        id<MTLCommandBuffer> commandBuffer = device->GetPendingCommandBuffer();

        for (uint32_t i = 0; i < numCommands; ++i) {
            commands[i]->FillCommands(commandBuffer);
        }

        device->SubmitPendingCommandBuffer();
    }

}}  // namespace backend::metal
