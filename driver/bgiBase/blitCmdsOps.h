#ifndef GUNGNIR_DRIVER_BASE_BLITCMDSOPS_H
#define GUNGNIR_DRIVER_BASE_BLITCMDSOPS_H

#include "base.h"
#include "buffer.h"
#include "cmds.h"
#include "texture.h"
#include "types.h"
#include "enums.h"

#include <stddef.h>

GUNGNIR_NAMESPACE_OPEN_SCOPE

//// \struct HgiTextureGpuToCpuOp
///
/// Describes the properties needed to copy texture data from GPU to CPU.
/// This copies one mip at a time.
///
/// It is the responsibility of the caller to:
///   - ensure the destination buffer is large enough to receive the data
///     (keep in mind the destinationByteOffset, mipLevel, numLayers, etc).
///   - ensure the source texture and destination buffer are valid at the time
///     the command is executed.
///
/// <ul>
/// <li>gpuSourceTexture:
///   The gpu texture to copy pixels from.</li>
/// <li>sourceTexelOffset:
///   The texel offset (width, height, depth) of where to start copying.
///   If the texture is a 2d_array the third element is the layer/slice.</li>
/// <li>mipLevel:
///   Mip level to copy from.</li>
/// <li>cpuDestinationBuffer:
///   The copy destination cpu buffer.</li>
/// <li>destinationByteOffset:
///   The byte offset in destination buffer where to start copying the data to.</li>
/// <li>destinationBufferByteSize:
///   Size of the destination buffer (in bytes)</li>
/// </ul>
///
struct BgiTextureGpuToCpuOp
{
    BgiTextureGpuToCpuOp()
    : gpuSourceTexture()
    , sourceTexelOffset(GfVec3i(0))
    , mipLevel(0)
    , cpuDestinationBuffer(nullptr)
    , destinationByteOffset(0)
    , destinationBufferByteSize(0)
    {}

    BgiTextureHandle gpuSourceTexture;
    GfVec3i sourceTexelOffset;
    uint32_t mipLevel;
    void* cpuDestinationBuffer;
    size_t destinationByteOffset;
    size_t destinationBufferByteSize;
};

//// \struct HgiTextureCpuToGpuOp
///
/// Describes the properties needed to copy texture data from CPU to GPU.
/// This uploads one mip at a time.
///
/// It is the responsibility of the caller to:
///   - ensure the destination textures is large enough to receive the data.
///   - ensure the source buffer and destination texture are valid at the time
///     the command is executed.
///
/// <ul>
/// <li>cpuSourceBuffer:
///   Pointer to CPU source (ie. texels) to copy the data from.</li>
/// <li>bufferByteSize:
///   Byte size (length) of cpuSourceBuffer.</li>
/// <li>destinationTexelOffset:
///   The texel offset (width, height, depth) of where to upload the data.
///   If the texture is a 2d_array the third element is the layer/slice.</li>
/// <li>mipLevel:
///   Mip level to upload into.</li>
/// <li>gpuDestinationTexture:
///   The GPU texture to upload the data into.</li>
/// </ul>
///
struct BgiTextureCpuToGpuOp
{
    BgiTextureCpuToGpuOp()
    : cpuSourceBuffer(nullptr)
    , bufferByteSize(0)
    , destinationTexelOffset(GfVec3i(0))
    , mipLevel(0)
    , gpuDestinationTexture()
    {}

    void const* cpuSourceBuffer;
    size_t bufferByteSize;
    GfVec3i destinationTexelOffset;
    uint32_t mipLevel;
    BgiTextureHandle gpuDestinationTexture;
};

//// \struct HgiBufferGpuToGpuOp
///
/// Describes the properties needed to copy buffer data from GPU to GPU.
///
/// It is the responsibility of the caller to:
///   - ensure the destination buffer is large enough to receive the data
///     (keep in mind the destinationByteOffset).
///   - ensure the source buffer and destination buffer are valid at the time
///     the command is executed.
///
/// <ul>
/// <li>gpuSourceBuffer:
///   The gpu buffer to copy data from.</li>
/// <li>sourceByteOffset:
///   The byte offset in source buffer to start copying the data from.</li>
/// <li>byteSize:
///   Size of the data (in bytes) to copy</li>
/// <li>gpuDestinationBuffer:
///   The copy destination gpu buffer.</li>
/// <li>destinationByteOffset:
///   The byte offset in destination buffer where to start copying the data to.</li>
/// </ul>
///
struct BgiBufferGpuToGpuOp
{
    BgiBufferGpuToGpuOp()
    : gpuSourceBuffer()
    , sourceByteOffset(0)
    , byteSize(0)
    , gpuDestinationBuffer()
    , destinationByteOffset(0)
    {}

    BgiBufferHandle gpuSourceBuffer;
    size_t sourceByteOffset;
    size_t byteSize;
    BgiBufferHandle gpuDestinationBuffer;
    size_t destinationByteOffset;
};


//// \struct HgiBufferCpuToGpuOp
///
/// Describes the properties needed to copy buffer data from CPU to GPU.
///
/// It is the responsibility of the caller to:
///   - ensure the destination buffer is large enough to receive the data.
///   - ensure the source buffer and destination buffer are valid at the time
///     the command is executed.
///
/// <ul>
/// <li>cpuSourceBuffer:
///   Pointer to CPU source to copy the data from.</li>
/// <li>sourceByteOffset:
///   The byte location in cpuSourceBuffer where copying starts.</li>
/// <li>gpuDestinationBuffer:
///   The GPU buffer to copy the data into.</li>
/// <li>destinationByteOffset:
///   The byte location in gpuDestinationBuffer where copying starts.</li>
/// <li>byteSize:
///   The size in bytes to copy.</li>
/// </ul>
///
struct BgiBufferCpuToGpuOp
{
    BgiBufferCpuToGpuOp()
    : cpuSourceBuffer(nullptr)
    , sourceByteOffset(0)
    , gpuDestinationBuffer()
    , destinationByteOffset(0)
    , byteSize(0)
    {}

    void const* cpuSourceBuffer;
    size_t sourceByteOffset;
    BgiBufferHandle gpuDestinationBuffer;
    size_t destinationByteOffset;
    size_t byteSize;
};

//// \struct HgiBufferGpuToCpuOp
///
/// Describes the properties needed to copy buffer data from GPU to CPU.
///
/// It is the responsibility of the caller to:
///   - ensure the destination buffer is large enough to receive the data
///     (keep in mind the destinationByteOffset).
///   - ensure the source buffer and destination buffer are valid at the time
///     the command is executed.
///
/// <ul>
/// <li>gpuSourceBuffer:
///   The gpu buffer to copy data from.</li>
/// <li>sourceByteOffset:
///   The byte offset in source buffer to start copying the data from.</li>
/// <li>byteSize:
///   Size of the data (in bytes) to copy</li>
/// <li>cpuDestinationBuffer:
///   The copy destination cpu buffer.</li>
/// <li>destinationByteOffset:
///   The byte offset in destination buffer where to start copying the data to.</li>
/// </ul>
///
struct BgiBufferGpuToCpuOp
{
    BgiBufferGpuToCpuOp()
    : gpuSourceBuffer()
    , sourceByteOffset(0)
    , byteSize(0)
    , cpuDestinationBuffer()
    , destinationByteOffset(0)
    {}

    BgiBufferHandle gpuSourceBuffer;
    size_t sourceByteOffset;
    size_t byteSize;
    void* cpuDestinationBuffer;
    size_t destinationByteOffset;
};

//// \struct HgiTextureToBufferOp
///
/// Describes the properties needed to copy GPU texture data into a GPU buffer.
///
/// It is the responsibility of the caller to:
///   - ensure the destination buffer is large enough to receive the data
///     (keep in mind the destinationByteOffset).
///   - ensure the source texture and destination buffer are valid at the time
///     the command is executed.
///
/// <ul>
/// <li>gpuSourceTexture:
///   The gpu texture to copy pixels from.</li>
/// <li>mipLevel:
///   Mip level to copy from.</li>
/// <li>gpuDestinationBuffer:
///   The GPU buffer to copy the data into.</li>
/// <li>destinationByteOffset:
///   The byte offset in destination buffer where to start copying the data to.</li>
/// <li>byteSize:
///   Size of the data (in bytes) to copy</li>
/// </ul>
///
struct BgiTextureToBufferOp
{
    BgiTextureToBufferOp()
    : gpuSourceTexture()
    , sourceTexelOffset(GfVec3i(0))
    , mipLevel(0)
    , gpuDestinationBuffer()
    , destinationByteOffset(0)
    , byteSize(0)
    {}

    BgiTextureHandle gpuSourceTexture;
    GfVec3i sourceTexelOffset;
    uint32_t mipLevel;
    BgiBufferHandle gpuDestinationBuffer;
    size_t destinationByteOffset;
    size_t byteSize;
};

//// \struct HgiBufferToTextureOp
///
/// Describes the properties needed to copy GPU buffer data into a GPU texture.
///
/// It is the responsibility of the caller to:
///   - ensure the destination textures is large enough to receive the data.
///   - ensure the source buffer and destination texture are valid at the time
///     the command is executed.
///
/// <ul>
/// <li>gpuSourceBuffer:
///   The gpu buffer to copy data from.</li>
/// <li>sourceByteOffset:
///   The byte offset in source buffer to start copying the data from.</li>
/// <li>gpuDestinationTexture:
///   The GPU texture to upload the data into.</li>
/// <li>destinationTexelOffset:
///   The texel offset (width, height, depth) of where to upload the data.
///   If the texture is a 2d_array the third element is the layer/slice.</li>
/// <li>mipLevel:
///   Mip level to upload into.</li>
/// <li>byteSize:
///   Size of the data (in bytes) to copy</li>
/// </ul>
///
struct BgiBufferToTextureOp
{
    BgiBufferToTextureOp()
    : gpuSourceBuffer()
    , sourceByteOffset(0)
    , gpuDestinationTexture()
    , destinationTexelOffset(GfVec3i(0))
    , mipLevel(0)
    , byteSize(0)
    {}

    BgiBufferHandle gpuSourceBuffer;
    size_t sourceByteOffset;
    BgiTextureHandle gpuDestinationTexture;
    GfVec3i destinationTexelOffset;
    uint32_t mipLevel;
    size_t byteSize;
};

GUNGNIR_NAMESPACE_CLOSE_SCOPE

#endif