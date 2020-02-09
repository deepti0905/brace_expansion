class Solution {
    unordered_set<string> set_;
    vector<string> output;
public:
    void GetTokens(string str, vector<string> &tokens) {
    stringstream check1(str);
    string intermediate;

    // Tokenizing w.r.t. space ' '
    while (getline(check1, intermediate, ',')) {
      tokens.push_back(intermediate);
    }
  }
    
  void  RecursiveFunc(string str)
  {
    if(str.find("{") == string::npos && str.find(",") == string::npos)
    {
        if(set_.find(str) == set_.end())
        {
            set_.insert(str);
            output.push_back(str);
        }
        return;
    }       
    int rpos = str.find_first_of("}");
    int i=rpos;
    while(i>=0 && str[i] !='{' )i--;

    int lpos = i;

    vector<string> tokens;
    GetTokens(str.substr(lpos+1, rpos-lpos-1), tokens);
    string left = lpos > 0 ? str.substr(0,lpos): "";
    string right= rpos < str.size() -1 ? str.substr(rpos+1): "";
    for(auto a: tokens)
    {
        RecursiveFunc(left+ a+ right);
    }
      
  }

    vector<string> braceExpansionII(string expression) {
        if(expression.empty()) return output;
        RecursiveFunc(expression); 
        sort(output.begin(), output.end());
        return output;
    }
};
