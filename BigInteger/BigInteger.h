



#include <string>
#include <vector>
#include <cstdint>
#include <string>

struct BigInteger {
public:
    BigInteger();

    BigInteger(BigInteger const &other) = default;

    //BigInteger(BigInteger && other) = default;
    BigInteger(BigInteger &&other);

    BigInteger(int);

    BigInteger(std::string const &str);

    friend std::string to_string(BigInteger const &a);

    BigInteger &operator+(BigInteger const &right);

    BigInteger &operator-(BigInteger const &right);

    BigInteger &operator*(BigInteger const &right);
    BigInteger &operator+=(BigInteger const &right);

    BigInteger &operator-=(BigInteger const &right);

    BigInteger &operator*=(BigInteger const &right);

    BigInteger &operator=(BigInteger const &right) = default;

    friend bool operator==(const BigInteger& left, const BigInteger& right);


private:
    std::vector<unsigned> digits;
    bool sign;
};

std::string to_string(BigInteger const &a);

std::ostream &operator<<(std::ostream &out, BigInteger const &a);

std::istream &operator>>(std::istream &iut, BigInteger &a);

