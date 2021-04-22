int sum_of_digits(int n){
    int sum=0;
    while(n>0){
    int m=n%10;
    sum=sum+m;
    n=n/10;
    }

    return sum;
}

int rev(int n){
    int rev=0;
    while (n != 0) {
        int remainder = n % 10;
        rev = rev * 10 + remainder;
        n /= 10;
    }

    return rev;
}


void palin(int n){
    if(rev(n)==n){
        printf("Yes");
    }
    else{
        printf("No");
    }

}
