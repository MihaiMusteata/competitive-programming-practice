class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        vector<int> record;

        for(int i = 0; i < operations.size(); i++) { 
            if(operations[i] == "C") {
                sum -= record.back();
                record.pop_back();
                continue;
            }
            
            if(operations[i] == "D") {
                record.push_back(record.back() * 2);
            } else if(operations[i] == "+") {
                record.push_back(record[record.size() - 1] + record[record.size() - 2]);
            } else {
                record.push_back(stoi(operations[i]));
            }
            
            sum += record.back();
        }

        return sum;
    }
};