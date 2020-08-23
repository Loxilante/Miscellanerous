/*
	Made by Loxilante

	2020-08-24

	To test songs' bpm

	Version: 1.0
 */

#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <testlib.h>

int main(int argc, char ** argv)
{

	std::cout<<std::endl<<std::endl<<"Plz input the time(s)."<<std::endl;

	int period;
	std::cin>>period;
	double at = (double)60/period, bpm;

	std::cout<<std::endl<<std::endl;

	int cnt = 0;
	for(clock_t t_begin = clock(), t_doing = clock(); (double)(t_doing-t_begin)/CLOCKS_PER_SEC <= period; t_doing = clock())
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			while(GetAsyncKeyState(VK_SPACE) && (double)(clock()-t_begin)/CLOCKS_PER_SEC <= period);
			cnt++;
			bpm = (double)at*cnt;
			std::cout<<"Now the song's bpm is "<<bpm<<std::endl;
		}
	}

	std::cout<<std::endl<<"The song's final bpm is "<<bpm<<'.'<<std::endl<<std::endl;

	bool noguess = 0;
	char * songtype;

	if (bpm <= 40) songtype = "Larghissimo";
	else if (40 < bpm && bpm <= 60) songtype = "Lento";
	else if (60 < bpm && bpm <= 66) songtype = "Larghetto";
	else if (66 < bpm && bpm <= 76) songtype = "Adagio";
	else if (76 < bpm && bpm <= 92) songtype = "Andante";
	else if (92 < bpm && bpm <= 105) songtype = "Moderato";
	else if (105 < bpm && bpm <= 112) songtype = "Allegretto";
	else if (112 < bpm && bpm <= 120) songtype = "Allegro Moderato";
	else if (120 < bpm && bpm <= 168) songtype = "Allegro";
	else if (168 < bpm && bpm <= 200) songtype = "Presto";
	else if (200 < bpm && bpm <= 208) songtype = "Prestissimo";
	else if (208 < bpm && bpm <= 250) songtype = "Prestississimo";
	else
	{
		std::cout<<"oh, are you testing a song!"<<std::endl;
		noguess = 1;
	}

	if (!noguess)
	{
		char * prword[] = {"I guess you are listening a ", "Are you listening a ", "Emmm, a "};
		char * sufword[] = {".", ".", ", right?"};

		int choose = rnd.next(3);

		std::cout<<prword[choose]<<songtype<<sufword[choose]<<std::endl;
	}

	std::cout<<std::endl<<std::endl<<std::endl;

	Sleep(4000);

	return 0;
}
