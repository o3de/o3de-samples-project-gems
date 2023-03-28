
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "BistroPBRSystemComponent.h"

namespace BistroPBR
{
    void BistroPBRSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<BistroPBRSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<BistroPBRSystemComponent>("BistroPBR", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void BistroPBRSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("BistroPBRService"));
    }

    void BistroPBRSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("BistroPBRService"));
    }

    void BistroPBRSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void BistroPBRSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    BistroPBRSystemComponent::BistroPBRSystemComponent()
    {
        if (BistroPBRInterface::Get() == nullptr)
        {
            BistroPBRInterface::Register(this);
        }
    }

    BistroPBRSystemComponent::~BistroPBRSystemComponent()
    {
        if (BistroPBRInterface::Get() == this)
        {
            BistroPBRInterface::Unregister(this);
        }
    }

    void BistroPBRSystemComponent::Init()
    {
    }

    void BistroPBRSystemComponent::Activate()
    {
        BistroPBRRequestBus::Handler::BusConnect();
    }

    void BistroPBRSystemComponent::Deactivate()
    {
        BistroPBRRequestBus::Handler::BusDisconnect();
    }
}
