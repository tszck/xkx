// Room: /d/5lt/tianpindian.c

inherit ROOM;

void create()
{
	set("short", "甜品店");
	set("long", @LONG
這是一個賣食品的小鋪子，店裏面有好多好多喫的東西，簡直可以
用琳琅滿目來形容。加上老闆娘是村長的可心，臺長的妹妹，所以店裏
生意是村裏頭出了名的好!
LONG );
	set("exits", ([
		"north" : __DIR__"eroad1",
	]));
        set("objects", ([
		__DIR__"npc/blueeye": 1,
	]));
	set("no_fight", "1");
	set("coor/x", -140);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}