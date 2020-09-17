class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a_r, a_i, b_r, b_i;
        sscanf(a.c_str(), "%d+%di", &a_r, &a_i);
        sscanf(b.c_str(), "%d+%di", &b_r, &b_i);
        int real = a_r * b_r - a_i * b_i;
        int imag = a_r * b_i + b_r * a_i;
        return to_string(real) + "+" + to_string(imag) + "i";
    }
};