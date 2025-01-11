/*
726. Number of Atoms


Description:

Given a string formula representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

    For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.

Two formulas are concatenated together to produce another formula.

    For example, "H2O2He3Mg4" is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula.

    For example, "(H2O2)" and "(H2O2)3" are formulas.

Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.

 

Example 1:

Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.

Example 2:

Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.

Example 3:

Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.

 

Constraints:

    1 <= formula.length <= 1000
    formula consists of English letters, digits, '(', and ')'.
    formula is always valid.
*/


class Solution {
public:
    void helper(std::map<std::string, uint> &_atom_counts, string &_formula)
    {
        size_t cur = 0;
        while (cur < _formula.size())
        {
            if (isupper(_formula[cur]))
            {
                std::string cur_atom;
                cur_atom += _formula[cur];
                cur++;
                if (cur < _formula.size() && islower(_formula[cur]))
                {
                    cur_atom += _formula[cur];
                    cur++;
                }
                std::string cur_digit;
                while (cur < _formula.size() && isdigit(_formula[cur]))
                {
                    cur_digit += _formula[cur];
                    cur++;
                }
                int cur_count = 1;
                if (cur_digit.size())
                {
                    cur_count = stoi(cur_digit);
                }
                _atom_counts[cur_atom] += cur_count;
            }
            else if (_formula[cur] == '(')
            {
                std::string cur_str;
                int count = 0;
                cur++;
                while (true)
                {
                    if (_formula[cur] == ')')
                    {
                        if (count)
                        {
                            cur_str += _formula[cur];
                            count--;
                            cur++;
                            continue;
                        }
                        cur++;
                        std::map<std::string, uint> cur_counts;
                        helper(cur_counts, cur_str);
                        std::string cur_digit;
                        while (cur < _formula.size() && isdigit(_formula[cur]))
                        {
                            cur_digit += _formula[cur];
                            cur++;
                        }
                        int cur_count = 1;
                        if (cur_digit.size())
                        {
                            cur_count = stoi(cur_digit);
                        }
                        for (std::map<std::string, uint>::iterator it = cur_counts.begin(); it != cur_counts.end(); it++)
                        {
                            _atom_counts[it->first] += it->second * cur_count;
                        }
                        break;
                    }
                    if (_formula[cur] == '(')
                    {
                        count++;
                    }
                    cur_str += _formula[cur];
                    cur++;
                }
            }
            else
            {
                throw "YUYU";
            }
        }
    }
    string countOfAtoms(string formula) {
        std::map<std::string, uint> atom_counts;
        helper(atom_counts, formula);
        std::string out;
        for (std::map<std::string, uint>::iterator it = atom_counts.begin(); it != atom_counts.end(); it++)
        {
            out += it->first;
            if (it->second > 1)
            {
                out += std::to_string(it->second);
            }
        }
        return out;
    }
};
