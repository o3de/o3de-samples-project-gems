
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "BistroPBRSystemComponent.h"

namespace BistroPBR
{
    class BistroPBRModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(BistroPBRModule, "{87D74108-1EC8-4D9C-9BD0-BA72DA5A70CF}", AZ::Module);
        AZ_CLASS_ALLOCATOR(BistroPBRModule, AZ::SystemAllocator, 0);

        BistroPBRModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                BistroPBRSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<BistroPBRSystemComponent>(),
            };
        }
    };
}// namespace BistroPBR

AZ_DECLARE_MODULE_CLASS(Gem_BistroPBR, BistroPBR::BistroPBRModule)
