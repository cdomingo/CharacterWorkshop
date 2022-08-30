
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace O3DConWorkshop
{
    class O3DConWorkshopRequests
    {
    public:
        AZ_RTTI(O3DConWorkshopRequests, "{A9B06570-1C03-4E43-B9AA-B45A27297E5A}");
        virtual ~O3DConWorkshopRequests() = default;
        // Put your public methods here
    };

    class O3DConWorkshopBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using O3DConWorkshopRequestBus = AZ::EBus<O3DConWorkshopRequests, O3DConWorkshopBusTraits>;
    using O3DConWorkshopInterface = AZ::Interface<O3DConWorkshopRequests>;

} // namespace O3DConWorkshop
