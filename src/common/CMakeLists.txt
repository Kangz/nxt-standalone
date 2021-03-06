# Copyright 2017 The Dawn Authors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set(COMMON_DIR ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND COMMON_SOURCES
    ${COMMON_DIR}/Assert.cpp
    ${COMMON_DIR}/Assert.h
    ${COMMON_DIR}/BitSetIterator.h
    ${COMMON_DIR}/Compiler.h
    ${COMMON_DIR}/DynamicLib.cpp
    ${COMMON_DIR}/DynamicLib.h
    ${COMMON_DIR}/HashUtils.h
    ${COMMON_DIR}/Math.cpp
    ${COMMON_DIR}/Math.h
    ${COMMON_DIR}/Platform.h
    ${COMMON_DIR}/Result.h
    ${COMMON_DIR}/Serial.h
    ${COMMON_DIR}/SerialQueue.h
    ${COMMON_DIR}/SwapChainUtils.h
    ${COMMON_DIR}/vulkan_platform.h
    ${COMMON_DIR}/windows_with_undefs.h
)

add_library(dawn_common STATIC ${COMMON_SOURCES})
target_include_directories(dawn_common PUBLIC ${SRC_DIR})
DawnInternalTarget("" dawn_common)
