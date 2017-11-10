# include <iostream>
# include <string>

using namespace std;

//////////////////////////////////////////////////////
// Welcome to the code for Text Adventure 2 in c++! //
//////////////////////////////////////////////////////

struct Page{
    string      text;           // the text displayed to the user when they're on this page

    int         options;        // the number of options available to the user.  If <= 0, then this indicates the user has no options beczuse they died / got a game over.

    int         nextpage[10];   // The next page to go to depending on which option the user selected.
};

const Page gamePages[] = {
	// Table of Contents
	//0 menu
	//1 tutorial
	//2 tutorial 2
	//3 game begin
	//4 you get out of bed
	//5 you stay in bed
	//6 you pick up the call
	//7 you get fired
	//8 you apologise to your boss
	//9 you quit your job

	//0
	{
		"\nWelcome to Text Adventure 2!\n\n"
		"(1: Begin, 2: Tutorial)\n\n",
		2,
		{3,1}
	},
	//1
	{
		"\nThis is the tutorial!\n"
		"If you gotten yourself here then you have probably got the\n"
		"basics down, but just in case, the parentheses under the text\n"
		"shows your options, you just type the number that coresponds\n"
		"to the option you want to choose, and press enter! try it now!\n\n"
		"(1: continue, 2:begin adventure)\n\n",
		2,
		{2,3}
	},
	//2
	{
		"\nGreat job! With your newfound skills you will be able to rid\n"
		"this world of evil! Do you wish to continue?\n\n"
		"(1: begin adventure!)\n\n",
		1,
		{3}
	},
	//3
	{
		"\nYou wake up... You hear a high pitched beeping and you feel\n"
		"tired. Do you get out of bed?\n\n"
		"(1: get out of bed, 2: fall back asleep)\n\n",
		2,
		{4,5}
	},
	//4
	{
		"\nYou are still a little bit tired, but you manage to press\n"
		"the button on your alarm clock and pull yourself out of bed.\n"
		"Suddenly, your phone, sitting on your bedside table starts\n"
		"making a loud noise signaling that you are receving a call.\n"
		"A quick glance at the phone screen lets you know that the\n"
		"call is coming from your work boss. Do you pick it up?\n\n"
		"(1: pick up the call, 2: decline the call, 3: let it go to voicemail)\n\n",
		3,
		{6,7,7}
	},
	//5
	{
		"\nYou press a button on your alarm clock making it stop\n"
		"beeping and begin to drift off... But it wasn't long before\n"
		"you are woken up again this time by your phone making a\n"
		"loud noise signalling that you are receving a call.\n"
                "A quick glance at the phone screen lets you know that the\n"
                "call is coming from your work boss. Do you pick it up?\n\n"
                "(1: pick up the call, 2: decline the call, 3: let it go to voicemail)\n\n",
		3,
		{6,7,7}
	},
	//6
	{
		"\nYou reach over to your phone and press the button to\n"
		"accept the call. Almost immediately you here your boss\n"
		"talking particularly loudly at you. YOU WERE SUPPOSED TO\n"
		"BE AT THE OFFICE 20 MINUTES AGO JOE. DO I NEED TO REMIND\n"
		"YOU EVERY TIME YOU NEED TO COME TO THE OFFICE?! NOT TO\n"
		"MENTION THAT THERE IS A MEETING TODAY AND YOU ARE ALREADY\n"
		"BLOODY LATE FOR IT!\n\n"
		"(1: apologise, 2:quit your job, 3:hang up)\n\n",
		3,
		{8,9,7}
	},
	//7
	{
		"\nThe next day you come to work, late as always, and your\n"
		"boss tells you to leave. You ask him why, and he responds\n"
		"with telling you he fired you yesterday...\n\n"
		"GAMEOVER\n\n",
		0,
		{}
	},
	//8
	{
		"\nYou wait for your boss to stop yelling and then tell him\n"
		"that you are deeply sorry and will make sure it won't happen\n"
		"again. IT HAD BETTER NOT HAPPEN AGAIN, I DON'T KNOW HOW I\n"
		"PUT UP WITH YOU. NOW GET DOWN TO THE OFFICE. NOW.\n\n"
		"(1: Yes sir (go to the office), 2: Quit your job)\n\n",
		2,
		{10,9}
	}
};

int doPage(int page)
{
    // Page logic is simple:  output the flavor text
    cout << gamePages[page].text;

    // If the user has no options, they got game over
    if(gamePages[page].options <= 0)        // no options
        return -1;                          // return -1 to indicate game over

    // otherwise, if they did not get game over, get their selection
    int selection;
    cin >> selection;

    // make sure their selection is valid
    while(  selection < 1 ||                    // invalid selections are less than 1
            selection > gamePages[page].options // or are greater than the number of available options
         )
    {
        cout << "That is an invalid selection.  Please try again.\n";
        cin >> selection;
    }

    // their selection is valid.... so return the next page number to go to
    return gamePages[page].nextpage[ selection-1 ];  // note we have to subtract 1 here
                                                    // because our selection ID starts at 1
                                                    // but array indexes start at 0
}

int main() {
    int currentPage =0;        // start at page 1

    while(currentPage >= 0)     // as long as they don't have game over...
    {
        //... do a page
        currentPage = doPage(currentPage);
    }

    return 0;
}
