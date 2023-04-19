
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Content_Samples
{
    class Content_SamplesRequests
    {
    public:
        AZ_RTTI(Content_SamplesRequests, "{B7CA01BA-F722-43FA-94E2-902DA3260353}");
        virtual ~Content_SamplesRequests() = default;
        // Put your public methods here
    };

    class Content_SamplesBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using Content_SamplesRequestBus = AZ::EBus<Content_SamplesRequests, Content_SamplesBusTraits>;
    using Content_SamplesInterface = AZ::Interface<Content_SamplesRequests>;

} // namespace Content_Samples
