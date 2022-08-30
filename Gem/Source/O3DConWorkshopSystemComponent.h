
#pragma once

#include <AzCore/Component/Component.h>

#include <O3DConWorkshop/O3DConWorkshopBus.h>

namespace O3DConWorkshop
{
    class O3DConWorkshopSystemComponent
        : public AZ::Component
        , protected O3DConWorkshopRequestBus::Handler
    {
    public:
        AZ_COMPONENT(O3DConWorkshopSystemComponent, "{A44D9C90-0F2D-4CD8-861D-EC975EDC2CE3}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        O3DConWorkshopSystemComponent();
        ~O3DConWorkshopSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // O3DConWorkshopRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
