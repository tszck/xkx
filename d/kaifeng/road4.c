// /kaifeng/road4.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "州橋");
	set("long", @LONG
這座高高的橋如同彩虹初降人間，三十六道石階直通橋面橋下就是
水流奔湧的大運河。橋上人來如梭河中巨舟橫過。切然在橋下看去，人
行於高波之上，令人心顫不已。
LONG);
	set("exits", ([
		"southdown" : __DIR__"road3",
		"northdown" : __DIR__"road5",
	]));
	set("objects", ([
		__DIR__"npc/walker" : 1,
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
