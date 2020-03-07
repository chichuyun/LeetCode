struct pair_hash {
	template<typename T, typename U>
	size_t operator()(const pair<T, U> &x) const {
		return hash<T>()(x.first) ^ hash<U>()(x.second);
	}
};

class Solution {
private:
    unordered_set<pair<int,int>,pair_hash> nums; // +32 this is not necessary.
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty() || word.empty()) return false;
        if(board.size()*board[0].size()<word.size()) return false;
        int cols=board.size(), rows=board[0].size();

        for(int i=0;i<cols;++i) {
            for(int j=0;j<rows;++j) {
                if(helper(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, string &word, int i, int j, int k) {
        if(word[k]==board[i][j]) {
            pair<int,int> num=make_pair(i,j);
            if(nums.find(num)==nums.end()) {
                if(k==word.size()-1) return true;
                nums.insert(num);
                ++k;
                if(i-1>=0              && helper(board, word, i-1, j, k)) return true;
                if(i+1<board.size()    && helper(board, word, i+1, j, k)) return true;
                if(j-1>=0              && helper(board, word, i, j-1, k)) return true;
                if(j+1<board[0].size() && helper(board, word, i, j+1, k)) return true;
                nums.erase(num);
            }
        }
        return false;
    }
};