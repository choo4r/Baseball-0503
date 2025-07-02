#include <stdexcept>

using namespace std;
class Baseball {
public:
	void guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
	}
	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicateNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	int isDuplicateNumber(const string& guessNumber)
	{
		if (guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2]) {
			return 1;
		}

		return 0;
	}
};