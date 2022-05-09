//IRFAN ALI SADAB 2011054642
/*
My approach for this problem
1.At first I take the input using getline and demand an # for denoting the end of input as it's a composition and my program needs to know when to stop taking input
2.After taking the input I split the whole composition into multiple lines considering '\n' as the splitting criteria
3.While splitting the composition into lines using a while loop,I keep track of how many lines i've got using a counter and then store it in a global variable named 'linecount'
.In the while loop,I also store every line in a array of strings for finding the character frequency later

4.then I call a method called checkchar Inside which I run a loop until i have no more lines using 'linecount' variable
5.Inside the loop i save my current iteration's line in a temporary variable name 'str'
6.then i created a-z variables and initialized them with zero as they will work as my character counter
7.then I run another loop till the end of the current line,inside which I check the freuency of each character in the current line and print it
8.the loop continues this way showing character frequencies of every line this way


*/



#include <iostream>
#include <string>
//#include <vector>
#include <sstream>
#include<string.h>
using namespace std;
string temp[500];//declaring an array of strings globally to store the splitted lines and reduce hassle
int linecount;//declared the linecount as global variable to reduce hassle

void checkchar() //This method checks the frequency of characters in each line and prints them
{
    int ii;
    for (ii = 0;ii < linecount;ii++) {//using a loop to print frequency of each line till the end of lines.i have already saved how many lines are here in the main function while splitting the lines


        std::string str; //declaring another temporary string variable for easier operations
         // int n = 0;
        str = temp[ii]; //assigning the line of current iterationn in the temporary string variable
      //cout<<str<<"88888888888888888888888888"<<endl;


              // = "
       // strcpy(temp[1],str)
      //////////////try convert string to char array
      /*int lengti =temp[1].length();
      cout<<lengti;
      char char_array[lengti + 1];
      strcpy(char_array, temp[1].c_str());
      for (int i = 0; i < n; i++)
          {
              cout << char_array[i];
          }*/

          // temp[1] = str;
           //cout<<"111111111111111111111111111111111111111111111"<<str<<endl;
          // cout<<temp[0]<<endl;
           //char checkCharacter = 'a';
           /*char b = 'b';
              char c = 'c';
              char d = 'd';
              char e = 'e';
              char f = 'f';
              char g = 'g';
              char h = 'h';
              char i = 'i';
              char k = 'k';
              char l = 'l';
              char m='m';
              char n='n';
              char o='o';
              char ='d';
              char d='d'; */


              //declaring variables of characters to keep track of the frequency of them in a line and setting their values initially to zero
        int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
        f = 0;
        g = 0;
        h = 0;
        i = 0;
        j = 0;
        k = 0;
        l = 0;
        m = 0;
        n = 0;
        o = 0;
        p = 0;
        q = 0;
        r = 0;
        s = 0;
        t = 0;
        w = 0;
        v = 0;
        u = 0;
        x = 0;
        y = 0;
        z = 0;



        // int count = 0;
       //cout<<str.size()<<"3444444444444444444444444"<<endl;
        for (int in = 0; in < str.size(); in++)//runnig a loop till the end of the current line to find out the freuency of each character in this particular line
        {
            if (str[i] == 'a' || str[i] == 'A')
            {
                ++a;
            }

            else if (str[in] == 'b' || str[in] == 'B')
            {
                ++b;
            }
            else if (str[in] == 'c' || str[in] == 'C')
            {
                ++c;
            }
            else if (str[in] == 'd' || str[in] == 'D')
            {
                ++d;
            }
            else if (str[in] == 'e' || str[in] == 'E')
            {
                ++e;
            }
            else if (str[in] == 'f' || str[in] == 'F')
            {
                ++f;
            }
            else if (str[in] == 'g' || str[in] == 'G')
            {
                ++g;
            }
            else if (str[in] == 'h' || str[in] == 'H')
            {

                ++h;
            }
            else if (str[in] == 'i' || str[in] == 'I')
            {
                ++i;
            }
            else if (str[in] == 'j' || str[in] == 'J')
            {
                ++j;
            }
            else if (str[in] == 'k' || str[in] == 'K')
            {
                ++k;
            }
            else if (str[in] == 'l' || str[in] == 'L')
            {
                ++l;
            }
            else if (str[in] == 'm' || str[in] == 'M')
            {
                ++m;
            }
            else if (str[in] == 'n' || str[in] == 'N')
            {
                ++n;
            }

            else if (str[in] == 'o' || str[in] == 'O')
            {
                ++o;
            }
            else if (str[in] == 'p' || str[in] == 'P')
            {
                ++p;
            }

            else if (str[in] == 'q' || str[in] == 'Q')
            {
                ++q;
            }
            else if (str[in] == 'r' || str[i] == 'R')
            {
                ++r;
            }
            else if (str[in] == 's' || str[in] == 'S')
            {
                ++s;
            }
            else if (str[in] == 't' || str[in] == 'T')
            {
                ++t;
            }
            else if (str[in] == 'u' || str[in] == 'U')
            {
                ++u;
            }
            else if (str[in] == 'v' || str[in] == 'V')
            {
                ++v;
            }
            else if (str[in] == 'w' || str[in] == 'W')
            {
                ++w;
            }
            else if (str[in] == 'x' || str[in] == 'X')
            {
                ++x;
            }
            else if (str[in] == 'y' || str[in] == 'Y')
            {
                ++y;
            }
            else if (str[in] == 'z' || str[in] == 'Z')
            {
                ++z;
            }
            //cout<<"ddddddddddddddddddddddddddddddddddd"<<i;
        }
        cout << "SHOWING CHARACTER FREQUENCY FOR LINE NO:" << ii + 1 << " BELOW:" << endl;

        cout << "Number of " << "a" << " = " << a << endl;
        cout << "Number of " << "b" << " = " << b << endl;
        cout << "Number of " << "c" << " = " << c << endl;
        cout << "Number of " << "d" << " = " << d << endl;
        cout << "Number of " << "e" << " = " << e << endl;
        cout << "Number of " << "f" << " = " << f << endl;
        cout << "Number of " << "g" << " = " << g << endl;
        cout << "Number of " << "h" << " = " << h << endl;
        cout << "Number of " << "i" << " = " << i << endl;
        cout << "Number of " << "j" << " = " << j << endl;
        cout << "Number of " << "k" << " = " << k << endl;
        cout << "Number of " << "l" << " = " << l << endl;
        cout << "Number of " << "m" << " = " << m << endl;
        cout << "Number of " << "n" << " = " << n << endl;
        cout << "Number of " << "o" << " = " << o << endl;
        cout << "Number of " << "p" << " = " << p << endl;
        cout << "Number of " << "q" << " = " << q << endl;
        cout << "Number of " << "r" << " = " << r << endl;
        cout << "Number of " << "s" << " = " << s << endl;
        cout << "Number of " << "t" << " = " << t << endl;
        cout << "Number of " << "u" << " = " << u << endl;
        cout << "Number of " << "v" << " = " << v << endl;
        cout << "Number of " << "w" << " = " << w << endl;
        cout << "Number of " << "x" << " = " << x << endl;
        cout << "Number of " << "y" << " = " << y << endl;
        cout << "Number of " << "z" << " = " << z << endl;



    }
}





int main()
{
    string Stringinput;
    string temporary;

    cout << "Please Enter Your Input with an '#' character at the end" << endl;
    getline(cin, Stringinput, '#'); //so that the console reads until an special character arrives(# in this case )which denotes the end of the input
    stringstream Obj(Stringinput);		//Obj is an object of STringstream class.

    int i = 0;
    while (getline(Obj, temporary, '\n'))//using obj to read the string here nad using temporary to store the splitted part and finally and the the character to split by
    {

        temp[i] = temporary;//saving the splitted line in an array of strings for using later
      //  cout << temporary << endl;
     //   if(i==0)
        //  {cout<<"2222222222222222222222222"<<temp[0]<<endl;
       //   std:: string mol=temp[0];
        //  cout<<mol<<endl; }
          // prin t split string
        i++;
        // }
    }
    linecount = i;//keeping count of how many lines in total so that it helps in printing the frequency later
 // cout << i;
//  int j = 0;
 /* while (j <=linecount)
    {
      cout << temp[j] << endl;
      j++;
    }*/



    checkchar(); //calling the method to check the frequency of characters in each line
    return 0;

}