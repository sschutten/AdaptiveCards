#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"
#include "ChoiceSetInput.h"
#include "Enums.h"
#include <windows.foundation.h>
#include "AdaptiveInputElement.h"

AdaptiveNamespaceStart
    class DECLSPEC_UUID("fa103f57-5d54-48ba-80a5-d8939b85e82d") AdaptiveChoiceSetInput :
        public Microsoft::WRL::RuntimeClass<
            Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
            ABI::AdaptiveNamespaceRef::IAdaptiveChoiceSetInput,
            ABI::AdaptiveNamespaceRef::IAdaptiveInputElement,
            ABI::AdaptiveNamespaceRef::IAdaptiveCardElement,
            Microsoft::WRL::CloakedIid<ITypePeek>,
            Microsoft::WRL::CloakedIid<AdaptiveNamespaceRef::AdaptiveInputElementBase>>
    {
        AdaptiveRuntime(AdaptiveChoiceSetInput)

    public:
        AdaptiveChoiceSetInput();

        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(_In_ const std::shared_ptr<AdaptiveCards::ChoiceSetInput>& sharedChoiceSetInput);

        // IAdaptiveChoiceSetInput

        IFACEMETHODIMP get_Value(_Out_ HSTRING* value);
        IFACEMETHODIMP put_Value(_In_ HSTRING value);

        IFACEMETHODIMP get_IsMultiSelect(_Out_ boolean* isMultiSelect);
        IFACEMETHODIMP put_IsMultiSelect(_In_ boolean isMultiSelect);

        IFACEMETHODIMP get_ChoiceSetStyle(_Out_ ABI::AdaptiveNamespaceRef::ChoiceSetStyle* choiceSetStyle);
        IFACEMETHODIMP put_ChoiceSetStyle(_In_ ABI::AdaptiveNamespaceRef::ChoiceSetStyle choiceSetStyle);

        IFACEMETHODIMP get_Choices(_COM_Outptr_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespaceRef::IAdaptiveChoiceInput*>** columns);

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
        Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespaceRef::IAdaptiveChoiceInput*>> m_choices;
        boolean m_isMultiSelect;
        ABI::AdaptiveNamespaceRef::ChoiceSetStyle m_choiceSetStyle;
        Microsoft::WRL::Wrappers::HString m_value;
    };

    ActivatableClass(AdaptiveChoiceSetInput);
AdaptiveNamespaceEnd
