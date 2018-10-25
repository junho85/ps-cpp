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
        unsigned long length = s.size();

        if (length == 0) {
            return "";
        }

        string palindrome = s.substr(0, 1);

        for (int i=0; i < length - 1; i++) {
            // check from 2 pair
            if (i < length - 1 and s[i] == s[i+1]) {
                string tmp_palindrome = s.substr(i, 2);

                for (int j = 1; j < length; j++) {
                    // check range
                    if (i - j < 0 or i + 1 + j > length - 1) {
                        break;
                    }

                    // check palindrome
                    if (s[i - j] == s[i + 1 + j]) {
                        tmp_palindrome = s.substr(i - j, j * 2 + 2);
                    } else {
                        break;
                    }
                }
                if (tmp_palindrome.size() > palindrome.size()) {
                    palindrome = tmp_palindrome;
                }
            }

            // check 3
            if (i < length - 2 and s[i] == s[i+2]) {
                string tmp_palindrome = s.substr(i, 3);
                for (int j = 0; j < length; j++) {
                    // check range
                    if (i - j < 0 or i + 2 + j > length - 1) {
                        break;
                    }

                    // check palindrome
                    if (s[i - j] == s[i + 2 + j]) {
                        tmp_palindrome = s.substr(i - j, j * 2 + 3);
                    } else {
                        break;
                    }

                }
                if (tmp_palindrome.size() > palindrome.size()) {
                    palindrome = tmp_palindrome;
                }

            }
        }
        return palindrome;
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
    string result1 = solution.longestPalindrome("babad");
    assert(result1 == "bab" or result1 == "aba");
    
    assert(solution.longestPalindrome("cbbd") == "bb");
    assert(solution.longestPalindrome("a") == "a");
    assert(solution.longestPalindrome("ac") == "a");

    string result5 = solution.longestPalindrome("bb");
    assert(result5 == "bb");

    assert(solution.longestPalindrome("abcda") == "a");
    assert(solution.longestPalindrome("abqgjjgqab") == "qgjjgq");
    assert(solution.longestPalindrome("") == "");

    cout << "=====" << endl;
    string result8 = solution.longestPalindrome(
            "rgczcpratwyqxaszbuwwcadruayhasynuxnakpmsyhxzlnxmdtsqqlmwnbxvmgvllafrpmlfuqpbhjddmhmbcgmlyeypkfpreddyencsdmgxysctpubvgeedhurvizgqxclhpfrvxggrowaynrtuwvvvwnqlowdihtrdzjffrgoeqivnprdnpvfjuhycpfydjcpfcnkpyujljiesmuxhtizzvwhvpqylvcirwqsmpptyhcqybstsfgjadicwzycswwmpluvzqdvnhkcofptqrzgjqtbvbdxylrylinspncrkxclykccbwridpqckstxdjawvziucrswpsfmisqiozworibeycuarcidbljslwbalcemgymnsxfziattdylrulwrybzztoxhevsdnvvljfzzrgcmagshucoalfiuapgzpqgjjgqsmcvtdsvehewrvtkeqwgmatqdpwlayjcxcavjmgpdyklrjcqvxjqbjucfubgmgpkfdxznkhcejscymuildfnuxwmuklntnyycdcscioimenaeohgpbcpogyifcsatfxeslstkjclauqmywacizyapxlgtcchlxkvygzeucwalhvhbwkvbceqajstxzzppcxoanhyfkgwaelsfdeeviqogjpresnoacegfeejyychabkhszcokdxpaqrprwfdahjqkfptwpeykgumyemgkccynxuvbdpjlrbgqtcqulxodurugofuwzudnhgxdrbbxtrvdnlodyhsifvyspejenpdckevzqrexplpcqtwtxlimfrsjumiygqeemhihcxyngsemcolrnlyhqlbqbcestadoxtrdvcgucntjnfavylip");
    assert(result8 == "qgjjgq");

    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

    cout << "elapsed: " << duration << '\n';

    return 0;
}