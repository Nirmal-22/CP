int Solution::solve(string A, string B) {
    
    if(B[B.length()-1]=='-') 
    // B[B.length()-1]='';
    B=B.substr(0,B.length()-1);
    if(B[0]=='-') 
    // B[0]='';
    B=B.substr(1,B.length()-1);
    
    replace(B.begin(), B.end(), '-', ' ');

    map<string, int> wordToNumber;
    wordToNumber["zero"] = 0;
    wordToNumber["one"] = 1;
    wordToNumber["two"] = 2;
    wordToNumber["three"] = 3;
    wordToNumber["four"] = 4;
    wordToNumber["five"] = 5;
    wordToNumber["six"] = 6;
    wordToNumber["seven"] = 7;
    wordToNumber["eight"] = 8;
    wordToNumber["nine"] = 9;
    wordToNumber["ten"] = 10;
    wordToNumber["eleven"] = 11;
    wordToNumber["twelve"] = 12;
    wordToNumber["thirteen"] = 13;
    wordToNumber["fourteen"] = 14;
    wordToNumber["fifteen"] = 15;
    wordToNumber["sixteen"] = 16;
    wordToNumber["seventeen"] = 17;
    wordToNumber["eighteen"] = 18;
    wordToNumber["nineteen"] = 19;
    wordToNumber["twenty"] = 20;
    wordToNumber["thirty"] = 30;
    wordToNumber["forty"] = 40;
    wordToNumber["fifty"] = 50;
    wordToNumber["sixty"] = 60;
    wordToNumber["seventy"] = 70;
    wordToNumber["eighty"] = 80;
    wordToNumber["ninety"] = 90;
    wordToNumber["hundred"] = 100;
    wordToNumber["thousand"] = 1000;
    // wordToNumber["million"] = 1000000;
    wordToNumber["lakh"] = 100000;
    wordToNumber["crore"]= 10000000;

    stringstream ss(B);
    string word;
    int result = 0;
    int currentNumber = 0;

    while (ss >> word) 
    {
        // if (word == "and") continue;

        if (wordToNumber.find(word) != wordToNumber.end()) 
        {
            int number = wordToNumber[word];
            if (number == 100) 
            {
                currentNumber *= number;
            } 
            else if (number >= 1000) 
            {
                result += currentNumber * number;
                currentNumber = 0;
            } 
            else 
            {
                currentNumber += number;
            }
        } 
    }

    result += currentNumber;
    // return result;
    
    if (result == stoi(A)) return 1;
    else  return 0;
}
