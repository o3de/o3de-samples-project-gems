
#pragma once

#include <AzCore/Component/Component.h>

#include <BistroPBR/BistroPBRBus.h>

namespace BistroPBR
{
    class BistroPBRSystemComponent
        : public AZ::Component
        , protected BistroPBRRequestBus::Handler
    {
    public:
        AZ_COMPONENT(BistroPBRSystemComponent, "{EAB34DE3-DA9D-476B-AA07-10DE6BE01595}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        BistroPBRSystemComponent();
        ~BistroPBRSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // BistroPBRRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
