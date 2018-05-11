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

// Walkthrough:
// get through the first day without trying to get fired
// make deal with demon
// do other things

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
//~	//25 go home smelly (leads to 32)
	//26 try to rub soap off jacket
	//27 hope boss won't notice soap on jacket
	//28 pull over for cops
	//29 gun it from cops
	//30 continue talk with president
//~	//31 tell president to kiss your ass (argue) (leads to 32)
//~~	//32 Go home hopelessly
	//33 go to the bar 
//~	//34 go home with soap stain (leads to 32)
	//35 use soap in office bathroom (alternate)
	//36 try to rub soap off jacket (alternate
	//37 hope boss won't notice soap on jacket (alternate)
//~	//38 give thug your money (leads to 32)
	//39 fight thug
	//40 Continue to work (alternate for 11)
	//41 argue about being fired by president
//~	//42 pack up your things
	
	// Home after bad day
	// 32 included here

	//43 take a nap and discover pendant
	//44 look at what to eat
	//45 drink milk
	//46 make omlet
	//47 eat sandwich
	//48 eat pizza
	//49 trust demon
	//50 don't trust demon 1
	//51 shake demon's hand
	//52 don't trust demon 2
	
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
		{16,17,35}
	},
	//13
	{
		"\nYou say sorry and you should have gotten here sooner.\n"
		"He says Yes, you should have gotten here sooner, and I\n"
		"expect all of you to remember what we talked about now.\n\n"
		"Ok, meeting adjourned, all of you get back to work, everyone\n"
		"except you, Joe.\n\n"
		"(1: stay in the meeting room, 2: argue)\n\n",
		2,
		{21,22}
	},
	//14
	{
		"\nMe: Well it doesn't matter now, I am here, aren't I?\n"
		"President: Insubordination. I am on edge, and you just\n"
		"pushed me over. You are fired. No exeptions. Leave.\n\n"
		"(1: leave, 2: argue)\n\n",
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
		"GAMEOVER\n\n",
		0,
		{}
		
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
		"(1: use the soap from the office restroom to clean, 2: leave hopelessly)\n\n",
		2,
		{18,25}
	},
	//18
	{
		"\nYou rush into the office restroom, dodging your boss.\n"
		"You are in such a rush that your hands slip, and you smear\n"
		"soap on your jacket. What do you do!\n\n"
		"(1: try to rub it off, 2: hope he won't notice)\n\n",
		2,
		{26,27}
	},
	//19
	{
                "\nYou decide that keeping your job is more important than\n"
                "a traffic ticket, so you begin to speed to work, when you hear\n"
                "the iconic sirens with flashing lights behind you.\n\n"
                "(1: pull over, 2: gun it from the cops)\n\n",
                2,
                {28,29}
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
		"\nYou decide to play the smart card and stay to avoid more lashing.\n"
		"So Joe, do you know why I have asked you to stay to talk?\n\n"
		"(1: No, 2: argue)\n\n",
		2,
		{30,31}
        },
	//22
        {
		"\nYou leave the room with your middle finger pointed behind you, you\n"
		"assume you have been fired, and continue your day, jobless\n\n"
		"GAMEOVER\n\n",
		0,
		{}
        },
        //23
        {
		"\nYou walk out of the room somberly yet loathingly. Stupid president.\n\n"
		"GAMEOVER\n\n",
		0,
		{}
        },
        //24
        {
		"\nYou: All I did was try to say that casually, I shouldn't be fired\n"
		"for that! President: I do not care what you think you did, this is a\n"
		"place of business, not a backalley street, and I should expect you to\n"
		"act like it. Leave. Now.\n\n"
		"GAMEOVER\n\n",
		0,
		{}
        },
        //25
        {
		"\nWhatever, you think to yourself. If they need to be so picky, they\n"
		"should choose someone else to be picky towards. I don't need this job.\n"
		"Then you remember that you have rent to pay, and walk to your car full of\n"
		"sorrow...\n\n"
		"(1: go home, 2: go to the bar)\n\n",
		2,
		{32,33}
		
        },
        //26
        {
		"\nYou try to run the soap off your jacket, but it only smears it even\n"
		"more! He's bound to notice it now...\n\n"
		"(1: hope he won't notice, 2: go home)\n\n",
		2,
		{27,34}
        },
        //27
        {
		"\nYou run back out to your boss and ask, is this better? He says: Maybe\n"
		"a little bit, but what is the white stain on your jacket? I cannot let\n"
		"you in there looking like that. The people I chose for this meeting from\n"
                "this unit I chose specifically because I thought they could represent us\n"
                "well, looks like you have, sadly. Just leave, I will not let you in.\n\n"
                "(1: go home)\n\n",
                1,
                {34}
        },
        //28
        {
		"\nYou pull over onto the side of the road, and watch as the cops drive\n"
		"past you! *Phew*.\n\n"
		"(1: continue to work)\n\n",
		1,
		{40}
        },
	//29
	{
		"\nYou speed up even faster, and you see the cops behind you doing the\n"
		"same. Eventually, you reach your exit, to see it blocked off... so you\n"
		"continue down the highway, making sure to keep ahead of the cops, when\n"
		"you see more flashing lights up ahead! along with police and spike strips!\n"
		"You stop before you hit the spike strips, and you are imediatly surrounded\n"
		"by police officers. They take you out of your car, arrest you, and you\n"
		"go to jail...\n\n"
		"GAMEOVER\n\n",
		0,
		{}
	},
	//30
	{
		"\nYou: No sir, I do not. President: Well I'll tell you then. The previous\n"
		"meeting was about group productivity. I want to talk to you one on one\n"
		"though. This can't end well you think to yourself. You are the least\n"
		"productive employee in the company, and you are constantly getting into\n"
		"trouble with your coworkers. I am afraid I have to fire you.\n\n"
		"(1: go home 2: argue)\n\n",
		2,
		{25,41}
	},
	//31
	{
		"\nYes, I do believe you wanted to talk to me about kissing my ass? Am I\n"
		"corrrect? President: IF YOU DON'T LEAVE THIS BUILDING THIS INSTANT I WILL\n"
		"SUE YOU, YOU MORONIC SON OF A... he trailed off... I am not going to lose\n"
		"my professionalism over this. But I meant what I said. Leave now.\n\n"
		"(1: go home)\n\n",
		1,
		{32}
	},
	//32
	{
		"\nYou enter your car, and begin the sad drive home. When you get home, you\n"
		"feel tired, maybe you should take a nap...\n\n"
		"(1: take a nap 2: get something to eat)\n\n",
		2,
		{43,44}
	},
	//33
	{
		"\nYou leave the building, enter your car, and decide you will go to the\n"
		"local bar to lay off some steam. When you get there, though, you are stopped\n"
		"in the doorway by a thug, asking for your money with a knife to your throat!\n\n"
		"(1: give him your money 2: fight the thug)\n\n",
		2,
		{38,39}
	},
	//34
	{
		"\nYou exit the building slumped and sad...\n\n"
		"(1: enter your car)\n\n",
		1,
		{32}
	},
	//35
	{
		"\nYou rush into the office restroom, dodging your boss.\n"
                "You are in such a rush that your hands slip, and you smear\n"
                "soap on your jacket. What do you do!\n\n"
                "(1: try to rub it off, 2: hope he won't notice)\n\n",
                2,
		{36,37}
	},
	//36
	{
	        "\nYou try to run the soap off your jacket, but it only smears it even\n"
                "more! He's bound to notice it now...\n\n"
                "(1: hope he won't notice, 2: go home)\n\n",
                2,
		{37,34}
	},
	//37
	{
	        "\nYou run back out to your boss and ask, do I smell ok? He says: No, not\n"
                "really at all, but what is the white stain on your jacket? I cannot let\n"
                "you in there looking like that. The people I chose for this meeting from\n"
		"this unit I chose specifically because I thought they could represent us\n"
		"well, looks like you have, sadly. Just leave, I will not let you in.\n\n"
                "(1: go home)\n\n",
                1,
                {34}
	},
	//38
	{
		"\nYou give the thug your money and he runs away. You decide you are just\n"
		"going to go home...\n\n"
		"(1: go home)\n\n",
		1,
		{32}
	},
	//39
	{
		"\nYou act like you are pulling out your wallet, and punch the thug in the\n"
		"face! But he recovered quickly, and you couldn't do anything from that\n"
		"point on...\n\n"
		"GAMEOVER\n\n",
		0,
		{}
	},
	//40
	{
		"\nWhen you arrive, your boss rushes you\n"
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
	//41
	{
		"\nYou: Hey! I shouldn't be fired just because I am less productive,\n"
		"Please give me a second chance! President: My desision is final.\n"
		"Pack your things and leave.\n\n"
		"(1: go home)\n\n",
		1,
		{42}
	},
	//42
	{
		"\nYou go to your cubicle, pack your things in a box, and walk to your\n"
		"car...\n\n"
		"(1: go home 2: go to the bar)\n\n",
		2,
		{32,33}
	},
	//43
	{
		"\nYou fall back on your bed, banging your head on the headboard\n"
		"in the process, and pick up your pillow to adjust it, when you\n"
		"feel something cold ant metal under your pillow... You take it\n"
		"out from under your pillow, and it looks like... A necklace?\n"
		"An amulet? You aren't sure, but almost immediatly, you see a\n"
		"huge dark and red cloud forming at the edge of our bed, and\n"
		"a figure begins to slowly take shape from the cloud. once it is\n"
		"finished. It looks like... A demon!?! Demon: Hello Joe, nice to\n"
		"finally meet you. I am Hnikkarr. And yes, I am a demon. So now\n"
		"that we have that sortened out, why don't we talk about that\n"
		"pendant of yours. You: HOLY SHIT A FXZKING DEMON DON'T KILL ME,\n"
		"PLEASE!!! Hnikkarr: HAHAHAHA! I don't want to kill you... I\n"
		"merely want to talk to you about that pendant in your hands\n"
		"right now...\n\n"
		"(1: Trust the demon 2: don't trust him!)\n\n",
		2,
		{49,50}
	},
	//44
	{
		"\nYou look in your refrigerator and see milk, eggs, a sandwich,\n"
		"and a slice of pizza.\n\n"
		"(1: drink milk 2: make omlet with eggs and milk 3: eat sandwich\n"
		"4: eat pizza)\n\n",
		4,
		{45,46,47,48}
	},
	//45
	{
		"\nYou take a big gulp of milk right out of the jug, asperate half\n"
		"of it, almost die, and decide that that is enough for you\n\n"
		"(1: take a nap)\n\n",
		1,
		{43}
	},
	//46
	{
		"\nYou take out the milk and eggs, and begin to make an omlet.\n"
		"First you drop all the eggshells in the mixture, add too much\n"
		"milk, making it runny. And then you burn it to a crisp trying to\n"
		"cook it. You have loast your appitite after that.\n\n"
		"(1: take a nap)\n\n",
		1,
		{43}
	},
	//47
	{
		"\nYou take out the sandwich, find that the previously hidden side\n"
		"is actually covered with stinky mold, and lose your appitite.\n\n"
		"(1: take a nap)\n\n",
		1,
		{43}
	},
	//48
	{
		"\nThe piece of pizza looks old, but you trust it, so you eat it\n"
		"Just minutes later, your stomach feels like it is doing a backflip,\n"
		"and you puke all over your couch. After a long messy clean up, you\n"
		"feel exhausted and tired at the same time\n\n"
		"(1: take a nap)\n\n",
		1,
		{43}
	},
	//49
	{
		"\nYou: Ok, fine. I trust you... For now... What do you want with me,\n"
		"and what is so special about this pendant... Hnikkarr: I don't care\n"
		"much about you... I just want that pendant. And to answer your\n"
		"second question, that is a pendant of bad luck. It curses anyone\n"
		"who sleeps near it for one night with horrible, disgusting luck for\n"
		"approximatly 13 hours. You: Why do you want it, and why was it under\n"
		"my pillow! Hnikkarr: Aren't you full of questions... I want it to\n"
		"give me more power, and my guess is someone or something put it\n"
		"underneath your pillow. You: Why would someone want to give me bad\n"
		"luck!? Hnikkarr: Beats me, could be any number of reasons. But I\n"
		"don't care why. Just give me the pendant. You: Ok, a couple more\n"
		"questions. Why do you want more power if you are already a demon?\n"
		"Hnikkarr: Us demons are always searching to be the strongest...\n"
		"That rare pendant would give me a huge surge of power. I would\n"
		"easily be the strongest demon if I had it. You: Ok, that makes\n"
		"sense. But why don't you just take the pendant from me? Hnikkarr:\n"
		"Demons can only harm another being if we are contracted to do so.\n"
		"You: Yes... I want to know who put this pendant under my pillow,\n"
		"ruining my life and costing me my job. And you desperatly want\n"
		"this pendant... If I made a deal with you, to give you the\n"
		"pendant in return for helping me kill the person that ruined my\n"
		"life... Hnikkarr: I am perfectly fine with helping you kill anyone\n"
		"you want. As long as I get that pendant. You: So it is a deal.\n\n"
		"(1: shake Hnikkarr's hand 2: do not trust him!!)\n\n",
		2,
		{51,52}
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
