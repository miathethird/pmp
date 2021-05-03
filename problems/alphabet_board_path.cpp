#include <iostream>

std::string pathToLetter(char src, char dest)
{
    std::string res;

    int src_row = ((src-'a') / 5);
    int src_col = (src-'a') % 5;
    int dest_row = ((dest-'a') / 5);
    int dest_col =  (dest-'a') % 5;

    if(src == 'z')
    {
        res+='U';
        src_row--;
    }

    while(src_row != dest_row)
    {
        if(src_row>dest_row)
        {
            res+='U';
            src_row--;
        }
        else
        {
            res+='D';
            dest_row--;
        }
    }
    while(src_col != dest_col)
    {
        if(src_col>dest_col)
        {
            res+='L';
            src_col--;
        }
        else
        {
            res+='R';
            dest_col--;
        }
    }
    return res+='!';
}

std::string alphabetBoardPath(std::string target)
{
    std::string res;

    res+=pathToLetter('a', target[0]);

    for(int i=1; i<target.length(); i++)
    {
        res+=pathToLetter(target[i-1],target[i]);
    }

    return res;
}

int main()
{
    std::cout << alphabetBoardPath("leetcode");
    return 0;
}