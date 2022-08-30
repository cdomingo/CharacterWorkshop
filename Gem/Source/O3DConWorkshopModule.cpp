
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "O3DConWorkshopSystemComponent.h"

namespace O3DConWorkshop
{
    class O3DConWorkshopModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(O3DConWorkshopModule, "{69B27530-6346-45BD-B996-37752F5B8E74}", AZ::Module);
        AZ_CLASS_ALLOCATOR(O3DConWorkshopModule, AZ::SystemAllocator, 0);

        O3DConWorkshopModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                O3DConWorkshopSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<O3DConWorkshopSystemComponent>(),
            };
        }
    };
}// namespace O3DConWorkshop

AZ_DECLARE_MODULE_CLASS(Gem_O3DConWorkshop, O3DConWorkshop::O3DConWorkshopModule)
