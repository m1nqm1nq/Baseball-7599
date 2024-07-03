#include <stdexcept>

using namespace std;

#include "pch.h"
#include "../Baseball/Baseball.cpp"

class BaseballTestFixture : public testing::Test
{
public:
    Baseball game;
    void assertIllegalArgument(string guessNumber)
    {
        try
        {
            game.guess(guessNumber);
            FAIL();
        }
        catch (exception e)
        {
            // PASS
        }
    }
};

TEST_F(BaseballTestFixture, ThrowExceptionWhenInvalidCase)
{
    assertIllegalArgument("12");
    assertIllegalArgument("12s");
}
