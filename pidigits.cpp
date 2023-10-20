#include <cctype>
#include <iomanip>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long tot = 0;
    long digits[10] = {};
    int  ch;
    while ((ch = std::cin.get()) != EOF)
    {
	// Skip blanks, dots and other non-digits.
	if (!std::isdigit(ch))
	    continue;
	tot++;
	int num = ch - '0';
	digits[num]++;
    }

    std::cout << "Total digits:" << tot << "\n";

    auto tenth = tot / 10;
    for (int i = 0; i < sizeof(digits) / sizeof(digits[0]); i++)
    {
	auto d = digits[i];
	auto prop = static_cast<double>(d) / tot;

	std::cout << std::setw(3) << i << std::setw(16) << d << " "
	          << "(" << d - tenth << ")" << std::setw(14) << std::fixed << std::setprecision(8)
	          << prop * 100 << "% " << std::setw(12) << (1 - prop / 0.1) * 100 << "%"
	          << "\n";
    }
    std::cout << std::endl;
}
