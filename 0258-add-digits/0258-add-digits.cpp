class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
        return 0;

        return 1 + (num - 1) % 9;
        /*int j=0, k=0, l=0, i;
        while (num>=10){
            i= num%10;
            num= num/10;
            j=j+i;
        }
        j=j+num;
        if (j<10){
            return j;
        }
        else{
            while (j>=10){
            l= j%10;
            j= j/10;
            k=k+l;
            }
            k=k+j;
        } return k;*/
    }
};