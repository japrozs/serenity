/*
 * Copyright (c) 2020, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/DOM/ARIARoleNames.h>
#include <LibWeb/HTML/HTMLElement.h>

namespace Web::HTML {

class HTMLOListElement final : public HTMLElement {
    WEB_PLATFORM_OBJECT(HTMLOListElement, HTMLElement);

public:
    virtual ~HTMLOListElement() override;

    // https://www.w3.org/TR/html-aria/#el-ol
    virtual FlyString default_role() const override { return DOM::ARIARoleNames::list; }

private:
    HTMLOListElement(DOM::Document&, DOM::QualifiedName);
};

}
