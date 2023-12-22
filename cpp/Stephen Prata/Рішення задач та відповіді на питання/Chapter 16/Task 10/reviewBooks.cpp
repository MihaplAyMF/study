#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Review
{
    string title;
    double price;
    int rating;
};

bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool worseThanTitle(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool worseThanRaiting(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool worseThanPrice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool FillReview(Review& rr);
void ShowReview(const shared_ptr<Review>& rr);

int main()
{
    vector<shared_ptr<Review>> books;
    Review temp;
    while(FillReview(temp))
    {
        shared_ptr<Review> t (make_shared<Review>());
        t->title = temp.title;
        t->rating = temp.rating;
        t->price = temp.price;
        books.push_back(t);
    }
    if(books.size() > 0)
    {
        cout << "Thank you. You entered the following "
            << books.size() << " ratings:\n"
            << "Rating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), worseThanRaiting);
        cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), worseThanPrice);
        cout << "Sorted by price:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        random_shuffle(books.begin(), books.end());
        cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    return 0;
}

bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
    if(r1->title < r2->title)
        return true;
    else if(r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThanTitle(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
    if(r1->title < r2->title)
        return true;
    else
        return false;
}

bool worseThanRaiting(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
    if(r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThanPrice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
    if(r1->price < r2->price)
        return true;
    else
        return false;
}

bool FillReview(Review& rr)
{
    cout << "Enter book title (quit to quit): ";
    getline(cin, rr.title);
    if(rr.title == "quit")
        return false;
    
    cout << "Enter book rating: ";
    cin >> rr.rating;
    if(!cin)
        return false;

    cout << "Enter book price: ";
    cin >> rr.price;
    if(!cin)
        return false;
    
    while(cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const shared_ptr<Review>& rr)
{
    cout << rr->rating << "\t" << rr->title << "\t" << rr->price << endl;
}
