#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <ctime>

using namespace std;

class Solution {
public:
    bool is_palindrome(string s) {
        unsigned long half_size = s.size()/2;

        string left = s.substr(0, half_size);
        string right = s.substr(half_size + (s.size()%2 == 1 ? 1 : 0));
        reverse(right.begin(), right.end());

        if (left == right) {
            return true;
        }
        return false;
    }

    set<string> get_substrings_by_size(string s, unsigned int size) {
        set<string> substrings;

        for (int i=0; i<s.size()-size+1; i++) {
            string substring = s.substr(i, size);
            substrings.insert(substring);
        }

        return substrings;
    }

    string longestPalindrome(string s) {
        // get substrings from longest
        for (unsigned long i=s.size(); i>=1; i--) {
            set<string> substrings = get_substrings_by_size(s, i);

            for (set<string>::iterator it = substrings.begin(); it != substrings.end(); ++it) {
                if (is_palindrome(*it)) {
                    return *it;
                }
            }
        }
        return "";
    }
};

int main() {
    Solution solution = Solution();

    // palindrome
    assert(solution.is_palindrome("bab") == true);
    assert(solution.is_palindrome("baab") == true);
    assert(solution.is_palindrome("abcba") == true);
    assert(solution.is_palindrome("abccba") == true);

    // not palindrome
    assert(solution.is_palindrome("abc") == false);
    assert(solution.is_palindrome("qwerty") == false);

    // get_substrings_by_size
    set<string> substrings = solution.get_substrings_by_size("abcdef", 3);

    clock_t start;
    double duration;

    start = clock();

    // longestPalindrome
    assert(solution.longestPalindrome("babad") == "bab" or solution.longestPalindrome("babad") == "aba");
    assert(solution.longestPalindrome("cbbd") == "bb");
    assert(solution.longestPalindrome("a") == "a");
    assert(solution.longestPalindrome("ac") == "a");
    assert(solution.longestPalindrome("bb") == "bb");
    assert(solution.longestPalindrome("abcda") == "a");
    cout << solution.longestPalindrome(
            "rgczcpratwyqxaszbuwwcadruayhasynuxnakpmsyhxzlnxmdtsqqlmwnbxvmgvllafrpmlfuqpbhjddmhmbcgmlyeypkfpreddyencsdmgxysctpubvgeedhurvizgqxclhpfrvxggrowaynrtuwvvvwnqlowdihtrdzjffrgoeqivnprdnpvfjuhycpfydjcpfcnkpyujljiesmuxhtizzvwhvpqylvcirwqsmpptyhcqybstsfgjadicwzycswwmpluvzqdvnhkcofptqrzgjqtbvbdxylrylinspncrkxclykccbwridpqckstxdjawvziucrswpsfmisqiozworibeycuarcidbljslwbalcemgymnsxfziattdylrulwrybzztoxhevsdnvvljfzzrgcmagshucoalfiuapgzpqgjjgqsmcvtdsvehewrvtkeqwgmatqdpwlayjcxcavjmgpdyklrjcqvxjqbjucfubgmgpkfdxznkhcejscymuildfnuxwmuklntnyycdcscioimenaeohgpbcpogyifcsatfxeslstkjclauqmywacizyapxlgtcchlxkvygzeucwalhvhbwkvbceqajstxzzppcxoanhyfkgwaelsfdeeviqogjpresnoacegfeejyychabkhszcokdxpaqrprwfdahjqkfptwpeykgumyemgkccynxuvbdpjlrbgqtcqulxodurugofuwzudnhgxdrbbxtrvdnlodyhsifvyspejenpdckevzqrexplpcqtwtxlimfrsjumiygqeemhihcxyngsemcolrnlyhqlbqbcestadoxtrdvcgucntjnfavylip")
         << endl;

    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

    cout << "elapsed: " << duration << '\n';

    return 0;
}