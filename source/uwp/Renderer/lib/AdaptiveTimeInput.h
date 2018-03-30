#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"
#include "Enums.h"
#include "TimeInput.h"
#include "AdaptiveInputElement.h"

AdaptiveNamespaceStart
    class DECLSPEC_UUID("5d05c3fe-f808-4181-9f44-3a802b556a43")  AdaptiveTimeInput :
        public Microsoft::WRL::RuntimeClass<
            Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
            ABI::AdaptiveNamespaceRef::IAdaptiveTimeInput,
            ABI::AdaptiveNamespaceRef::IAdaptiveInputElement,
            ABI::AdaptiveNamespaceRef::IAdaptiveCardElement,
            Microsoft::WRL::CloakedIid<ITypePeek>,
            Microsoft::WRL::CloakedIid<AdaptiveNamespaceRef::AdaptiveInputElementBase>>
    {
        AdaptiveRuntime(AdaptiveTimeInput)

    public:
        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(_In_ const std::shared_ptr<AdaptiveCards::TimeInput>& sharedTimeInput);

        // IAdaptiveTimeInput
        IFACEMETHODIMP get_Max(_Out_ HSTRING* max);
        IFACEMETHODIMP put_Max(_In_ HSTRING max);

        IFACEMETHODIMP get_Min(_Out_ HSTRING* min);
        IFACEMETHODIMP put_Min(_In_ HSTRING min);

        IFACEMETHODIMP get_Placeholder(_Out_ HSTRING* placeholder);
        IFACEMETHODIMP put_Placeholder(_In_ HSTRING placeholder);

        IFACEMETHODIMP get_Value(_Out_ HSTRING* value);
        IFACEMETHODIMP put_Value(_In_ HSTRING value);

        // IAdaptiveInputElement
        IFACEMETHODIMP get_IsRequired(_Out_ boolean* isRequired) { return AdaptiveInputElementBase::get_IsRequired(isRequired); }
        IFACEMETHODIMP put_IsRequired(_In_ boolean isRequired) { return AdaptiveInputElementBase::put_IsRequired(isRequired); }

        // IAdaptiveCardElement
        IFACEMETHODIMP get_ElementType(_Out_ ABI::AdaptiveNamespaceRef::ElementType* elementType);

        IFACEMETHODIMP get_Spacing(_Out_ ABI::AdaptiveNamespaceRef::Spacing* spacing) { return AdaptiveCardElementBase::get_Spacing(spacing); }
        IFACEMETHODIMP put_Spacing(_In_ ABI::AdaptiveNamespaceRef::Spacing spacing) { return AdaptiveCardElementBase::put_Spacing(spacing); }

        IFACEMETHODIMP get_Separator(_Out_ boolean* separator) { return AdaptiveCardElementBase::get_Separator(separator); }
        IFACEMETHODIMP put_Separator(_In_ boolean separator) { return AdaptiveCardElementBase::put_Separator(separator); }

        IFACEMETHODIMP get_Id(_Out_ HSTRING* id) { return AdaptiveCardElementBase::get_Id(id); }
        IFACEMETHODIMP put_Id(_In_ HSTRING id) { return AdaptiveCardElementBase::put_Id(id); }

        IFACEMETHODIMP get_ElementTypeString(_Out_ HSTRING* value) { return AdaptiveCardElementBase::get_ElementTypeString(value); }

        IFACEMETHODIMP get_AdditionalProperties(_Out_ ABI::Windows::Data::Json::IJsonObject** result) { return AdaptiveCardElementBase::get_AdditionalProperties(result); }
        IFACEMETHODIMP put_AdditionalProperties(_In_ ABI::Windows::Data::Json::IJsonObject* value) { return AdaptiveCardElementBase::put_AdditionalProperties(value); }

        IFACEMETHODIMP ToJson(_Out_ ABI::Windows::Data::Json::IJsonObject** result) { return AdaptiveCardElementBase::ToJson(result); }

        virtual HRESULT GetSharedModel(std::shared_ptr<AdaptiveCards::BaseCardElement>& sharedModel) override;

        // ITypePeek method
        void *PeekAt(REFIID riid) override
        {
            return PeekHelper(riid, this);
        }

    private:
        Microsoft::WRL::Wrappers::HString m_max;
        Microsoft::WRL::Wrappers::HString m_min;
        Microsoft::WRL::Wrappers::HString m_placeholder;
        Microsoft::WRL::Wrappers::HString m_value;
    };

    ActivatableClass(AdaptiveTimeInput);
AdaptiveNamespaceEnd