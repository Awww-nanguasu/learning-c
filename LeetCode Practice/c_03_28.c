int isPalindrome(int x){
    long int r = 0;  //是回文数就返回1，不是返回0
    int y = x;
	if(x == 0) 
        return 1;
    if(x < 0 || x%10 == 0) 
        return 0;    
	else
	{
		while(x)
		{
			r = 10 * r + x % 10;
			x = x / 10;
		}
		if(r == y )
			return 1;
		else
			return 0;
    }
}
int main(){
    isPalindrome(121);
}