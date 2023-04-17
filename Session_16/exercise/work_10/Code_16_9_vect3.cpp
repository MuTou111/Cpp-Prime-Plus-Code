#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;
struct Review
{
    std::string title;
    double price;
    int rating;
};

bool operator<(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool worseThan_r(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool worseThan_p(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool betterThan_r(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool betterThan_p(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool FillReview(shared_ptr<Review> &rr);
void ShowReview(const shared_ptr<Review> &rr);

int main()
{
    vector<shared_ptr<Review>> books;
    shared_ptr<Review> temp;
    while (FillReview(temp))
        books.push_back(temp);

    if (books.size() > 0)
    {
        cout << "Which Order?\n"
             << "a): Origin\tb): Alphabet\tc): Rating_Up\n"
             << "d): Rating_Down\te): Price_Up\tf): Price_Down\tq): quit\n";
        char flag;
        while (cin >> flag && flag != 'q')
        {
            cout << "Rating\tBook\t\tPrice\n";
            switch (flag)
            {
            case 'a':
                for_each(books.begin(), books.end(), ShowReview);
                break;

            case 'b':
                sort(books.begin(), books.end());
                for_each(books.begin(), books.end(), ShowReview);
                break;

            case 'c':
                sort(books.begin(), books.end(), worseThan_r);
                for_each(books.begin(), books.end(), ShowReview);
                break;

            case 'd':
                sort(books.begin(), books.end(), betterThan_r);
                for_each(books.begin(), books.end(), ShowReview);
                break;

            case 'e':
                sort(books.begin(), books.end(), worseThan_p);
                for_each(books.begin(), books.end(), ShowReview);
                break;

            case 'f':
                sort(books.begin(), books.end(), betterThan_p);
                for_each(books.begin(), books.end(), ShowReview);
                break;
            }
            cout << "Which Order?\n"
                 << "a): Origin\tb): Alphabet\tc): Rating_Up\n"
                 << "d): Rating_Down\te): Price_Up\tf): Price_Down\tq): quit\n";
        }
    }
    else
        cout << "No entires. ";
    cout << "Bye.\n";
    return 0;
}

bool operator<(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->rating == r2->rating && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan_r(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan_p(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
}

bool betterThan_r(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    if (r1->rating > r2->rating)
        return true;
    else
        return false;
}

bool betterThan_p(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    if (r1->price > r2->price)
        return true;
    else
        return false;
}

bool FillReview(shared_ptr<Review> &rr)
{
    rr = shared_ptr<Review>(new Review());
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr->title);
    if (rr->title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr->rating;
    while (std::cin.get() != '\n')
        continue;
    std::cout << "Enter book price: ";
    std::cin >> rr->price;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const shared_ptr<Review> &rr)
{
    std::cout << rr->rating << "\t" << rr->title << "\t\t" << rr->price << std::endl;
}