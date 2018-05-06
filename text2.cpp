# include <iostream>
# include <string>

using namespace std;

//////////////////////////////////////////////////////
// Welcome to the code for Text Adventure 2 in c++! //
//////////////////////////////////////////////////////
//                                                  //
// Script (main course of action):                  //
// You have a bad day no matter what you do for the //
// first day                                        //
//                                                  //
// you find a wierd pendant under your pillow when  //
// you get home and a demon explains it is a pendant//
// of bad luck.                                     //
//                                                  //
// you make a deal with the demon to destroy the    //
// person that ruined your chances                  //
//                                                  //
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

	// Bad day (//~ = end of day 1)

	//3 game begin
	//4 get out of bed
	//5 stay in bed
	//6 pick up the call
	//7 get fired
	//8 apologise to your boss
	//9 quit your job
	//10 go to the office
	//11 take a shower
	//12 don't take a shower
	//13 apologise to the president
	//14 brush off the president
	//15 quit your job to the president
	//16 run back home to shower
	//17 go in all smelly
	//18 clean up with the soap in the bathroom
	//19 speed to the office
	//20 quit over text
	//21 stay after the meeting
	//22 argue with the president
//~	//23 get fired for insubordination
	//24 argue against firing
//~	//25 go home humiliated
	//26 go home smelly

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
		"or something. Your heart stops. Then the president asks,\n"
		"where have you been Joe? This is the sort of thing that\n"
		"caused me to bring this meeting to order, your unit is the\n"
		"least productive unit in the entire company! And that needs\n"
		"to change. So Joe, what do you have to say for yourself,\n"
		"being late for possibly the most important meeting you\n"
		"will ever attend with your work ethic?\n\n"
		"(1: apologise, 2: brush it off, 3: quit job)\n\n",
		3,
		{13,14,15}
	},
	//12
	{
		"\nIn a rush you forgot to take a shower, and when you\n"
		"got to the office, you realize that you smell like the\n"
		"snacks you were eating last night. What do you do?!\n\n"
		"(1: run back home, 2: do nothing, 3: use the soap in the office bathroom)\n\n",
		3,
		{16,17,18}
	},
	//13
	{
		"\nYou say sorry and you should have gotten here sooner.\n"
		"He says Yes, you should have gotten here sooner, and I\n"
		"expect all of you to remember what we talked about now.\n\n"
		"Ok, meeting adjourned, all of you get back to work, everyone\n"
		"except you, Joe.\n\n"
		"{1: stay in the meeting room, 2: argue}\n\n",
		2,
		{21,22}
	},
	//14
	{
		"\nMe: Well it doesn't matter now, I am here, aren't I?\n"
		"President: Insubordination. I am on edge, and you just\n"
		"pushed me over. You are fired. No exeptions. Leave.\n\n"
		"{1: leave, 2: argue}\n\n",
		2,
		{23,24}
	},
	//15
	{
		"\nMe: Why are people always picking on me?! do I have a\n"
		"target on my back? You know what, I quit this clown act.\n"
		"President: With your childish aditude I am sure you won't\n"
		"be missed. I didn't get a degree in elementary education.\n"
		"Your coworkers laugh as you storm out of the room\n\n"
		"{1: go home}\n\n",
		1,
		{25}
		
	},
	//16
	{
		"\nYou run back to your car and zoom back home.But\n"
		"when you were leaving again your boss sends you a\n"
		"text saying that you are fired if you don't get there\n"
		"that minute! What do you do?\n\n"
		"(1: speed to the office, 2: quit job)\n\n",
		2,
		{19,20}
	},
	//17
	{
		"\nYou walk into the office building, your boss begins\n"
		"to move you to the meeting room, but stops and takes a\n"
		"deep breath through his nose, stopping halfway and almost\n"
		"choking on his breath. Boss: You smell horrible! Jesus,\n"
		"I am not going to let you in that room with the president\n"
		"of the company smelling like that, consider yourself done.\n"
		"The president of the company! Holy makerel, I need to do\n"
		"something! And fast!\n\n"
		"{1: use the soap from the office restroom to clean, 2: leave hopelessly}\n\n",
		2,
		{18,26}
	},
	//18
	{
		"\nYou rush into the office restroom, dodging your boss.\n"
		"You are in such a rush that your hands slip, and you smear\n"
		"soap on your jacket. What do you do!\n\n"
		"{1: try to rub it off, 2: hope he won't notice}\n\n",
		2,
		{27,28}
	},
	//19
	{
                "\nYou decide that keeping your job is more important than\n"
                "a traffic ticket, so you begin to speed to work, when you hear\n"
                "the iconic sirens with flashing lights behind you.\n\n"
                "{1: pull over, 2: run from the cops}\n\n",
                2,
                {29,30}
        },
        //20
        {
                "\nYou: Actually, I won't come to work. I don't want a job\n"
                "that puts me through so much stress on such short notice. I\n"
                "quit. Boss: Well by the looks of it, we didn't need you in the\n"
                "first place. And this meeting has been planned for over a week.\n\n"
                "GAMEOVER\n\n",
                0,
                {}
        },
	//21
        {

        },
	//22
        {

        },
        //23
        {

        },
        //24
        {

        },
        //25
        {

        },
        //26
        {

        },
        //27
        {

        },
        //28
        {

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
