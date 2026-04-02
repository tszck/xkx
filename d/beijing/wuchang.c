inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG
這是一個練武場，由巨大的花崗巖石板鋪就，豎立着幾個木人。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"kang2",
	]));
	set("objects",([
                "/d/shaolin/npc/mu-ren" : 4
	]));
	set("coor/x", -179);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
