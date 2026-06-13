#include<iostream> 
using namespace std;
#define MAX 100

char tolower(char a)
{
    if(a>='A'&&a<='Z')
    {
        a=a+32;
        return a;
    }
    return a;
}
int main()
 {
    char s1[MAX], s2[MAX];
    int i, len1 = 0, len2 = 0;
    int isPalin = 1, isAnagram = 1;
    int freq[26] = {0};
   
    cout<<"Enter S1: ";
    cin>>s1;
    cout<<"Enter S2: ";
    cin>>s2;
    // Compute length of S1
    while (s1[len1] != '\0') 
        len1++;
    while (s2[len2] != '\0') 
        len2++;
    cout<<"Length of S1:"<<len1<<endl;
    
    // Palindrome check
    int left = 0, right = len1-1;  
    while (left < right) {
        if (tolower(s1[left]) != tolower(s1[right])) {
            isPalin = 0;
            break;
        }
        left++;
        right--;
    }
    if (isPalin)
        cout<<"S1 is a Palindrome"<<endl;
    else
        cout<<"S1 is NOT a Palindrome"<<endl;
      
    // Anagram check using frequency array
    for (i = 0; s1[i] != '\0'; i++)
        freq[tolower(s1[i]) - 'a']++;
    for (i = 0; s2[i] != '\0'; i++)
        freq[tolower(s2[i]) - 'a']++;  
    for (i = 0; i < 26; i++) {
        
        if((freq[i]%2) != 0 && freq[i]!=0) 
        { 
            isAnagram = 0; 
            break;
         }
         }
    if (isAnagram)
        cout<<"S1 and S2 are Anagrams"<<endl;
    else
        cout<<"S1 and S2 are NOT Anagrams"<<endl;
    return 0;
}
