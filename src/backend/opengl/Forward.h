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

#ifndef BACKEND_OPENGL_FORWARD_H_
#define BACKEND_OPENGL_FORWARD_H_

#include "backend/ToBackend.h"

namespace {
    class BindGroupBase;
    class BindGroup;
    class RenderPassDescriptor;
}  // namespace

namespace backend { namespace opengl {

    using BindGroup = BindGroupBase;
    using BindGroupLayout = BindGroupLayoutBase;
    class BlendState;
    class Buffer;
    class BufferView;
    class CommandBuffer;
    class ComputePipeline;
    class DepthStencilState;
    class Device;
    class InputState;
    class PersistentPipelineState;
    class PipelineLayout;
    class Queue;
    using RenderPassDescriptor = RenderPassDescriptorBase;
    class RenderPipeline;
    class Sampler;
    class ShaderModule;
    class SwapChain;
    class Texture;
    class TextureView;

    struct OpenGLBackendTraits {
        using BindGroupType = BindGroup;
        using BindGroupLayoutType = BindGroupLayout;
        using BlendStateType = BlendState;
        using BufferType = Buffer;
        using BufferViewType = BufferView;
        using CommandBufferType = CommandBuffer;
        using ComputePipelineType = ComputePipeline;
        using DepthStencilStateType = DepthStencilState;
        using DeviceType = Device;
        using InputStateType = InputState;
        using PipelineLayoutType = PipelineLayout;
        using QueueType = Queue;
        using RenderPassDescriptorType = RenderPassDescriptor;
        using RenderPipelineType = RenderPipeline;
        using SamplerType = Sampler;
        using ShaderModuleType = ShaderModule;
        using SwapChainType = SwapChain;
        using TextureType = Texture;
        using TextureViewType = TextureView;
    };

    template <typename T>
    auto ToBackend(T&& common) -> decltype(ToBackendBase<OpenGLBackendTraits>(common)) {
        return ToBackendBase<OpenGLBackendTraits>(common);
    }

}}  // namespace backend::opengl

#endif  // BACKEND_OPENGL_FORWARD_H_
