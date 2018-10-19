/*
 * This project is licensed under the MIT license. For more information see the
 * LICENSE file.
 */
#include <memory>

#include "gmock/gmock.h"

#include "maddy/italicparser.h"

// -----------------------------------------------------------------------------

TEST(MADDY_ITALICPARSER, ItReplacesMarkdownWithItalicHTML)
{
  struct testIt {
    std::string text;
    std::string expected;
  };

  std::vector<testIt> tests{
    {
      "some text *bla* text testing *it* out",
      "some text <i>bla</i> text testing <i>it</i> out"
    },
    {
      "some text _bla_ text testing _it_ out",
      "some text <i>bla</i> text testing <i>it</i> out"
    },
  };

  auto italicParser = std::make_shared<maddy::ItalicParser>();

  for(auto& test : tests) {
    italicParser->Parse(test.text);
    ASSERT_EQ(test.expected, test.text);
  }
}
