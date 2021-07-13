#include <bits/stdc++.h>

/*

While playing an RPG game, you were assigned to complete one of the hardest quests in this game.
There are n monsters you'll need to defeat in this quest. Each monster i is described with two integer
numbers - power i and bonus i. To defeat this monster, you'll need at least power i experience points. If
you try fighting this monster without having enough experience points, you lose immediately. You will
also gain bonus i experience points if you defeat this monster. You can defeat monsters in any order.
The quest turned out to be very hard - you try to defeat the monsters but keep losing repeatedly. Your
friend told you that this quest is impossible to complete. Knowing that, you're interested, what is the
maximum possible number of monsters you can defeat? (Question difficulty level: Hardest)
Sample cases:
Input Output Output description
n-----> 2
exp----->123
power of 0th monster---->78
power of 1st monster---->130
bonus of 0th monster---->10
bonus of 1st monster---->0
o/p : monster we can kill----->2
Explanation : Initial experience level is 123 points.
              Defeat the first monster having power of 78 and bonus of 10.
              Experience level is now 123+10=133.
              Defeat the second monster.

*/

using namespace std;

int main()
{
    cout << "Enter number of monsters : " ;int n;cin >> n;
    vector<int> power(n,0),bonus(n,0);
    cout << "Enter initial Experience : ";int exp;cin >> exp;
    for(int i=0;i<n;i++)
    {
        cout << "Enter power of " << i << "th monster : ";cin >> power[i];
    }
    for(int i=0;i<n;i++)
    {
        cout << "Enter bonus of " << i << "th monster : ";cin >> bonus[i];
    }
    vector<bool> check(n,false);
    int c = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(power[j] <= exp && check[j] == false)
            {
                exp += bonus[j];
                c++;
                check[j] = true;
            }
        }
    }
    cout << "Monster we can kill is : " << c;
    return 0;
}
