

void inser(stack<int> &st, int temp){
    if(st.size()==0 || temp <= st.top()){
        st.push(temp);
        return;
    }
    int rem = st.top();
    st.pop();
    inser(st,temp);
    st.push(rem);
}

void solve(stack<int> &st){                                             // ------->> call solve with a non-sorted stack from int main <<<---------//
    if(st.size()==1)
        return;
    int temp = st.top();
    st.pop();
    solve(st);
    inser(st,temp);
}
