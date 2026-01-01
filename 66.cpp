class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int index = digits.size();
        if (digits[digits.size() - 1] + 1 == 10) {
            carry = 1;
             digits[digits.size() - 1] = 0;
            index = digits.size() - 2;
        } else {
            digits[digits.size() - 1] += 1;
        }

        while (carry) {
            if (index == -1) {
                digits.insert(digits.begin(), 1);
                break;
            }
            if (digits[index] + carry == 10) {
                digits[index] = 0;
                index -= 1;
            } else {
                digits[index] += 1;
                break;
            }
        }
        return digits;
    }
};