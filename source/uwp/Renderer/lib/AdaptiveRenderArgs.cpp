#include "pch.h"

#include "AdaptiveRenderArgs.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveNamespaceRef;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::UI::Xaml;

AdaptiveNamespaceStart
    HRESULT AdaptiveRenderArgs::RuntimeClassInitialize() noexcept
    {
        return S_OK;
    }

    HRESULT AdaptiveRenderArgs::RuntimeClassInitialize(
        ABI::AdaptiveNamespaceRef::ContainerStyle containerStyle,
        IInspectable* parentElement) noexcept try
    {
        m_containerStyle = containerStyle;
        m_parentElement = parentElement;
        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveRenderArgs::get_ContainerStyle(ABI::AdaptiveNamespaceRef::ContainerStyle *value)
    {
        *value = m_containerStyle;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderArgs::put_ContainerStyle(ABI::AdaptiveNamespaceRef::ContainerStyle value)
    {
        m_containerStyle = value;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderArgs::get_ParentElement(_COM_Outptr_ IInspectable** value)
    {
        return m_parentElement.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderArgs::put_ParentElement(_In_ IInspectable* value)
    {
        m_parentElement = value;
        return S_OK;
    }
AdaptiveNamespaceEnd
