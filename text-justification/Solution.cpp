// https://leetcode.com/problems/text-justification/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> text({""});

        int line = 0;

        for (const auto& w: words) {
            if (text[line].size() != 0) {
                if (text[line].size() + w.size() + 1 > maxWidth) {
                    line++;
                    text.push_back("");
                } else {
                    text[line].append(" ");
                }
            }
            text[line].append(w);
        }

        for (auto it = text.begin(); it != text.end(); it++) {
            int spaces = count((*it).begin(), (*it).end(), ' ');
            if (spaces == 0 || it == text.end()-1) {
                it->append(maxWidth - (*it).size(), ' ');
                continue;
            }
            int space_left = maxWidth - (*it).size();
            int base = space_left / spaces;
            vector<int> space_buckets(spaces, 1+base);
            for (int i = 0; i < space_left % spaces; i++) {
                space_buckets[i]++;
            }
            string new_line = "";
            int p_l = 0;
            int i = 0;
            for (int p = (*it).find(" "); p != string::npos; p=(*it).find(" ", p+1)) {
                new_line.append((*it).begin() + p_l, (*it).begin() + p);
                new_line.append( string(space_buckets[i++], ' ') );
                p_l = p+1;
            }
            new_line.append((*it).begin() + p_l, (*it).end());
            *it = move(new_line);
        }

        return text;
    }
};