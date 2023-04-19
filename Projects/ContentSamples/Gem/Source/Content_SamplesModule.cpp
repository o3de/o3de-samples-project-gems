
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "Content_SamplesSystemComponent.h"

namespace Content_Samples
{
    class Content_SamplesModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(Content_SamplesModule, "{1B0A2A1E-F3DD-4CC9-B360-11B5CFEB615B}", AZ::Module);
        AZ_CLASS_ALLOCATOR(Content_SamplesModule, AZ::SystemAllocator, 0);

        Content_SamplesModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                Content_SamplesSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<Content_SamplesSystemComponent>(),
            };
        }
    };
}// namespace Content_Samples

AZ_DECLARE_MODULE_CLASS(Gem_Content_Samples, Content_Samples::Content_SamplesModule)
