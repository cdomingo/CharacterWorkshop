
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "O3DConWorkshopSystemComponent.h"

namespace O3DConWorkshop
{
    void O3DConWorkshopSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<O3DConWorkshopSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<O3DConWorkshopSystemComponent>("O3DConWorkshop", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void O3DConWorkshopSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("O3DConWorkshopService"));
    }

    void O3DConWorkshopSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("O3DConWorkshopService"));
    }

    void O3DConWorkshopSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void O3DConWorkshopSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    O3DConWorkshopSystemComponent::O3DConWorkshopSystemComponent()
    {
        if (O3DConWorkshopInterface::Get() == nullptr)
        {
            O3DConWorkshopInterface::Register(this);
        }
    }

    O3DConWorkshopSystemComponent::~O3DConWorkshopSystemComponent()
    {
        if (O3DConWorkshopInterface::Get() == this)
        {
            O3DConWorkshopInterface::Unregister(this);
        }
    }

    void O3DConWorkshopSystemComponent::Init()
    {
    }

    void O3DConWorkshopSystemComponent::Activate()
    {
        O3DConWorkshopRequestBus::Handler::BusConnect();
    }

    void O3DConWorkshopSystemComponent::Deactivate()
    {
        O3DConWorkshopRequestBus::Handler::BusDisconnect();
    }
}
