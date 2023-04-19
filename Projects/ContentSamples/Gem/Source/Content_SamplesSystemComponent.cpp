
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "Content_SamplesSystemComponent.h"

namespace Content_Samples
{
    void Content_SamplesSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<Content_SamplesSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<Content_SamplesSystemComponent>("Content_Samples", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void Content_SamplesSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("Content_SamplesService"));
    }

    void Content_SamplesSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("Content_SamplesService"));
    }

    void Content_SamplesSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void Content_SamplesSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    Content_SamplesSystemComponent::Content_SamplesSystemComponent()
    {
        if (Content_SamplesInterface::Get() == nullptr)
        {
            Content_SamplesInterface::Register(this);
        }
    }

    Content_SamplesSystemComponent::~Content_SamplesSystemComponent()
    {
        if (Content_SamplesInterface::Get() == this)
        {
            Content_SamplesInterface::Unregister(this);
        }
    }

    void Content_SamplesSystemComponent::Init()
    {
    }

    void Content_SamplesSystemComponent::Activate()
    {
        Content_SamplesRequestBus::Handler::BusConnect();
    }

    void Content_SamplesSystemComponent::Deactivate()
    {
        Content_SamplesRequestBus::Handler::BusDisconnect();
    }
}
