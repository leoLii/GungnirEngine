#ifndef GUNGNIR_DRIVER_VULKAN_PIPELINE_CACHE_H
#define GUNGNIR_DRIVER_VULKAN_PIPELINE_CACHE_H

#include "core/base.h"

#include "driver/bgiVulkan/api.h"
#include "driver/bgiVulkan/vulkan.h"

GUNGNIR_NAMESPACE_OPEN_SCOPE

class BgiVulkanDevice;

/// \class HgiVulkanPipelineCache
///
/// Wrapper for Vulkan pipeline cache.
///
class BgiVulkanPipelineCache final
{
public:
    BGIVULKAN_API
    BgiVulkanPipelineCache(BgiVulkanDevice* device);

    BGIVULKAN_API
    ~BgiVulkanPipelineCache();

    /// Returns the vulkan pipeline cache.
    BGIVULKAN_API
    VkPipelineCache GetVulkanPipelineCache() const;

private:
    BgiVulkanPipelineCache() = delete;
    BgiVulkanPipelineCache & operator=(const BgiVulkanPipelineCache&) = delete;
    BgiVulkanPipelineCache(const BgiVulkanPipelineCache&) = delete;

    BgiVulkanDevice* _device;
    VkPipelineCache _vkPipelineCache;
};

GUNGNIR_NAMESPACE_CLOSE_SCOPE

#endif // GUNGNIR_DRIVER_VULKAN_PIPELINE_CACHE_H