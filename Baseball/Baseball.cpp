#include <stdexcept>

using namespace std;

struct GuessResult
{
    bool solved;
    int strikes;
    int balls;
};

class Baseball
{
private:
    string question;
public:
    explicit Baseball(const string& question)
        : question{ question } {}
    GuessResult guess (const string& guessNumber)
    {
        assertIllegalArgument(guessNumber);
        return { true, 3, 0 };
    }

    void assertIllegalArgument(const std::string& guessNumber)
    {
        if (guessNumber.length() != 3)
        {
            throw length_error("Must be three letters.");
        }

        for (char c : guessNumber)
        {
            if (c >= '0' && c <= '9') continue;
            throw invalid_argument("Must be number.");
        }

        if (isDuplicatedNumber(guessNumber))
        {
            throw invalid_argument("Must not have the same number.");
        }
    }
    bool isDuplicatedNumber(const std::string& guessNumber)
    {
        return (guessNumber[0] == guessNumber[1]) ||
            (guessNumber[0] == guessNumber[2]) ||
            (guessNumber[1] == guessNumber[2]);
    }
};