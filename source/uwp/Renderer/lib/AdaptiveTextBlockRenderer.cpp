#include "pch.h"

#include "AdaptiveTextBlock.h"
#include "AdaptiveTextBlockRenderer.h"
#include "AdaptiveRenderContext.h"
#include "Util.h"
#include "XamlBuilder.h"
#include "AdaptiveElementParserRegistration.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveNamespaceRef;
using namespace ABI::Windows::Foundation;

AdaptiveNamespaceStart
    HRESULT AdaptiveTextBlockRenderer::RuntimeClassInitialize() noexcept try
    {
        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlockRenderer::Render(
        IAdaptiveCardElement* cardElement,
        IAdaptiveRenderContext* renderContext,
        IAdaptiveRenderArgs* renderArgs,
        ABI::Windows::UI::Xaml::IUIElement** result)
    {
        XamlBuilder::BuildTextBlock(cardElement, renderContext, renderArgs, result);
        return S_OK;
    }

    HRESULT AdaptiveTextBlockRenderer::FromJson(
        ABI::Windows::Data::Json::IJsonObject* jsonObject,
        ABI::AdaptiveNamespaceRef::IAdaptiveElementParserRegistration* elementParserRegistration,
        ABI::AdaptiveNamespaceRef::IAdaptiveActionParserRegistration* actionParserRegistration,
        ABI::AdaptiveNamespaceRef::IAdaptiveCardElement** element)
    {
        return AdaptiveNamespaceRef::FromJson<AdaptiveNamespaceRef::AdaptiveTextBlock, AdaptiveCards::TextBlock, AdaptiveCards::TextBlockParser>(jsonObject, elementParserRegistration, actionParserRegistration, element);
    }
AdaptiveNamespaceEnd
