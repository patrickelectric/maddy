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
 * StrongParser
 *
 * Has to be used before the `EmphasizedParser`.
 *
 * @class
 */
class StrongParser : public LineParser
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
    res.push_back(std::regex{"(?!.*`.*|.*<code>.*)\\*\\*(?!.*`.*|.*<\\/code>.*)([^\\*\\*]*)\\*\\*(?!.*`.*|.*<\\/code>.*)"});
    res.push_back(std::regex{"(?!.*`.*|.*<code>.*)\\_\\_(?!.*`.*|.*<\\/code>.*)([^\\_\\_]*)\\_\\_(?!.*`.*|.*<\\/code>.*)"});
    static std::string replacement = "<strong>$1</strong>";
    for(const auto& re : res) {
      line = std::regex_replace(line, re, replacement);
    }
  }
}; // class StrongParser

// -----------------------------------------------------------------------------

} // namespace maddy
