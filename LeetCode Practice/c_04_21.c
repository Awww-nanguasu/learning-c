int lengthOfLastWord(char * s){
    int i=0,count=0;
    while(s[i]!='\0'){
        if(s[i]!=' '){
            count++;
        }
        if(s[i]==' ' && s[i+1]!=' ' && s[i+1]!='\0'){
            count=0;
        }
        i++;
    }
    return count;
}