const int Len = 40;
class golf
{
private:
    char fullname[Len];
    int handicap;

public:
    //  non-interactive version:
    //  function sets golf structure to provideed name, handicap
    //  using values passed as arguments to the function
    golf(const char *name = "A", int hc = 1);

    //  interactive version:
    //  function solicits name and handicap from user
    //  and sets the members of g to the values entered
    //  returns 1 if name is entered, 0 if name is empty string
    void setgolf();

    //  function resets handicap to new value
    void set_handicap(int hc);

    //  function display contents of golf structure
    void showgolf() const;
};