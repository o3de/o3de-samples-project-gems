
#pragma once

#include <AzCore/Component/Component.h>

#include <Content_Samples/Content_SamplesBus.h>

namespace Content_Samples
{
    class Content_SamplesSystemComponent
        : public AZ::Component
        , protected Content_SamplesRequestBus::Handler
    {
    public:
        AZ_COMPONENT(Content_SamplesSystemComponent, "{4F9120D6-BA56-4A67-B186-E20C6D38D96B}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        Content_SamplesSystemComponent();
        ~Content_SamplesSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // Content_SamplesRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
