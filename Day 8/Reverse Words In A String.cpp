string reverseString(string &str){
	stack<string>st;
	for(int i=0;i<str.size();i++){
		string word="";
		while(str[i]!=' ' && i<str.size()){
			word+=str[i];
			i++;
		}
		if(!word.empty()){
			st.push(word);
		}
	}
	string ans="";
	while(!st.empty()){
		ans+=st.top();
		ans.push_back(' ');
		st.pop();
	}
	return ans;
}