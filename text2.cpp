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
	//10 you go to the office
	//11 you take a shower
	//12 you don't take a shower
	//13 you apologise to the president
	//14 you explain your day
	//15 you quit your job to the president
	//16 you run back home to shower
	//17 you go in all smelly
	//18 you clean up with the soap in the bathroom
	//19 you speed to the office
	//20 you quit over text

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
	},
	//9
	{
		"\nYou interupt your boss and tell him that you have decided\n"
		"not to work for him anymore. He ends the call.\n\n"
		"You have been fired\n"
		"GAMEOVER\n\n",
		0,
		{}
	},
	//10
	{
		"\nYour boss ends the call and you put your phone in your\n"
		"pocket. You need to get to the office as soon as possible.\n"
		"Do you take a shower?\n\n"
		"(1: yes, 2: no)\n\n",
		2,
		{11,12}
	},
	//11
	{
		"\nEven though you know your boss will be angrier, you rush\n"
		"to your bathroom and take possibly the fastest shower you\n"
		"have ever taken in only 2 minutes. You rush into your suit\n"
		"and tie and grab everything you think you need. Then you\n"
		"head to the office... When you arrive your boss rushes you\n"
		"into meeting room 2 and tells you everything you need to\n"
		"know for the meeting. It took you a moment to notice him,\n"
		"but at the end of the large oval table, where the boss\n"
		"normally sits, sat the president of the company! You weren't\n"
		"really listening when your boss was briefing you on what\n"
		"the meeting was about, so you ask one of your coworkers\n"
		"sitting next to you. He says that it is about productivity\n"
		"or something. Your heart stops. Then the president says,\n"
		"where have you been Joe? This is the sort of thing that\n"
		"caused me to bring this meeting to order, your unit is the\n"
		"least productive unit in the entire company! And that needs\n"
		"to change. So Joe, what do you have to say for yourself,\n"
		"being late for possibly the most important meeting you\n"
		"will ever attend with your work ethic?\n\n"
		"(1: apologise, 2: explain what happened, 3: quit job)\n\n",
		3,
		{13,14,15}
	},
	//12
	{
		"\nIn a rush you forgot to take a shower, and when you\n"
		"got to the office, you realize that you smell like the\n"
		"snacks you were eating last night. What do you do?!\n\n"
		"(1: run back home, 2: do nothing, 3: use the soap in the bathroom)\n\n",
		3,
		{16,17,18}
	},
	//13
	{},
	//14
	{},
	//15
	{},
	//16
	{
		"\nYou run back to your car and zoom back home.But\n"
		"when you were leaving again your boss sends you a\n"
		"text saying that you are fired if you don't get there\n"
		"that minute! What do you do?\n\n"
		"(1: speed to the office, 2: quit job)\n\n",
		2,
		{19,20}
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
