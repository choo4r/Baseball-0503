#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) : question(question) {}

	bool isDuplicateNumber(const string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];

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

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3, 0 };
		}

		GuessResult result = getCount(guessNumber);
		return result;
	}

	GuessResult getCount(const string& guessNumber) {
		GuessResult count = { false, 0, 0 };
		for (int i = 0; i < guessNumber.length(); ++i) {
			for (int j = 0; j < question.length(); ++j) {
				if (guessNumber[i] != question[j]) continue;
				if (i == j) count.strikes++;
				else count.balls++;
			}
		}
		return count;
	}

private:
	string question;
};