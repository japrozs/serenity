/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/HTML/HTMLHeadingElement.h>

namespace Web::HTML {

HTMLHeadingElement::HTMLHeadingElement(DOM::Document& document, DOM::QualifiedName qualified_name)
    : HTMLElement(document, move(qualified_name))
{
    set_prototype(&Bindings::cached_web_prototype(realm(), "HTMLHeadingElement"));
}

HTMLHeadingElement::~HTMLHeadingElement() = default;

// https://html.spec.whatwg.org/multipage/rendering.html#tables-2
void HTMLHeadingElement::apply_presentational_hints(CSS::StyleProperties& style) const
{
    HTMLElement::apply_presentational_hints(style);
    for_each_attribute([&](auto& name, auto& value) {
        if (name.equals_ignoring_case("align"sv)) {
            if (value == "left"sv)
                style.set_property(CSS::PropertyID::TextAlign, CSS::IdentifierStyleValue::create(CSS::ValueID::Left));
            else if (value == "right"sv)
                style.set_property(CSS::PropertyID::TextAlign, CSS::IdentifierStyleValue::create(CSS::ValueID::Right));
            else if (value == "center"sv)
                style.set_property(CSS::PropertyID::TextAlign, CSS::IdentifierStyleValue::create(CSS::ValueID::Center));
            else if (value == "justify"sv)
                style.set_property(CSS::PropertyID::TextAlign, CSS::IdentifierStyleValue::create(CSS::ValueID::Justify));
        }
    });
}

}
