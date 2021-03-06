// Copyright 2017 The Dawn Authors
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

#include "backend/opengl/SamplerGL.h"

#include "backend/opengl/DeviceGL.h"
#include "common/Assert.h"

namespace backend { namespace opengl {

    namespace {
        GLenum MagFilterMode(dawn::FilterMode filter) {
            switch (filter) {
                case dawn::FilterMode::Nearest:
                    return GL_NEAREST;
                case dawn::FilterMode::Linear:
                    return GL_LINEAR;
                default:
                    UNREACHABLE();
            }
        }

        GLenum MinFilterMode(dawn::FilterMode minFilter, dawn::FilterMode mipMapFilter) {
            switch (minFilter) {
                case dawn::FilterMode::Nearest:
                    switch (mipMapFilter) {
                        case dawn::FilterMode::Nearest:
                            return GL_NEAREST_MIPMAP_NEAREST;
                        case dawn::FilterMode::Linear:
                            return GL_NEAREST_MIPMAP_LINEAR;
                        default:
                            UNREACHABLE();
                    }
                case dawn::FilterMode::Linear:
                    switch (mipMapFilter) {
                        case dawn::FilterMode::Nearest:
                            return GL_LINEAR_MIPMAP_NEAREST;
                        case dawn::FilterMode::Linear:
                            return GL_LINEAR_MIPMAP_LINEAR;
                        default:
                            UNREACHABLE();
                    }
                default:
                    UNREACHABLE();
            }
        }

        GLenum WrapMode(dawn::AddressMode mode) {
            switch (mode) {
                case dawn::AddressMode::Repeat:
                    return GL_REPEAT;
                case dawn::AddressMode::MirroredRepeat:
                    return GL_MIRRORED_REPEAT;
                case dawn::AddressMode::ClampToEdge:
                    return GL_CLAMP_TO_EDGE;
                default:
                    UNREACHABLE();
            }
        }

    }  // namespace

    Sampler::Sampler(Device* device, const dawn::SamplerDescriptor* descriptor)
        : SamplerBase(device, descriptor) {
        glGenSamplers(1, &mHandle);
        glSamplerParameteri(mHandle, GL_TEXTURE_MAG_FILTER, MagFilterMode(descriptor->magFilter));
        glSamplerParameteri(mHandle, GL_TEXTURE_MIN_FILTER,
                            MinFilterMode(descriptor->minFilter, descriptor->mipmapFilter));
        glSamplerParameteri(mHandle, GL_TEXTURE_WRAP_R, WrapMode(descriptor->addressModeW));
        glSamplerParameteri(mHandle, GL_TEXTURE_WRAP_S, WrapMode(descriptor->addressModeU));
        glSamplerParameteri(mHandle, GL_TEXTURE_WRAP_T, WrapMode(descriptor->addressModeV));
    }

    GLuint Sampler::GetHandle() const {
        return mHandle;
    }

}}  // namespace backend::opengl
