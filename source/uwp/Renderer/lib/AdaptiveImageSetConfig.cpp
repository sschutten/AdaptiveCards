#include "pch.h"
#include "AdaptiveImageSetConfig.h"

using namespace Microsoft::WRL;
using namespace ABI::AdaptiveNamespaceRef;

AdaptiveNamespaceStart
    HRESULT AdaptiveImageSetConfig::RuntimeClassInitialize() noexcept try
    {
        ImageSetConfig imageSetConfig;
        return RuntimeClassInitialize(imageSetConfig);
    } CATCH_RETURN;

    HRESULT AdaptiveImageSetConfig::RuntimeClassInitialize(ImageSetConfig sharedImageSetConfig) noexcept
    {
        m_imageSize = static_cast<ABI::AdaptiveNamespaceRef::ImageSize>(sharedImageSetConfig.imageSize);
        m_maxImageHeight = sharedImageSetConfig.maxImageHeight;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImageSetConfig::get_ImageSize(ABI::AdaptiveNamespaceRef::ImageSize* imageSize)
    {
        *imageSize = m_imageSize;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveImageSetConfig::put_ImageSize(ABI::AdaptiveNamespaceRef::ImageSize imageSize)
    {
        m_imageSize = imageSize;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT  AdaptiveImageSetConfig::get_MaxImageHeight(UINT32* maxImageHeight)
    {
        *maxImageHeight = m_maxImageHeight;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT  AdaptiveImageSetConfig::put_MaxImageHeight(UINT32 maxImageHeight)
    {
        m_maxImageHeight = maxImageHeight;
        return S_OK;
    }
AdaptiveNamespaceEnd
