/*
 * This project is licensed under the MIT license. For more information see the
 * LICENSE file.
 */
#pragma once

// -----------------------------------------------------------------------------

#include <string>
#include <regex>

#include "maddy/lineparser.h"

// -----------------------------------------------------------------------------

namespace maddy {

// -----------------------------------------------------------------------------

/**
 * ItalicParser
 *
 * Has to be used before the `EmphasizedParser`.
 *
 * @class
 */
class ItalicParser : public LineParser
{
public:
  /**
   * Parse
   *
   * From Markdown: `text **text**`
   *
   * To HTML: `text <strong>text</strong>`
   *
   * @method
   * @param {std::string&} line The line to interpret
   * @return {void}
   */
  void
  Parse(std::string& line) override
  {
    static std::vector<std::regex> res;
    res.push_back(std::regex{"(?!.*`.*|.*<code>.*)\\*(?!.*`.*|.*<\\/code>.*)([^\\*]*)\\*(?!.*`.*|.*<\\/code>.*)"});
    res.push_back(std::regex{"(?!.*`.*|.*<code>.*)\\_(?!.*`.*|.*<\\/code>.*)([^\\_]*)\\_(?!.*`.*|.*<\\/code>.*)"});
    static std::string replacement = "<i>$1</i>";
    for(const auto& re : res) {
      line = std::regex_replace(line, re, replacement);
    }
  }
}; // class ItalicParser

// -----------------------------------------------------------------------------

} // namespace maddy
