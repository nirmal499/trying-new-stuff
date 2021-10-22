#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Question
{
private:
    int m_questionNumber;
    string m_question;
    int m_correctAnswerIndex;

public:
    Question(int questionNumber, string question, int correctAnswerIndex) : m_questionNumber(questionNumber), m_question(question),
                                                                            m_correctAnswerIndex(correctAnswerIndex) {}
    int getQuestionNumber() const
    {
        return m_questionNumber;
    }

    string getQuestion() const
    {
        return m_question;
    }
    int getAnswerIndex() const
    {
        return m_correctAnswerIndex;
    }
};

/* the custom comparison object that the map will use to sort the keys */
struct QuestionCompare
{
    bool operator()(const Question &lhs,
                    const Question &rhs) const
    {
        return lhs.getQuestionNumber() < rhs.getQuestionNumber();
    }
};

int main()
{
    map<Question, vector<string>, QuestionCompare> quiz;
    Question question1(1, "Which two actors directed themselves in movies and won Oscars for Best Actor?", 2);
    vector<string> question1Answers =
        {
            "Al Pacino and Timothy Hutton",
            "Jack Nicholson and Kevin Spacey",
            "Laurence Olivier and Roberto Benigni",
            "Tom Hanks and Paul Newman"};

    Question question2(2, "\"After all, tomorrow is another day!\" was the last line in which Oscar-winning Best Picture?", 0);
    vector<string> question2Answers =
        {
            "Gone With the Wind",
            "Great Expectations",
            "Harold and Maude",
            "The Matrix"};

    quiz.insert(make_pair(question1, question1Answers));
    quiz.insert(make_pair(question2, question2Answers));
    cout << "Welcome to the movie quiz" << endl;
    cout << "Type your answer between 1-4 and press enter:" << endl;
    map<Question, vector<string>>::iterator quizIterator = quiz.begin();

    vector<bool> correctAnswers;

    while (quizIterator != quiz.end())
    {
        /* Notice we are using arrow operator on the iterator */
        cout << quizIterator->first.getQuestion() << endl;
        int answerIndex = 1;

        for (auto answer : quizIterator->second)
        {
            cout << answerIndex << " : " << answer << endl;
            answerIndex++;
        }

        int answerOfUser;
        cout << "Enter your answer: ";
        cin >> answerOfUser;
        int correctAnswerIndex = quizIterator->first.getAnswerIndex();
        /* Since vector first element starts from index 0,
            thats why we are subtracting 1 from the answerIndex provided by the user
         */
        bool wasCorrect = answerOfUser - 1 == correctAnswerIndex;
        cout << (wasCorrect ? "CORRECT!" : "INCORRECT!") << " Correct answer is: " << quizIterator->second[correctAnswerIndex] << endl;

        if (wasCorrect)
        {
            /* Only if we got the correct then only it will get pushed back */
            correctAnswers.push_back(answerOfUser);
        }
        quizIterator++;
    }

    cout << "Your score was " << correctAnswers.size() << " out of " << quiz.size() << endl;
    cout << "Done\n";
}