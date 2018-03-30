#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"

AdaptiveNamespaceStart
    class AdaptiveWarning:
        public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
        Microsoft::WRL::Implements<ABI::AdaptiveNamespaceRef::IAdaptiveWarning>,
        Microsoft::WRL::FtmBase>
    {
        AdaptiveRuntime(AdaptiveWarning)

    public:
        HRESULT RuntimeClassInitialize();

        HRESULT RuntimeClassInitialize(
            ABI::AdaptiveNamespaceRef::WarningStatusCode statusCode,
            HSTRING message);

        // IAdaptiveWarning
        HRESULT put_StatusCode(_In_ ABI::AdaptiveNamespaceRef::WarningStatusCode value);
        IFACEMETHODIMP get_StatusCode(_Out_ ABI::AdaptiveNamespaceRef::WarningStatusCode* value);

        HRESULT put_Message(_In_ HSTRING value);
        IFACEMETHODIMP get_Message(_Out_ HSTRING* value);

    private:
        Microsoft::WRL::Wrappers::HString m_message;
        ABI::AdaptiveNamespaceRef::WarningStatusCode m_statusCode;
    };

    ActivatableClass(AdaptiveWarning);
AdaptiveNamespaceEnd
