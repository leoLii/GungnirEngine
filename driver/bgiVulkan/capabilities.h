#pragma once

#include "common/base.h"

#include "driver/bgiBase/capabilities.h"
#include "driver/bgiVulkan/api.h"
#include "driver/bgiVulkan/vulkanBridge.h"

GUNGNIR_NAMESPACE_OPEN_SCOPE

namespace driver {

class BgiVulkanDevice;

/// \class HgiVulkanCapabilities
///
/// Reports the capabilities of the Vulkan device.
///
class BgiVulkanCapabilities final :public BgiCapabilities
{
public:
    BGIVULKAN_API
    BgiVulkanCapabilities(BgiVulkanDevice* device);

    BGIVULKAN_API
    ~BgiVulkanCapabilities();

    BGIVULKAN_API
    int GetAPIVersion() const override;
    
    BGIVULKAN_API
    int GetShaderVersion() const override;

    bool supportsTimeStamps;
    VkPhysicalDeviceProperties vkDeviceProperties;
    VkPhysicalDeviceProperties2 vkDeviceProperties2;
    VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT
        vkVertexAttributeDivisorProperties;
    VkPhysicalDeviceFeatures vkDeviceFeatures;
    VkPhysicalDeviceFeatures2 vkDeviceFeatures2;
    VkPhysicalDeviceVulkanFeatures vkVulkanFeatures;
    VkPhysicalDeviceDescriptorIndexingFeaturesEXT vkIndexingFeatures;
    VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT
        vkVertexAttributeDivisorFeatures;
    VkPhysicalDeviceMemoryProperties vkMemoryProperties;
};

}

GUNGNIR_NAMESPACE_CLOSE_SCOPE
