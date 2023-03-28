
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace BistroPBR
{
    class BistroPBRRequests
    {
    public:
        AZ_RTTI(BistroPBRRequests, "{375BEC53-C14E-4970-AD22-EA8EE4523BFD}");
        virtual ~BistroPBRRequests() = default;
        // Put your public methods here
    };

    class BistroPBRBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using BistroPBRRequestBus = AZ::EBus<BistroPBRRequests, BistroPBRBusTraits>;
    using BistroPBRInterface = AZ::Interface<BistroPBRRequests>;

} // namespace BistroPBR
